// these are land_ based objects meant for map baking
class IAT_MiningSegment_Colorbase extends House
{
	protected string m_FormattedPersistentID;

	protected bool m_PlaySmokeParticles;
	protected bool m_IsExit;

	void IAT_MiningSegment_Colorbase()
	{
		RegisterNetSyncVariableBoolSignal("m_PlaySmokeParticles");
		RegisterNetSyncVariableBool("m_IsExit");
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		if (m_PlaySmokeParticles)
		{
			PlaySmokeParticles();
		}

	}

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
	string GetMiningYield(ItemBase itemInHands)	{ return ""; }

	void PlaySmokeParticles() {}

	void SpawnMaterialAndQuantityYield() {}

	float GetDamageToMiningItemEachYield(ItemBase item)	{ return 0; }

	float GetDamageToMineWallEachYield(ItemBase item) { return 0; }

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
		return vector.Zero;
	}

	//=============================================== GETTERS & SETTERS
	string GetFormattedPersistentID()
	{
		if (!m_FormattedPersistentID)
		{
			Print("GetFormattedPersistentID::This should never be null, server handles creation of junctions.");
			// int b1 = 0;
			// int b2 = 0;
			// int b3 = 0;
			// int b4 = 0;
			// GetPersistentID(b1, b2, b3, b4);
			// int uuid[4];
			// uuid[0] = b1;
			// uuid[1] = b2;
			// uuid[2] = b3;
			// uuid[3] = b4;
			// m_FormattedPersistentID = UUIDApi.FormatString(uuid);
			// PrintFormat("formatted persistent id for %1 - %2", GetType(), m_FormattedPersistentID);
		}
		return m_FormattedPersistentID;
	}
	void SetFormattedPersistentID(string id) { m_FormattedPersistentID = id; }

	void SetPlaySmokeParticles(bool value)
	{
		// PrintFormat("setting play particles to: %1", value);
		m_PlaySmokeParticles = value;
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( ResetSmokeParticles, GetResetTimerMS(), false);
	}
	bool GetPlaySmokeParticles()
	{
		return m_PlaySmokeParticles;
	}
	int GetResetTimerMS()
	{
		return 2000;
	}
	void ResetSmokeParticles()
	{
		SetSynchDirty();
	}
	bool IsExit()
	{
		return m_IsExit;
	}
	void SetIsExit(bool value)
	{
		m_IsExit = value;
	}
	bool IsEntrance()
	{
		return false;
	}
};

