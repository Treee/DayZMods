#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_MA_DataTest : IAT_ScenarioCase
{
	protected int m_Variant;

	void IAT_MA_DataTest(string name, int variant)
	{
		m_Mod = "IAT_MapAnnotations";
		m_Suite = "AnnotationData";
		m_Name = name;
		m_Variant = variant;
	}

	override bool Execute()
	{
		if (m_Variant == 0)
			Geometry();
		else if (m_Variant == 1)
			Document();
		else if (m_Variant == 2)
			Capacity();
		else
			StorageAndPackets();
		return true;
	}

	protected IAT_MA_Stroke Stroke(int count = 2)
	{
		IAT_MA_Stroke stroke = new IAT_MA_Stroke;
		stroke.Color = 1;
		stroke.Width = 4;
		for (int i = 0; i < count; i++)
			stroke.Points.Insert(IAT_MA_Geometry.Pack(Vector(100 + i, 0, 200 + i), 15360));
		return stroke;
	}

	protected void Geometry()
	{
		ref array<vector> positions = { "0 0 0", "15360 0 15360", "12000 0 4000", "500 0 14000", "7680 0 7680" };
		foreach (vector position : positions)
		{
			int packed = IAT_MA_Geometry.Pack(position, 15360);
			vector restored = IAT_MA_Geometry.Unpack(packed, 15360);
			Check(vector.Distance(position, restored) < 0.18, "Packing preserves terrain position including signed high bits", position.ToString(), restored.ToString());
		}
		ref array<vector> route = new array<vector>;
		for (int i = 0; i < 512; i++)
		{
			int parity = i % 2;
			route.Insert(Vector(i * 5, 0, parity * 50));
		}
		IAT_MA_Stroke reduced = IAT_MA_Geometry.MakeStroke(route, 15360, 0.5, 0, 2);
		Check(reduced.IsValid(), "Complex route fits one bounded stroke", "true", reduced.IsValid().ToString());
		Check(reduced.Points[0] == IAT_MA_Geometry.Pack(route[0], 15360), "Simplification retains start", "true", "checked");
		Check(reduced.Points[reduced.Points.Count() - 1] == IAT_MA_Geometry.Pack(route[511], 15360), "Simplification retains end rather than truncating", "true", "checked");
		ref array<vector> loop = { "100 0 100", "200 0 100", "200 0 200", "100 0 200", "100 0 100" };
		IAT_MA_Stroke closed = IAT_MA_Geometry.MakeStroke(loop, 15360, 1, 1, 4);
		Check(closed.Points.Count() == 5, "Closed shape keeps its corners", "5", closed.Points.Count().ToString());
		vector start, end;
		bool crosses = IAT_MA_Geometry.ClipLine("-10 50 0", "110 50 0", 100, 100, start, end);
		Check(crosses && vector.Distance(start, "0 50 0") < 0.001 && vector.Distance(end, "100 50 0") < 0.001, "Line crossing viewport clips to both edges", "0..100", start.ToString() + end.ToString());
		Check(!IAT_MA_Geometry.ClipLine("-10 -5 0", "110 -5 0", 100, 100, start, end), "Offscreen line is rejected", "false", "checked");
	}

	protected void Document()
	{
		IAT_MA_Document first = new IAT_MA_Document;
		IAT_MA_Document second = new IAT_MA_Document;
		IAT_MA_Stroke stroke = Stroke();
		Check(first.Apply(IAT_MA_Operation.ADD, 0, stroke, "chernarusplus", 15360) == IAT_MA_Result.OK, "First edit accepted", "OK", "checked");
		stroke.Points[0] = 123;
		Check(first.GetStrokes()[0].Points[0] != 123, "Stored stroke owns its data", "independent", "checked");
		Check(second.GetStrokes().Count() == 0, "Another map stays blank", "0", second.GetStrokes().Count().ToString());
		Check(first.Apply(IAT_MA_Operation.ADD, 0, Stroke(), "chernarusplus", 15360) == IAT_MA_Result.STALE, "Duplicate or stale edit is rejected", "STALE", "checked");
		Check(first.GetStrokes().Count() == 1, "Rejected retry does not duplicate a stroke", "1", first.GetStrokes().Count().ToString());
		Check(first.Apply(IAT_MA_Operation.ADD, 1, Stroke(), "enoch", 12800) == IAT_MA_Result.WRONG_TERRAIN, "Coordinates cannot silently move to another terrain", "WRONG_TERRAIN", "checked");
		Check(first.Apply(IAT_MA_Operation.UNDO, 1, null, "chernarusplus", 15360) == IAT_MA_Result.OK && first.GetPointCount() == 0, "Undo removes the latest stroke and frees capacity", "empty", "checked");
		first.Apply(IAT_MA_Operation.ADD, 2, Stroke(), "chernarusplus", 15360);
		Check(first.Apply(IAT_MA_Operation.CLEAR, 3, null, "chernarusplus", 15360) == IAT_MA_Result.OK && first.GetStrokes().Count() == 0, "Clear commits an empty map", "empty", "checked");
	}

	protected void Capacity()
	{
		IAT_MA_Document document = new IAT_MA_Document;
		IAT_MA_Stroke large = Stroke(128);
		for (int i = 0; i < 64; i++)
			document.Apply(IAT_MA_Operation.ADD, document.GetRevision(), large, "chernarusplus", 15360);
		Check(document.GetPointCount() == 8192, "Map accepts exactly its point budget", "8192", document.GetPointCount().ToString());
		Check(document.Apply(IAT_MA_Operation.ADD, document.GetRevision(), Stroke(1), "chernarusplus", 15360) == IAT_MA_Result.FULL, "Point budget rejects another stroke", "FULL", "checked");
		IAT_MA_Document tiny = new IAT_MA_Document;
		for (int j = 0; j < 256; j++)
			tiny.Apply(IAT_MA_Operation.ADD, tiny.GetRevision(), Stroke(1), "chernarusplus", 15360);
		Check(tiny.GetStrokes().Count() == 256 && tiny.Apply(IAT_MA_Operation.ADD, tiny.GetRevision(), Stroke(1), "chernarusplus", 15360) == IAT_MA_Result.FULL, "Many dots respect the stroke budget", "256 then FULL", "checked");
	}

	protected void StorageAndPackets()
	{
		IAT_MA_Document original = new IAT_MA_Document;
		original.Apply(IAT_MA_Operation.ADD, 0, Stroke(), "chernarusplus", 15360);
		ScriptReadWriteContext buffer = new ScriptReadWriteContext;
		original.Save(buffer.GetWriteContext());
		buffer.GetWriteContext().Write(9876);
		IAT_MA_Document restored = new IAT_MA_Document;
		ParamsReadContext reader = buffer.GetReadContext();
		Check(restored.Load(reader), "Saved annotations load", "true", "checked");
		Check(restored.GetStrokes().Count() == 1 && restored.GetPointCount() == 2 && restored.GetStrokes()[0].Color == 1 && restored.GetStrokes()[0].Width == 4, "Storage preserves strokes and brush", "one red stroke, width four", "checked");
		int sentinel;
		reader.Read(sentinel);
		Check(sentinel == 9876, "Load consumes exactly its extension", "9876", sentinel.ToString());
		ScriptReadWriteContext oversized = new ScriptReadWriteContext;
		oversized.GetWriteContext().Write(0);
		oversized.GetWriteContext().Write(2);
		oversized.GetWriteContext().Write(1000000);
		IAT_MA_Stroke bad = new IAT_MA_Stroke;
		Check(!bad.Read(oversized.GetReadContext()) && bad.Points.Count() == 0, "Oversized network count rejected before points are allocated", "rejected", "checked");
		ScriptReadWriteContext truncated = new ScriptReadWriteContext;
		truncated.GetWriteContext().Write(0);
		truncated.GetWriteContext().Write(2);
		truncated.GetWriteContext().Write(2);
		truncated.GetWriteContext().Write(123);
		Check(!bad.Read(truncated.GetReadContext()), "Truncated stroke is rejected", "false", "checked");
		ScriptReadWriteContext empty = new ScriptReadWriteContext;
		IAT_MA_Document oldMap = new IAT_MA_Document;
		Check(oldMap.Load(empty.GetReadContext()) && oldMap.GetPointCount() == 0, "Pre-mod map has an optional absent extension", "empty", "checked");
		original.Apply(IAT_MA_Operation.CLEAR, original.GetRevision(), null, "chernarusplus", 15360);
		ScriptReadWriteContext cleared = new ScriptReadWriteContext;
		original.Save(cleared.GetWriteContext());
		Check(restored.Load(cleared.GetReadContext()) && restored.GetStrokes().Count() == 0, "Empty save replaces previous annotations", "empty", "checked");
	}
}

