class IAT_BuildingStage_ColorBase extends BuildingSuper
{
	protected ref IAT_BuildingRequirements m_BuildingRequirements;
	protected bool m_HasFetchedBuildingRequirements = false;

	void IAT_BuildingStage_ColorBase()
	{
		ProcessInvulnerabilityCheck(GetInvulnerabilityTypeString());
	}

	// no doors/locks or other "building" functionality
	override bool IsBuilding()
	{
		return false;
	}
	override string GetInvulnerabilityTypeString()
	{
		return "disableBaseDamage";
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(IAT_ActionBuildStage);
	}

	//================================================== RPC'S
    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        switch (rpc_type)
        {
            case IAT_RPC_SIMPLEBUILDING.UPDATE_BUILDING_REQS: // client side request for requirements
				ServerRefreshBuildingRequirements(sender);
			break;
			case IAT_RPC_SIMPLEBUILDING.SEND_BUILDING_REQS: // client side request for requirements
				ClientRefreshBuildingRequirements(ctx);
			break;
		};
        super.OnRPC(sender, rpc_type, ctx);
    }
	void TryGetBuildingRequirements(PlayerIdentity invokingPlayer)
	{
		// client only
		if (!g_Game.IsDedicatedServer())
		{
			// if we have building requirements already
			if (m_BuildingRequirements)
			{
				return; // early return
			}
			if (m_HasFetchedBuildingRequirements)
			{
				return; // early return
			}
			// debouncer so we dont burst send rpcs due to network lag
			m_HasFetchedBuildingRequirements = true;
			// get the requirements from the server
			ScriptRPC rpc = new ScriptRPC();
			rpc.Send(this, IAT_RPC_SIMPLEBUILDING.UPDATE_BUILDING_REQS, true, invokingPlayer);
		}
	}
	void ServerRefreshBuildingRequirements(PlayerIdentity invokingPlayer)
	{
		if (g_Game.IsDedicatedServer())
		{
			if (!m_BuildingRequirements)
			{
				IAT_SimpleBuildingConfig buildingConfig;
				// if we have a config
				if (Class.CastTo(buildingConfig, GetDayZGame().GetIATSimpleBuildingConfig()))
				{
					// if we even have a config for this building
					if (buildingConfig.HasBuildingRequirements(GetType()))
					{
						// set the requirements from config
						m_BuildingRequirements = buildingConfig.GetBuildingRequirements(GetType());
					}
				}
			}
			// send the rpc
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(m_BuildingRequirements);
			rpc.Send(this, IAT_RPC_SIMPLEBUILDING.SEND_BUILDING_REQS, true, invokingPlayer);
		}
	}
	void ClientRefreshBuildingRequirements(ParamsReadContext ctx)
	{
		if (!ctx.Read(m_BuildingRequirements))
		{
			PrintFormat("[ServerRefreshBuildingRequirements] Unable to read building requirements; short circuit. Building Position: %1", GetPosition());
			return;
		}
		m_BuildingRequirements.PrettyPrint();
	}
	//================================================== HELPERS
	void CraftNextStage()
	{
		// guard against passing our last tier
		if (IsLastTier())
		{
			return;
		}

		// split our name into parts by the _ delimeter
		TStringArray parts = {};
		GetType().Split("_", parts);
		// we know the last part is the number
		string lastPart = parts.Get(parts.Count() - 1);

		string className = GetType();
		string tierReplaceString = string.Format("_%1", lastPart);
		int nextTierInt = lastPart.ToInt() + 1;
		string nextTierString = string.Format("_%1", nextTierInt);
		className.Replace(tierReplaceString, nextTierString);
		// get the position and orientation
		vector position = GetPosition();
		vector orientation = GetOrientation();

		// create the new stage
		IAT_BuildingStage_ColorBase nextStage;
		if (Class.CastTo(nextStage, g_Game.CreateObjectEx(className, position, ECE_SETUP|ECE_CREATEPHYSICS|ECE_KEEPHEIGHT)))
		{
			nextStage.SetOrientation(orientation);

			// consume materials nearby
			RemoveMaterialsInArea();
			// delete this stage
			DeleteSafe();
		}
	}
	float GetMaterialSearchRadius()
	{
		// predefine variables
		vector minMax[2];
        vector min, max;
		// if a collision box exists
        if (GetCollisionBox(minMax))
        {
            min = minMax[0];
            max = minMax[1];
        }
        else
        {
            return 5; // 5 meters default radius
        }
		float maxX = Math.Max(Math.AbsFloat(min[0]), Math.AbsFloat(max[0]));
		// float maxY = Math.Max(Math.AbsFloat(min[1]), Math.AbsFloat(max[1]));
		float maxZ = Math.Max(Math.AbsFloat(min[2]), Math.AbsFloat(max[2])); // magic number to give some slack between objects
		// pick the bigger of the 2 sides
		float maxSide = Math.Max(maxX, maxZ);
		// add a little extension
		maxSide += 3;
		return maxSide;
	}
	bool IsLastTier()
	{
		if (m_BuildingRequirements)
		{
			return m_BuildingRequirements.IsLastStage();
		}
		return false;
	}
	bool HasCorrectTool(string itemType)
	{
		if (m_BuildingRequirements)
		{
			return m_BuildingRequirements.HasAllowedTool(itemType);
		}
		return false;
	}
	bool HasMaterialsForNextStage(IAT_BuildingRequirements itemsOnGround)
	{
		if (m_BuildingRequirements)
		{
			if (m_BuildingRequirements.HasRequiredItemsAndQuantities(itemsOnGround))
			{
				return true;
			}
		}
		return false;
	}
	bool HasMaterialsInArea()
	{
		// get the objects around us on some interval and see if we can build
		vector from = GetPosition();
		vector to = GetPosition() + "0 0.5 0";
		vector contactPos, contactDir;
		float radius = GetMaterialSearchRadius();
		int contactComponent;
		EntityAI buildingMaterial;
		IAT_BuildingRequirements itemsOnGround = new IAT_BuildingRequirements();
		itemsOnGround.SetAllowedTools({});
		set<Object> hitObjects = new set<Object>;
		DayZPhysics.RaycastRV(from, to, contactPos, contactDir, contactComponent, hitObjects, NULL, this, false, false, ObjIntersectIFire, radius, CollisionFlags.ALLOBJECTS);
		foreach (Object hitObject : hitObjects)
		{
			// sanity checks for objects that will never be materials?
			if (hitObject.IsInherited(ManBase))
			{
				continue;
			}
			if (hitObject.IsInherited(ZombieBase))
			{
				continue;
			}
			if (hitObject.IsInherited(Transport))
			{
				continue;
			}
			if (Class.CastTo(buildingMaterial, hitObject))
			{
				// PrintFormat("found material: %1 quantity: %2", buildingMaterial.GetType(), buildingMaterial.GetQuantity());
				itemsOnGround.AddRequiredItem(new IAT_BuildingRequiredItems(buildingMaterial.GetType(), buildingMaterial.GetQuantity()));
			}
		}
		if (HasMaterialsForNextStage(itemsOnGround))
		{
			return true;
		}
		return false;
	}
	void RemoveMaterialsInArea()
	{
		// get the objects around us on some interval and see if we can build
		vector from = GetPosition();
		vector to = GetPosition() + "0 0.5 0";
		vector contactPos, contactDir;
		float radius = GetMaterialSearchRadius();
		int contactComponent;
		set<Object> hitObjects = new set<Object>;
		DayZPhysics.RaycastRV(from, to, contactPos, contactDir, contactComponent, hitObjects, NULL, this, false, false, ObjIntersectIFire, radius, CollisionFlags.ALLOBJECTS);

		// setup info about items to consume
		ItemBase buildingMaterial;
		array<ItemBase> buildingMaterials = {};
		array<ref IAT_BuildingRequiredItems> requiredItems = m_BuildingRequirements.GetRequiredItems();
		int amountToConsume = -1;

		foreach (Object hitObject : hitObjects)
		{
			// sanity checks for objects that will never be materials?
			if (hitObject.IsInherited(ManBase))
			{
				continue;
			}
			if (hitObject.IsInherited(ZombieBase))
			{
				continue;
			}
			if (hitObject.IsInherited(Transport))
			{
				continue;
			}
			if (Class.CastTo(buildingMaterial, hitObject))
			{
				buildingMaterials.Insert(buildingMaterial);
			}
		}

		int totalQuantityToConsume = -1;
		// check each required item against this found object
		foreach(IAT_BuildingRequiredItems requiredItem : requiredItems)
		{
			// set the total quantity needed to be consumed
			totalQuantityToConsume = requiredItem.GetRequiredQuantity();
			// foreach material that can be used
			foreach(ItemBase material : buildingMaterials)
			{
				// if the current item is a required item
				if (requiredItem.IsRequiredClassName(material.GetType()))
				{
					// if we have comsuned all that is needed
					if (totalQuantityToConsume < 1)
					{
						continue;
					}
					// get the smaller of the two so we consume all materials (ie, 2 groups of 5 = 10 total)
					amountToConsume = Math.Min(material.GetQuantityMax(), totalQuantityToConsume);
					// remove from the item (this should handle auto deletion?)
					material.AddQuantity(-amountToConsume);
					// decrement total needed by how much we just removed
					totalQuantityToConsume -= amountToConsume;
				}
			}
		}
	}
};