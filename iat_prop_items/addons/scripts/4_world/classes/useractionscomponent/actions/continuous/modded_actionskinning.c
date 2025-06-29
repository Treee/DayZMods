modded class ActionSkinning
{
	override void HandlePlayerBody(ActionData action_data)
	{
		PlayerBase body;
		if (Class.CastTo(body,action_data.m_Target.GetObject()))
		{
			//Remove splint if target is wearing one
			if (body.IsWearingSplint())
			{
				IAT_LegCastApplied_Colorbase attachment;
				if (Class.CastTo(attachment, body.GetItemOnSlot("Splint_Right")))
				{
					string castColor = action_data.m_MainItem.ConfigGetString("color");
					if (!castColor || castColor == "")
						castColor = "Basic";

					IAT_LegCast_Colorbase newItem;
					if (Class.CastTo(newItem, action_data.m_Player.SpawnEntityOnGroundOnCursorDir(string.Format("IAT_LegCast_%1", castColor), 0.5)))
					{
						MiscGameplayFunctions.TransferItemProperties(attachment, newItem);
						//Lower health level of splint after use
						if (newItem.GetHealthLevel() < 4)
						{
							int newDmgLevel = newItem.GetHealthLevel() + 1;
							float max = newItem.GetMaxHealth("", "");

							switch (newDmgLevel)
							{
								case GameConstants.STATE_BADLY_DAMAGED:
									newItem.SetHealth("", "", max * GameConstants.DAMAGE_BADLY_DAMAGED_VALUE);
									break;

								case GameConstants.STATE_DAMAGED:
									newItem.SetHealth("", "", max * GameConstants.DAMAGE_DAMAGED_VALUE);
									break;

								case GameConstants.STATE_WORN:
									newItem.SetHealth("", "", max * GameConstants.DAMAGE_WORN_VALUE);
									break;

								case GameConstants.STATE_RUINED:
									newItem.SetHealth("", "", max * GameConstants.DAMAGE_RUINED_VALUE);
									break;

								default:
									break;
							}
						}
					}

					attachment.Delete();
				}
			}
		}

		// do vanilla stuff
		super.HandlePlayerBody(action_data);
	}
};