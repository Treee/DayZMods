modded class ChernarusMap
{
	// ItemMap is an engine class; attach script state to its supported script child.
	protected ref IAT_MA_Document m_IAT_MA_Document = new IAT_MA_Document;
	protected ref array<ref IAT_MA_Stroke> m_IAT_MA_View = new array<ref IAT_MA_Stroke>;
	protected int m_IAT_MA_ServerNextRequest;
	protected int m_IAT_MA_Token;
	protected int m_IAT_MA_RequestId;
	protected int m_IAT_MA_ClientRevision = -1;
	protected int m_IAT_MA_ClientPointCount;
	protected int m_IAT_MA_ViewGeneration;
	protected int m_IAT_MA_NextRequest;
	protected int m_IAT_MA_Deadline;
	protected int m_IAT_MA_Operation;
	protected bool m_IAT_MA_Waiting;
	protected bool m_IAT_MA_Ready;
	protected bool m_IAT_MA_Failed;
	protected string m_IAT_MA_Status;

	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		m_IAT_MA_Document.Save(ctx);
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (!super.OnStoreLoad(ctx, version))
			return false;
		return m_IAT_MA_Document.Load(ctx);
	}

	//! A fresh read on every open avoids a stale view after an item changes hands.
	void IAT_MA_Open()
	{
		m_IAT_MA_Token++;
		m_IAT_MA_Waiting = false;
		m_IAT_MA_Ready = false;
		m_IAT_MA_Failed = false;
		m_IAT_MA_ClientRevision = -1;
		m_IAT_MA_View.Clear();
		m_IAT_MA_ClientPointCount = 0;
		m_IAT_MA_ViewGeneration++;
		m_IAT_MA_NextRequest = g_Game.GetTime() + IAT_MA_Limits.CLIENT_INTERVAL_MS;
		m_IAT_MA_Status = "Loading annotations...";
	}

	void IAT_MA_Update()
	{
		int now = g_Game.GetTime();
		if (m_IAT_MA_Waiting && now > m_IAT_MA_Deadline)
		{
			m_IAT_MA_Waiting = false;
			m_IAT_MA_Ready = false;
			m_IAT_MA_Failed = true;
			m_IAT_MA_Status = "No response. Reload to check whether your edit was saved.";
		}
		if (!m_IAT_MA_Ready && !m_IAT_MA_Failed && !m_IAT_MA_Waiting && now >= m_IAT_MA_NextRequest)
			IAT_MA_SendRequest(IAT_MA_Operation.PAGE, null);
	}

	bool IAT_MA_CanEdit()
	{
		return m_IAT_MA_Ready && !m_IAT_MA_Waiting && g_Game.GetTime() >= m_IAT_MA_NextRequest;
	}

	bool IAT_MA_Submit(int operation, IAT_MA_Stroke stroke = null)
	{
		if (!IAT_MA_CanEdit())
			return false;
		if (operation < IAT_MA_Operation.ADD || operation > IAT_MA_Operation.CLEAR)
			return false;
		if (operation == IAT_MA_Operation.ADD && (!stroke || !stroke.IsValid()))
			return false;
		IAT_MA_SendRequest(operation, stroke);
		return true;
	}

	array<ref IAT_MA_Stroke> IAT_MA_GetView() { return m_IAT_MA_View; }
	int IAT_MA_GetGeneration() { return m_IAT_MA_ViewGeneration; }
	string IAT_MA_GetStatus() { return m_IAT_MA_Status; }

	protected void IAT_MA_WriteRequest(ParamsWriteContext ctx, int operation, IAT_MA_Stroke stroke)
	{
		ctx.Write(IAT_MA_Limits.VERSION);
		ctx.Write(m_IAT_MA_Token);
		ctx.Write(m_IAT_MA_RequestId);
		ctx.Write(operation);
		ctx.Write(m_IAT_MA_ClientRevision);
		ctx.Write(m_IAT_MA_View.Count());
		if (operation == IAT_MA_Operation.ADD)
			stroke.Write(ctx);
	}

	protected void IAT_MA_SendRequest(int operation, IAT_MA_Stroke stroke)
	{
		m_IAT_MA_RequestId++;
		m_IAT_MA_Operation = operation;
		m_IAT_MA_Waiting = true;
		m_IAT_MA_Deadline = g_Game.GetTime() + IAT_MA_Limits.TIMEOUT_MS;
		m_IAT_MA_NextRequest = g_Game.GetTime() + IAT_MA_Limits.CLIENT_INTERVAL_MS;
		if (operation != IAT_MA_Operation.PAGE)
			m_IAT_MA_Status = "Saving...";
		if (!g_Game.IsMultiplayer())
		{
			ScriptReadWriteContext localPacket = new ScriptReadWriteContext;
			IAT_MA_WriteRequest(localPacket.GetWriteContext(), operation, stroke);
			OnRPC(null, IAT_MA_Limits.RPC_REQUEST, localPacket.GetReadContext());
			return;
		}
		ScriptRPC rpc = new ScriptRPC;
		IAT_MA_WriteRequest(rpc, operation, stroke);
		rpc.Send(this, IAT_MA_Limits.RPC_REQUEST, true);
	}

	protected bool IAT_MA_IsHeldBySender(PlayerIdentity sender)
	{
		PlayerBase holder = PlayerBase.Cast(GetHierarchyRootPlayer());
		if (!holder || !holder.IsAlive() || holder.IsUnconscious() || holder.IsRestrained() || holder.GetItemInHands() != this)
			return false;
		if (!g_Game.IsMultiplayer())
			return holder == g_Game.GetPlayer();
		return sender && holder.GetIdentity() && holder.GetIdentity().GetId() == sender.GetId();
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		if (rpc_type == IAT_MA_Limits.RPC_REQUEST)
		{
			if (g_Game.IsServer() && IAT_MA_IsHeldBySender(sender))
				IAT_MA_ServerRequest(sender, ctx);
			return;
		}
		if (rpc_type == IAT_MA_Limits.RPC_REPLY)
		{
			if (!g_Game.IsServer() || !g_Game.IsMultiplayer())
				IAT_MA_ClientReply(ctx);
			return;
		}
		super.OnRPC(sender, rpc_type, ctx);
	}

	protected void IAT_MA_ServerRequest(PlayerIdentity sender, ParamsReadContext ctx)
	{
		int version, token, requestId, operation, revision, index;
		if (!ctx.Read(version) || !ctx.Read(token) || !ctx.Read(requestId) || !ctx.Read(operation) || !ctx.Read(revision) || !ctx.Read(index))
			return;
		if (version != IAT_MA_Limits.VERSION || operation < IAT_MA_Operation.PAGE || operation > IAT_MA_Operation.CLEAR)
			return;
		int now = g_Game.GetTime();
		if (now < m_IAT_MA_ServerNextRequest)
		{
			IAT_MA_Reply(sender, token, requestId, operation, IAT_MA_Result.BUSY, 0, 0);
			return;
		}
		m_IAT_MA_ServerNextRequest = now + IAT_MA_Limits.REQUEST_INTERVAL_MS;
		int worldSize = g_Game.GetWorld().GetWorldSize();
		if (!m_IAT_MA_Document.MatchesTerrain(g_Game.GetWorldName(), worldSize))
		{
			IAT_MA_Reply(sender, token, requestId, operation, IAT_MA_Result.WRONG_TERRAIN, 0, 0);
			return;
		}
		int count = m_IAT_MA_Document.GetStrokes().Count();
		if (operation == IAT_MA_Operation.PAGE)
		{
			int result = IAT_MA_Result.OK;
			if (revision != m_IAT_MA_Document.GetRevision() && !(revision == -1 && index == 0))
				result = IAT_MA_Result.STALE;
			if (index < 0 || index > count)
				result = IAT_MA_Result.INVALID;
			int pageCount;
			int pagePoints;
			if (result == IAT_MA_Result.OK)
			{
				while (pageCount < IAT_MA_Limits.PAGE_STROKES && index + pageCount < count)
				{
					int nextPoints = m_IAT_MA_Document.GetStrokes()[index + pageCount].Points.Count();
					if (pagePoints + nextPoints > IAT_MA_Limits.PAGE_POINTS)
						break;
					pagePoints += nextPoints;
					pageCount++;
				}
			}
			IAT_MA_Reply(sender, token, requestId, operation, result, index, pageCount);
			return;
		}
		IAT_MA_Stroke stroke;
		if (operation == IAT_MA_Operation.ADD)
		{
			stroke = new IAT_MA_Stroke;
			if (!stroke.Read(ctx))
			{
				IAT_MA_Reply(sender, token, requestId, operation, IAT_MA_Result.INVALID, 0, 0);
				return;
			}
		}
		int editResult = m_IAT_MA_Document.Apply(operation, revision, stroke, g_Game.GetWorldName(), worldSize);
		int replyIndex;
		int replyCount;
		if (editResult == IAT_MA_Result.OK && operation == IAT_MA_Operation.ADD)
		{
			replyIndex = count;
			replyCount = 1;
		}
		IAT_MA_Reply(sender, token, requestId, operation, editResult, replyIndex, replyCount);
	}

	protected void IAT_MA_WriteReply(ParamsWriteContext ctx, int token, int requestId, int operation, int result, int index, int count)
	{
		ctx.Write(IAT_MA_Limits.VERSION);
		ctx.Write(token);
		ctx.Write(requestId);
		ctx.Write(operation);
		ctx.Write(result);
		ctx.Write(m_IAT_MA_Document.GetRevision());
		ctx.Write(m_IAT_MA_Document.GetStrokes().Count());
		ctx.Write(index);
		ctx.Write(count);
		for (int i = index; i < index + count; i++)
			m_IAT_MA_Document.GetStrokes()[i].Write(ctx);
	}

	protected void IAT_MA_Reply(PlayerIdentity recipient, int token, int requestId, int operation, int result, int index, int count)
	{
		if (!g_Game.IsMultiplayer())
		{
			ScriptReadWriteContext localPacket = new ScriptReadWriteContext;
			IAT_MA_WriteReply(localPacket.GetWriteContext(), token, requestId, operation, result, index, count);
			OnRPC(null, IAT_MA_Limits.RPC_REPLY, localPacket.GetReadContext());
			return;
		}
		// Never broadcast a map's contents to clients who have not opened it.
		if (!recipient)
			return;
		ScriptRPC rpc = new ScriptRPC;
		IAT_MA_WriteReply(rpc, token, requestId, operation, result, index, count);
		rpc.Send(this, IAT_MA_Limits.RPC_REPLY, true, recipient);
	}

	protected void IAT_MA_ClientReply(ParamsReadContext ctx)
	{
		int version, token, requestId, operation, result, revision, total, index, count;
		if (!ctx.Read(version) || !ctx.Read(token) || !ctx.Read(requestId) || !ctx.Read(operation) || !ctx.Read(result) || !ctx.Read(revision) || !ctx.Read(total) || !ctx.Read(index) || !ctx.Read(count))
			return;
		if (version != IAT_MA_Limits.VERSION || token != m_IAT_MA_Token || requestId != m_IAT_MA_RequestId || !m_IAT_MA_Waiting || operation != m_IAT_MA_Operation)
			return;
		if (total < 0 || total > IAT_MA_Limits.MAX_STROKES || count < 0 || count > IAT_MA_Limits.PAGE_STROKES || index < 0 || index > total || count > total - index)
			return;
		m_IAT_MA_Waiting = false;
		m_IAT_MA_NextRequest = g_Game.GetTime() + IAT_MA_Limits.CLIENT_INTERVAL_MS;
		if (result != IAT_MA_Result.OK)
		{
			m_IAT_MA_Status = IAT_MA_Limits.ResultText(result);
			if (result == IAT_MA_Result.STALE)
			{
				IAT_MA_Open();
				m_IAT_MA_Status = IAT_MA_Limits.ResultText(result);
			}
			else if (result != IAT_MA_Result.BUSY && operation == IAT_MA_Operation.PAGE)
				m_IAT_MA_Failed = true;
			return;
		}
		ref array<ref IAT_MA_Stroke> received = new array<ref IAT_MA_Stroke>;
		int receivedPoints;
		for (int i = 0; i < count; i++)
		{
			IAT_MA_Stroke stroke = new IAT_MA_Stroke;
			if (!stroke.Read(ctx))
			{
				IAT_MA_Open();
				return;
			}
			receivedPoints += stroke.Points.Count();
			if (receivedPoints > IAT_MA_Limits.PAGE_POINTS || m_IAT_MA_ClientPointCount + receivedPoints > IAT_MA_Limits.MAX_MAP_POINTS)
			{
				IAT_MA_Open();
				return;
			}
			received.Insert(stroke);
		}
		if (operation == IAT_MA_Operation.PAGE || operation == IAT_MA_Operation.ADD)
		{
			if (index != m_IAT_MA_View.Count() || (operation == IAT_MA_Operation.ADD && (count != 1 || revision != m_IAT_MA_ClientRevision + 1)) || (operation == IAT_MA_Operation.PAGE && m_IAT_MA_ClientRevision != -1 && revision != m_IAT_MA_ClientRevision))
			{
				IAT_MA_Open();
				return;
			}
			foreach (IAT_MA_Stroke entry : received)
				m_IAT_MA_View.Insert(entry);
			m_IAT_MA_ClientPointCount += receivedPoints;
		}
		else if (operation == IAT_MA_Operation.UNDO && m_IAT_MA_View.Count() > 0)
		{
			m_IAT_MA_ClientPointCount -= m_IAT_MA_View[m_IAT_MA_View.Count() - 1].Points.Count();
			m_IAT_MA_View.Remove(m_IAT_MA_View.Count() - 1);
		}
		else if (operation == IAT_MA_Operation.CLEAR)
		{
			m_IAT_MA_View.Clear();
			m_IAT_MA_ClientPointCount = 0;
		}
		m_IAT_MA_ClientRevision = revision;
		m_IAT_MA_Ready = m_IAT_MA_View.Count() == total;
		m_IAT_MA_ViewGeneration++;
		if (m_IAT_MA_Ready)
			m_IAT_MA_Status = string.Format("Saved: %1 / %2 strokes, %3 / %4 points", total, IAT_MA_Limits.MAX_STROKES, m_IAT_MA_ClientPointCount, IAT_MA_Limits.MAX_MAP_POINTS);
		else
			m_IAT_MA_Status = string.Format("Loading annotations: %1 / %2", m_IAT_MA_View.Count(), total);
	}
}
