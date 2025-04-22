modded class PlayerBase
{
	protected int m_IAT_RadioRangeCategory; // represents the km level selection. not terribly important
	protected int m_IAT_RadioRangeSelection; // represents the desired range of the radio.

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		switch(rpc_type)
		{
			// server is sending copy of config to client (not authority, just for action checking)
			case IAT_DYNAMICRADIO_RPC.CHECK_DYNAMICRADIO_CONFIG:
			{
				Param1<IAT_DynamicRadioConfig> configParams;
				// read the params, short circuit if there is an error
				if(!ctx.Read(configParams))
					return;

				// set client local copy of the config
				GetDayZGame().SetIATDynamicRadioConfig(configParams.param1);
				break;
			}
			// server side action context sync from menu option selection
			case IAT_DYNAMICRADIO_RPC.IAT_RPC_DR_RADIAL_MENU:
			{
				if (GetGame().IsDedicatedServer())
				{
					// read serially the value as an integer
					if (!ctx.Read(m_IAT_RadioRangeCategory))
						return;

					if (!ctx.Read(m_IAT_RadioRangeSelection))
						return;
				}
			}
			break;
		}
	}

	string IAT_GetRadioClassNameFromRange()
	{
		if (IAT_GetRadioRangeSelection() > -1)
		{
			PersonalRadio radio;
			if (Class.CastTo(radio, GetItemInHands()))
			{
				// translate into thousands. 0 index leaves first set of number 50-1000
				int bigRange = (m_IAT_RadioRangeCategory * 1000);
				int littleRange = (m_IAT_RadioRangeSelection * 50) + 50;
				if (bigRange > 4999)
					littleRange = (m_IAT_RadioRangeSelection * 100) + 100;

				int combinedNumber = bigRange + littleRange;
				return string.Format("IAT_PersonalRadio_%1", combinedNumber);
			}
		}
		return "";
	}

	int IAT_GetRadioRangeCategory()
	{
		return m_IAT_RadioRangeCategory;
	}
	int IAT_GetRadioRangeSelection()
	{
		return m_IAT_RadioRangeSelection;
	}
};