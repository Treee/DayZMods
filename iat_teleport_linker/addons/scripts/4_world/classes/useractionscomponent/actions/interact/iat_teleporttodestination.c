class IAT_ActionTeleportToDestination: ActionInteractBase
{
	void IAT_ActionTeleportToDestination()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask 	= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text 			= "Teleport";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem 	= new CCINone();
		m_ConditionTarget 	= new CCTCursor();
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!target)
			return false;

		Object targetObject;
		if (Class.CastTo(targetObject, target.GetObject()))
		{
			IAT_TeleportLinkData linkData;
			// this ensures anchor teleport doesnt move
			if (Class.CastTo(linkData, GetDayZGame().IAT_IsValidTeleporter(targetObject.GetType(), targetObject.GetPosition())))
			{
				// does the teleporter require a special item in hands to use?
				if (linkData.HasTeleportItemRequirement())
				{
					// if this teleport has a timer to stay active without requiring an item in hands; short circuit
					if (linkData.HasTimerToStayOpen() && linkData.IsTeleportActive())
					{
						return true;
					}

					ItemBase inHandsItem;
					// if no item in hands; short circuit
					if (!Class.CastTo(inHandsItem, player.GetItemInHands()))
						return false;

					// if item in hand is destroyed by damage
					if (inHandsItem.IsDamageDestroyed())
						return false;

					// get the type of required item
					typename itemType = linkData.GetTeleportItemInHandsRequirementName().ToType();

					bool itemIsExactlyCorrect = linkData.IsHoldingCorrectTeleportItemRequirement(inHandsItem.GetType());
					bool itemIsInherited = (itemType && inHandsItem.IsInherited(itemType));
					// if item in hand is incorrect and not inheritted
					if (!itemIsExactlyCorrect && !itemIsInherited)
						return false;
					// if item in hand does not have enough hp to teleport
					if (!linkData.HasRequiredHealth(inHandsItem.GetHealthLevel()))
						return false;
					// player has all the right things
					return true;
				}
				else
				{
					// no item required, use the teleporter
					return true;
				}
			}
		}

		return false;
	}

	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);

		Object targetObject;
		if (Class.CastTo(targetObject, action_data.m_Target.GetObject()))
		{
			IAT_TeleportLinkData linkData;
			// link data is true
			if (Class.CastTo(linkData, GetDayZGame().IAT_IsValidTeleporter(targetObject.GetType(), targetObject.GetPosition())))
			{
				// does the teleporter require a special item in hands to use?
				if (linkData.HasTeleportItemRequirement())
				{
					ItemBase inHandsItem;
					// if no item in hands; short circuit
					if (Class.CastTo(inHandsItem, action_data.m_Player.GetItemInHands()))
					{
						// damage the required item
						inHandsItem.AddHealth(-linkData.GetTeleportItemDamagePerUse());
					}
				}
				// once the item has been consumed,
				// if the teleport has a timer to stay open
				if (linkData.HasTimerToStayOpen())
				{
					// set the teleport to active
					linkData.SetTeleportActive();
				}

				vector newPosition = linkData.GetTeleporterDestination();

				// if the teleport is an area thing
				if (linkData.HasTeleportRadius())
				{
					// get the players in a radius around the teleporter
					PlayerBase nearbyPlayer;
					array<Man> nearbyMans = new array<Man>;
					GetGame().GetPlayers(nearbyMans);
					foreach (Man nearbyMan : nearbyMans)
					{
						if (Class.CastTo(nearbyPlayer, nearbyMan))
						{
							// if the player is close enough
							if (linkData.GetTeleportRadius() > vector.Distance(linkData.GetPosition(), nearbyPlayer.GetPosition()))
							{
								// set all their positions to new position
								nearbyPlayer.IAT_SetPreviousLocation(nearbyPlayer.GetPosition());
								nearbyPlayer.SetPosition(newPosition);
							}
						}
					}
				}
				else
				{
					action_data.m_Player.IAT_SetPreviousLocation(action_data.m_Player.GetPosition());
					action_data.m_Player.SetPosition(newPosition);
				}
			}
		}
	}

	override void OnEndClient( ActionData action_data )
	{
		super.OnEndClient(action_data);

		action_data.m_Player.IAT_SetPreviousLocation(action_data.m_Player.GetPosition());

		Object targetObject;
		if (Class.CastTo(targetObject, action_data.m_Target.GetObject()))
		{
			IAT_TeleportLinkData linkData;
			// link data is true
			if (Class.CastTo(linkData, GetDayZGame().IAT_IsValidTeleporter(targetObject.GetType(), targetObject.GetPosition())))
			{
				if (linkData.HasTimerToStayOpen())
				{
					linkData.SetTeleportActive();
				}
			}
		}
	}

	override bool IsLockTargetOnUse()
	{
		return false;
	}
};