class IAT_MA_ItemTest : IAT_ScenarioCase
{
	protected ChernarusMap m_Map;
	protected ChernarusMap m_Restored;
	protected int m_Stage;
	protected int m_Next;

	void IAT_MA_ItemTest()
	{
		m_Mod = "IAT_MapAnnotations";
		m_Suite = "AnnotationItem";
		m_Name = "HeldMapProtocolAndItemStorage";
	}

	override bool Prepare()
	{
		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		if (!player)
			return false;
		if (!m_Map)
		{
			m_Map = ChernarusMap.Cast(player.GetHumanInventory().CreateInHands("ChernarusMap"));
			m_Restored = ChernarusMap.Cast(g_Game.CreateObjectEx("ChernarusMap", player.GetPosition() + "1 0 0", ECE_PLACE_ON_SURFACE));
			Check(m_Map && m_Restored, "Two physical map fixtures created", "true", "checked");
		}
		return true;
	}

	override bool Execute()
	{
		if (!m_Restored || (!m_Map && m_Stage < 3))
			return true;
		if (g_Game.GetTime() < m_Next)
			return false;
		if (m_Stage == 0)
		{
			m_Map.IAT_MA_Open();
			m_Restored.IAT_MA_Open();
		}
		else if (m_Stage == 1)
		{
			m_Map.IAT_MA_Update();
			m_Restored.IAT_MA_Update();
		}
		else if (m_Stage == 2)
		{
			Check(m_Map.IAT_MA_CanEdit(), "Held map completes request/reply codec", "true", "checked");
			Check(!m_Restored.IAT_MA_CanEdit(), "Map on ground cannot be read or edited through holder protocol", "false", "checked");
			IAT_MA_Stroke stroke = new IAT_MA_Stroke;
			stroke.Points.Insert(IAT_MA_Geometry.Pack("12000 0 4000", g_Game.GetWorld().GetWorldSize()));
			Check(m_Map.IAT_MA_Submit(IAT_MA_Operation.ADD, stroke), "Held map submits one bounded stroke", "true", "checked");
			Check(m_Map.IAT_MA_GetView().Count() == 1, "Acknowledgment updates client view", "1", m_Map.IAT_MA_GetView().Count().ToString());
			ScriptReadWriteContext saved = new ScriptReadWriteContext;
			m_Map.OnStoreSave(saved.GetWriteContext());
			Check(m_Restored.OnStoreLoad(saved.GetReadContext(), g_Game.SaveVersion()), "Real item persistence hooks accept annotated map", "true", "checked");
			g_Game.ObjectDelete(m_Map);
			m_Map = null;
		}
		else if (m_Stage == 3)
		{
			PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
			player.LocalTakeEntityToHands(m_Restored);
		}
		else if (m_Stage == 4)
			m_Restored.IAT_MA_Open();
		else if (m_Stage == 5)
			m_Restored.IAT_MA_Update();
		else if (m_Stage == 6)
		{
			Check(m_Restored.IAT_MA_GetView().Count() == 1, "Restored item serves persisted annotations through the holder protocol", "1", m_Restored.IAT_MA_GetView().Count().ToString());
			if (m_Restored.IAT_MA_GetView().Count() == 1)
			{
				vector restoredPoint = IAT_MA_Geometry.Unpack(m_Restored.IAT_MA_GetView()[0].Points[0], g_Game.GetWorld().GetWorldSize());
				Check(vector.Distance(restoredPoint, "12000 0 4000") < 0.18, "Persisted annotation retains its location", "12000 0 4000", restoredPoint.ToString());
			}
			return true;
		}
		m_Stage++;
		m_Next = g_Game.GetTime() + 250;
		return false;
	}

