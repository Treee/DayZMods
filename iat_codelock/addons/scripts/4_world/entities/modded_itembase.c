modded class ItemBase
{
	protected ref IAT_CodelockRaidTool m_RaidToolProperties;
	protected bool m_HasRaidToolBeenInitialzied;
	// ==================================================== OVERRIDES
	override string GetDisplayName()
	{
		// get the display name from the super call
		string displayName = super.GetDisplayName();
		// if the current item has an inventory
		if (GetInventory())
		{
			// if the item has a codelock attached
			IAT_Codelock_Colorbase iat_codelock;
			if (Class.CastTo(iat_codelock, IAT_GetAttachedCodelock()))
			{
				// if the codelock is locked
				if (iat_codelock.IAT_IsLocked())
				{
					displayName = string.Format("(Locked) %1", displayName);
				}
				// if the codelock is not locked
				else
				{
					displayName = string.Format("(Unlocked) %1", displayName);
				}
			}
		}
		return displayName;
	}
	override void SetActions()
	{
		super.SetActions();

		// any hand held item can be a raid tool if configured correctly
		AddAction(IAT_ActionDestroyCodelock);
	}
	override bool CanDisplayCargo()
	{
		// cache call chain value for later use
		bool superBool = super.CanDisplayCargo();
		// if call chain says we can display, run our logic for codelocks
		if (superBool)
		{
			// if we have a config
			if (GetDayZGame().GetIATCodelockConfig())
			{
				// if we can attach a codelock to containers
				if (GetDayZGame().GetIATCodelockConfig().CanAttachCodelockToContainers())
				{
					// get the attached codelock on this item
					IAT_Codelock_Colorbase iat_codelock;
					if (Class.CastTo(iat_codelock, IAT_GetAttachedCodelock()))
					{
						// if the codelock is locked
						if (iat_codelock.IAT_IsLocked())
						{
							// if the player has access
							if (iat_codelock.HasAccess(GetGame().GetPlayer().GetIdentity()))
							{
								return true;
							}
							else
							{
								return false;
							}
						}
					}
				}
			}
		}
		return superBool;
	}
	// can only grab the codelock if it is unlocked
	override bool IsTakeable()
	{
		bool superBool = super.IsTakeable();
		// if we can take the item
		if (superBool)
		{
			// if our codelock is attached
			IAT_Codelock_Colorbase iat_codelock;
			if (Class.CastTo(iat_codelock, IAT_GetAttachedCodelock()))
			{
				// if the codelock is locked
				if (iat_codelock.IAT_IsLocked())
				{
					// if the player has access
					if (iat_codelock.HasAccess(GetGame().GetPlayer().GetIdentity()))
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
		return superBool;
	}

	// ==================================================== CUSTOM CODE
	void InitializeRaidItem()
	{
		// if we have a config
		if (GetDayZGame().GetIATCodelockConfig())
		{
			// if we have raid tools configured
			array<ref IAT_CodelockRaidTool> raidTools = GetDayZGame().GetIATCodelockConfig().GetRaidTools();
			// for each raid tool in the config
			foreach (IAT_CodelockRaidTool tool : raidTools)
			{
				// string matching exact item name
				if (tool.MatchesClassName(GetType()))
				{
					SetRaidToolProperties(tool);
					return;
				}
				// generic type matching for Colorbase
				else if (GetGame().IsKindOf(GetType(), tool.GetItemName()))
				{
					SetRaidToolProperties(tool);
					return;
				}
			}
		}
	}
	IAT_Codelock_Colorbase IAT_GetAttachedCodelock()
	{
		if (GetInventory())
		{
			// if the item has a codelock attached
			IAT_Codelock_Colorbase iat_codelock;
			if (Class.CastTo(iat_codelock, GetInventory().FindAttachmentByName("Att_CombinationLock")))
			{
				return iat_codelock;
			}
		}
		return null;
	}
	/*
	* This function is intended for modders to signal the AttachCodelock action
	* that this object is allowed to receive a codelock. Special cases like RAG cabins
	* or IAT_MoreDoors since these are not Fences but rather BuildingBase and ItemBase
	*/
	bool CanAttachCodelockToObject()
	{
		return false;
	}

	// ==================================================== SETTERS & GETTERS
	bool IAT_IsRaidItem()
	{
		// only check items in hand when needed
		if (!m_HasRaidToolBeenInitialzied)
		{
			InitializeRaidItem();
			m_HasRaidToolBeenInitialzied = true;
		}
		return m_RaidToolProperties != null;
	}
	void SetRaidToolProperties(IAT_CodelockRaidTool raidTool)
	{
		m_RaidToolProperties = raidTool;
	}
	IAT_CodelockRaidTool GetRaidToolProperties()
	{
		return m_RaidToolProperties;
	}
};