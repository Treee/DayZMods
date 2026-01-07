modded class PlayerBase
{
	// holds the players symbol selection from the gesture menu
	protected int m_IAT_TempSymbolSelection = -1;

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		switch(rpc_type)
		{
			// server side action context sync from menu option selection
			case IAT_SIMPLECARPENTRY_RPC.IAT_RPC_SC_RADIAL_MENU:
			{
				if (g_Game.IsDedicatedServer())
				{

					// read serially the value as an integer
					if (!ctx.Read(m_IAT_TempSymbolSelection))
						return;
				}
			}
			break;
		}
	}

	// expose the value to be retrieved from outside this class. let it be set via code in some cases
	int IAT_GetCarvedSymbolSelection()
	{
		return m_IAT_TempSymbolSelection;
	}
	void IAT_SetCarvedSymbolSelection(int newIndex)
	{
		m_IAT_TempSymbolSelection = newIndex;
	}
};