	override bool Cleanup()
	{
		if (m_Map)
			g_Game.ObjectDelete(m_Map);
		if (m_Restored)
			g_Game.ObjectDelete(m_Restored);
		m_Map = null;
		m_Restored = null;
		return true;
	}
}

class IAT_MA_LayoutTest : IAT_ScenarioCase
{
	protected Widget m_Root;

	void IAT_MA_LayoutTest()
	{
		m_Mod = "IAT_MapAnnotations";
		m_Suite = "AnnotationUI";
		m_Name = "PackedLayoutsAndMapProjection";
	}

	override bool Execute()
	{
		m_Root = g_Game.GetWorkspace().CreateWidgets("gui/layouts/day_z_map.layout");
		Check(m_Root != null, "Vanilla map layout loads", "true", "checked");
		if (!m_Root)
			return true;
		MapWidget mapWidget = MapWidget.Cast(m_Root.FindAnyWidget("Map"));
		if (!mapWidget)
		{
			Check(false, "Map widget exists", "true", "false");
			return true;
		}
		Widget overlay = g_Game.GetWorkspace().CreateWidgets("iat_map_annotations/scripts/ui/overlay.layout", mapWidget);
		Widget toolbar = g_Game.GetWorkspace().CreateWidgets("iat_map_annotations/scripts/ui/toolbar.layout", m_Root);
		Check(overlay && toolbar, "Packed annotation layouts load", "true", "checked");
		if (!overlay || !toolbar)
			return true;
		Check(CanvasWidget.Cast(overlay.FindAnyWidget("IAT_MA_Canvas")) != null, "Drawing canvas exists", "true", "checked");
		Check(overlay.FindAnyWidget("IAT_MA_Capture") != null && toolbar.FindAnyWidget("IAT_MA_Status") != null, "Input surface and status exist", "true", "checked");
		mapWidget.SetScale(0.2);
		mapWidget.SetMapPos("7600 0 7500");
		m_Root.Update();
		float x, y;
		overlay.GetScreenPos(x, y);
		vector anchor = mapWidget.MapToScreen(mapWidget.ScreenToMap(Vector(x, y, 0)));
		vector near = mapWidget.MapToScreen(mapWidget.ScreenToMap(Vector(x + 30, y + 40, 0))) - anchor;
		Check(Math.AbsFloat(near[0] - 30) < 1 && Math.AbsFloat(near[1] - 40) < 1, "Projection origin aligns mouse and canvas coordinates", "30 40", near.ToString());
		return true;
	}

	override bool Cleanup()
	{
		if (m_Root)
			m_Root.Unlink();
		m_Root = null;
		return true;
	}
}

modded class IAT_ScenarioRegistry
{
	void IAT_ScenarioRegistry()
	{
		m_Cases.Insert(new IAT_MA_DataTest("CoordinatePackingSimplificationAndClipping", 0));
		m_Cases.Insert(new IAT_MA_DataTest("MapIsolationRevisionAndErasing", 1));
		m_Cases.Insert(new IAT_MA_DataTest("AnnotationCapacityLimits", 2));
		m_Cases.Insert(new IAT_MA_DataTest("AnnotationStorageAndBoundedDecoding", 3));
		m_Cases.Insert(new IAT_MA_ItemTest);
		m_Cases.Insert(new IAT_MA_LayoutTest);
	}
}
#endif
#endif
