// these are land_ based objects meant for map baking
class IAT_MiningSegment_Colorbase extends House
{
	string m_FormattedPersistentID;

	bool m_IsEntrace;
	bool m_IsExit;
	//=============================================== VANILLA OVERRIDES
	override bool IsInventoryVisible()
	{
		return false;
	}
	override bool IsHealthVisible()
	{
		return false;
	}
	override bool CanPutIntoHands( EntityAI parent )
	{
		return false;
	}
	override bool CanPutInCargo (EntityAI parent)
	{
		return false;
	}
	override bool IsTakeable()
	{
		return false;
	}
	override bool CanBeAutoDeleted()
	{
		return false;
	}
	//=============================================== CUSTOM CODE
	bool IsMineable()
	{
		return false;
	}
	bool IsEntrance()
	{
		IAT_MiningConfig miningConfig;
		if (GetDayZGame() && Class.CastTo(miningConfig, GetDayZGame().GetIATMiningConfig()))
		{
			miningConfig.IsSegmentEntrance(GetFormattedPersistentID());
		}
		return false;
	}
	bool IsExit()
	{
		IAT_MiningConfig miningConfig;
		if (GetDayZGame() && Class.CastTo(miningConfig, GetDayZGame().GetIATMiningConfig()))
		{
			miningConfig.IsSegmentExit(GetFormattedPersistentID());
		}
		return false;
	}
	bool CanMineComponent(string componentName)
	{
		return false;
	}
	string GetFormattedPersistentID()
	{
		if (!m_FormattedPersistentID)
		{
			int uuid[4];
			GetPersistentID(uuid[0], uuid[1], uuid[2], uuid[3]);
			m_FormattedPersistentID = UUIDApi.FormatString(uuid);
			PrintFormat("formatted persistent id for %1 - %2", GetType(), m_FormattedPersistentID);
		}
		return m_FormattedPersistentID;
	}
	string GetMiningYield(ItemBase itemInHands)
	{
		return "";
	}
	int GetMiningYieldQuantity(ItemBase itemInHands)
	{
		return Math.RandomIntInclusive(1, 5);
	}

	float GetDamageToMiningItemEachYield(ItemBase item)
	{
		return 0;
	}

	/* Defines the yield of the action*/
	void GetMaterialAndQuantityYieldMap(ItemBase item, out map<string,int> output_map) {}

	void IncrementComponentHitCounter(string componentName) {}

	vector GetTeleportDestination()
	{
		// get the mining config if exists
		IAT_MiningConfig miningConfig;
		if (GetDayZGame() && Class.CastTo(miningConfig, GetDayZGame().GetIATMiningConfig()))
		{
			// return the teleport destination for this segment
			return miningConfig.GetSegmentTeleportDestination(GetFormattedPersistentID());
		}
		// otherwise return the matural position of this object
		return GetPosition();
	}
};

class land_iat_miningsegment_entrance extends IAT_MiningSegment_Colorbase
{
	void CreateMiningExit(vector returnPosition, vector surfacePosition)
	{
		vector underground = surfacePosition + "0 100 0";

		land_iat_miningsegment_junction m_LinkedExit;
		// create a junction at the location underneath the action target
		if (Class.CastTo(m_LinkedExit, GetGame().CreateObjectEx("land_iat_miningsegment_junction", underground, ECE_SETUP|ECE_CREATEPHYSICS|ECE_KEEPHEIGHT)))
		{
			// get the position we should spawn the player.
			// if the memory point in the p3d doesnt exist, use a default
			vector teleportPosition;
			if (MemoryPointExists(GetPlayerSpawnMemoryPoint()))
			{
				teleportPosition = GetMemoryPointPos(GetPlayerSpawnMemoryPoint());
				teleportPosition = ModelToWorld(teleportPosition);
			}
			else
			{
				teleportPosition = underground;
			}

			// create entry in the mining config
			IAT_MiningConfig miningConfig;
			if (GetDayZGame() && Class.CastTo(miningConfig, GetDayZGame().GetIATMiningConfig()))
			{
				// entry for the entrance
				miningConfig.CreateSegmentEntranceNode(GetFormattedPersistentID(), returnPosition, teleportPosition);

				// no magic numbers
				int maxHits = 5
				bool isExit = true;
				// entry for the first junction
				miningConfig.CreateSegmentJunctionNode(m_LinkedExit.GetFormattedPersistentID(), teleportPosition, returnPosition, maxHits, isExit);
			}
		}
	}
	string GetPlayerSpawnMemoryPoint()
	{
		return "player_spawn";
	}
	bool CanEnterMine()
	{
		return true;
	}
};

class land_iat_miningsegment_junction extends IAT_MiningSegment_Colorbase
{
	//=============================================== VANILLA OVERRIDE (AND SIMILAR)
	override bool IsRock()
	{
		return true;
	}
		// this is only used for the action prompt name
	override string GetMiningYield(ItemBase itemInHands)
	{
		return "Various Ores";
	}
	// this is used in the action to spawn items
	override void GetMaterialAndQuantityYieldMap(ItemBase item, out map<string,int> output_map)
	{
		if (item == null)
		{
			return;
		}

		switch (item.GetType())
		{
			case "Pickaxe":
			case "SledgeHammer":
			case "Hammer":
			case "Mace":
				output_map.Insert("Stone",1);
			break;
			case "PipeWrench":
			case "Wrench":
			case "Screwdriver":
			case "Crowbar":
			case "MeatTenderizer":
			case "Iceaxe":
				output_map.Insert("SmallStone",1);
			break;
		}
	}
	override float GetDamageToMiningItemEachYield(ItemBase item)
	{
		if (item)
		{
			switch (item.GetType())
			{
			case "SledgeHammer":
			case "Pickaxe":
			case "Iceaxe":
				return 20;
			case "Wrench":
			case "Screwdriver":
			case "MeatTenderizer":
				return 25;
			case "PipeWrench":
			case "Crowbar":
				return 50;
			case "Hammer":
			case "Mace":
				return 40;
			}
		}

		return 25;
	}

	//=============================================== CUSTOM CODE
	// controls of this object can trigger the mining action
	override bool IsMineable()
	{
		// Print("target is minable");
		return true;
	}
	// controls which components inside the p3d that can be mined
	override bool CanMineComponent(string componentName)
	{
		// get the mining config if exists
		IAT_MiningConfig miningConfig;
		if (GetDayZGame() && Class.CastTo(miningConfig, GetDayZGame().GetIATMiningConfig()))
		{
			// if we can actually mine this specific segment
			if (miningConfig.CanMineSegmentComponent(GetFormattedPersistentID(), componentName))
			{
				return true;
			}
		}
		// no mining config means false result
		return false;
	}
	// increments the wall hit counter for a given wall
	override void IncrementComponentHitCounter(string componentName)
	{
		// get the mining config if exists
		IAT_MiningConfig miningConfig;
		if (GetDayZGame() && Class.CastTo(miningConfig, GetDayZGame().GetIATMiningConfig()))
		{
			// increment our counters;
			miningConfig.IncrementSegmentComponentHitCounter(GetFormattedPersistentID(), componentName)
		}
	}
};