class land_iat_miningsegment_entrance extends IAT_MiningSegment_Colorbase
{
	void CreateMiningExit(vector returnPosition, vector surfacePosition)
	{
		// get the mining config
		IAT_MiningConfig miningConfig;
		if (GetDayZGame() && Class.CastTo(miningConfig, GetDayZGame().GetIATMiningConfig()))
		{
			// calculate where to place the first junction for this entrance
			vector underground = miningConfig.GetExitJunctionSpawnPosition(surfacePosition);

			// short circuit when a junction in the air exists
			if(vector.Distance(underground, "0 0 0") == 0)
				return;

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
				// entry for the entrance
				string id = miningConfig.CreateSegmentEntranceNode(returnPosition, teleportPosition);
				SetFormattedPersistentID(id);

				bool isExit = true;
				// entry for the first junction
				id = miningConfig.CreateSegmentJunctionNode(teleportPosition, returnPosition, isExit);
				m_LinkedExit.SetFormattedPersistentID(id);
				m_LinkedExit.SetIsExit(isExit);
				m_LinkedExit.SetSynchDirty();
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
	override bool IsEntrance()
	{
		return true;
	}
};

class land_iat_miningsegment_junction extends IAT_MiningSegment_Colorbase
{
	protected ParticleSource m_WallDestructParticle;
	protected ParticleSource m_WallCloudParticles;

	void ~land_iat_miningsegment_junction()
	{
		StopParticles();
	}
	override bool EEOnDamageCalculated(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEOnDamageCalculated(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		PrintFormat("DamageType: %1, Component: %2 DamageZone: %3 Ammo: %4", damageType, component, dmgZone, ammo);
		return true;
	}
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
	// override void GetMaterialAndQuantityYieldMap(ItemBase item, out map<string,int> output_map)
	// {
	// 	if (item == null)
	// 	{
	// 		return;
	// 	}

	// 	switch (item.GetType())
	// 	{
	// 		case "IAT_AdminPickaxe":
	// 		case "Pickaxe":
	// 		case "SledgeHammer":
	// 		case "Hammer":
	// 		case "Mace":
	// 			output_map.Insert("Stone",1);
	// 		break;
	// 		case "PipeWrench":
	// 		case "Wrench":
	// 		case "Screwdriver":
	// 		case "Crowbar":
	// 		case "MeatTenderizer":
	// 		case "Iceaxe":
	// 			output_map.Insert("SmallStone",1);
	// 		break;
	// 	}
	// }
	override float GetDamageToMiningItemEachYield(ItemBase item)
	{
		if (item)
		{
			switch (item.GetType())
			{
			case "SledgeHammer":
			case "Pickaxe":
			case "Iceaxe":
				return 5;
			case "Wrench":
			case "Screwdriver":
			case "MeatTenderizer":
				return 7;
			case "PipeWrench":
			case "Crowbar":
				return 10;
			case "Hammer":
			case "Mace":
				return 8;
			case "IAT_AdminPickaxe":
				return 0;
			}
		}

		return 25;
	}

	//=============================================== CUSTOM CODE
	// lets new items be mining tools if wanted
	override float GetDamageToMineWallEachYield(ItemBase item)
	{
		if (item)
		{
			switch (item.GetType())
			{
			case "SledgeHammer":
			case "Pickaxe":
			case "Iceaxe":
				return 10;
			case "Wrench":
			case "Screwdriver":
			case "MeatTenderizer":
				return 2;
			case "PipeWrench":
			case "Crowbar":
				return 3;
			case "Hammer":
			case "Mace":
				return 5;
			case "IAT_AdminPickaxe":
				return 5000;
			}
		}

		return 25;
	}
	// controls of this object can trigger the mining action
	override bool IsMineable()
	{
		// Print("target is minable");
		return true;
	}

	override void PlaySmokeParticles()
	{
		if (!GetGame().IsDedicatedServer())
		{
			StopParticles();
			m_WallDestructParticle = ParticleManager.GetInstance().PlayOnObject(ParticleList.PLASTIC_EXPLOSION, this, GetWallDestructParticlePosition());
			m_WallDestructParticle.ScaleParticleParam(EmitorParam.SIZE, Math.RandomFloatInclusive(1.8, 2.5));

			m_WallCloudParticles = ParticleManager.GetInstance().PlayOnObject(ParticleList.CLAYMORE_EXPLOSION, this, GetWallCloudParticlePosition());
		}
	}
	vector GetWallDestructParticlePosition()
	{
		PlayerBase player;
		if (Class.CastTo(player, GetGame().GetPlayer()))
		{
			vector headingDirection = MiscGameplayFunctions.GetHeadingVector(player);
			PrintFormat("wall particle position: %1", headingDirection);
			return headingDirection;
		}
		return "0 0 0";
	}
	vector GetWallCloudParticlePosition()
	{
		PlayerBase player;
		if (Class.CastTo(player, GetGame().GetPlayer()))
		{
			vector headingDirection = MiscGameplayFunctions.GetHeadingVector(player);
			PrintFormat("cloud particle position: %1", headingDirection);
			return headingDirection;
		}
		return "0 0 0";
	}

	void StopParticles()
	{
		if (m_WallDestructParticle)
			m_WallDestructParticle.StopParticle();

		if (m_WallCloudParticles)
			m_WallCloudParticles.StopParticle();
	}
};