// these are land_ based objects meant for map baking
class IAT_MiningSegment_Colorbase extends House
{
	/*
	* an array for holding how many logs are attached to a support
	* we do not save this information as a shortcut. not really needed since number of logs is 10
	*/
	protected ref TIntArray m_SupportLogCounts;
	// id to link to the json config on the server
	protected string m_FormattedPersistentID;

	// netsync veriables for controlling client side behavior
	protected bool m_PlaySmokeParticles;
	protected bool m_IsExit;

	void IAT_MiningSegment_Colorbase()
	{
		RegisterNetSyncVariableBoolSignal("m_PlaySmokeParticles");
		RegisterNetSyncVariableBool("m_IsExit");
		// down, up, east, west, north, south
		m_SupportLogCounts = {0, 0, 0, 0, 0, 0};
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
	// helper function for client actions
	bool CanEnterMine()
	{
		return false;
	}
	// helper function for client actions
	bool IsMineable()
	{
		return false;
	}

	// 	up 7 - Component35
	// down 8 - Component33
	// left (west) 9 - Component31
	// right (east) 10 - Component27
	// forward (south) 11 - Component25
	// back (north) 12 - Component29
	int IsJunctionOutOfMap(vector position, int surfaceY, int maxDepth, int mapEdgeBuffer)
	{
		if (position == vector.Zero)
		{
			// Print("Zero Vector, junction already exists or is out of bounds");
			return -1;
		}
		// check if this junction gets near the boundaries of the map
		World world;
		if (Class.CastTo(world, GetGame().GetWorld()))
		{
			// how far down can this mining system go
			int surfaceYMin = surfaceY - maxDepth;
			// modify this if we want to buffer a bit of space before hitting 0
			int absoluteMin = mapEdgeBuffer;
			// trim the max size by our minimum so now we have a nice buffer around the map
			int absoluteMax = world.GetWorldSize() - absoluteMin;

			if (position[1] > surfaceY)
			{
				// Print("===================================Cannot spawn a junction higher than surface level");
				return 6;
			}
			else if (position[1] < surfaceYMin)
			{
				// Print("===================================Cannot spawn a junction lower than bedrock level");
				return 7;
			}
			else if (position[0] < absoluteMin)
			{
				// Print("===================================Cannot spawn a junction further than the minimum map edge");
				return 8;
			}
			else if (position[0] > absoluteMax)
			{
				// Print("===================================Cannot spawn a junction further than the maximum map edge");
				return 9;
			}
			else if (position[2] < absoluteMin)
			{
				// Print("===================================Cannot spawn a junction further than the minimum map edge");
				return 10;
			}
			else if (position[2] > absoluteMax)
			{
				// Print("===================================Cannot spawn a junction further than the maximum map edge");
				return 11;
			}
		}
		return -1;
	}
	// server side only method to sync a junction to be an exit for client actions
	void UpdateNearbyJunction(vector entranceTeleportPosition, float radius = 0.25)
	{
		// update the in game object
		array<Object> nearest_objects = new array<Object>;
		array<CargoBase> proxy_cargos = new array<CargoBase>;
		GetGame().GetObjectsAtPosition3D(entranceTeleportPosition, radius, nearest_objects, proxy_cargos);

		// there should only be 1 object
		IAT_MiningSegment_Colorbase nearbyJunction;
		foreach (Object nearbyObject : nearest_objects)
		{
			// if the nearby object is a junction
			if (Class.CastTo(nearbyJunction, nearbyObject))
			{
				// set it to be an exit
				nearbyJunction.SetIsExit(true);
				nearbyJunction.SetSynchDirty();
			}
		}
	}

	void IncrementSupportCounter(string componentName)
	{
		IAT_MiningConfig miningConfig;
		if (GetDayZGame() && Class.CastTo(miningConfig, GetDayZGame().GetIATMiningConfig()))
		{
			// increment the config count for the junction and component
			int doorIndex = GetRawWallSupportIndexFromSelectionName(componentName);
			if (doorIndex > -1)
			{
				int supportCount = IncrementSupportCount(doorIndex);
				// PrintFormat("support count: %1", supportCount);
				// if we are above the support max
				if (supportCount >= miningConfig.GetMaxWallSupportCount())
				{
					// add the number of cave doors that exist prior to this door (12, up/down/left/right/forward/back for inner and outer)
					doorIndex = doorIndex + 12;
					// open the "door" for this wall support to show its visuals
					OpenDoor(doorIndex);
					// PrintFormat("close door: %1", doorIndex);
					// update the config
					miningConfig.UpdateJunctionDoorState(GetFormattedPersistentID(), doorIndex, 1);
					SetSynchDirty();
				}
			}
		}
	}

	// function for adding some number of supports to the array of support counters
	int IncrementSupportCount(int supportIndex, int numSupports = 1)
	{
		// if the index is valid
		if (m_SupportLogCounts.IsValidIndex(supportIndex))
		{
			// increment by 1
			m_SupportLogCounts[supportIndex] = m_SupportLogCounts[supportIndex] + numSupports;
			// return the updated count
			return m_SupportLogCounts[supportIndex];
		}
		// invalid index have -1 results
		return -1;
	}

	/*
	* down, up, east, west, north, south
	* door13, 14, 15, 16, 17, 18
	* subtract 13 and it gives us a nice index
	*/
	int GetRawWallSupportIndexFromSelectionName(string componentName)
	{
		// PrintFormat("component being checked: %1", componentName);
		// rip out any non number text
		componentName.Replace("door", "");
		// convert to an int
		int index = componentName.ToInt();
		// subtract to 0 out the index
		index = index - 13;
		// return the index
		return index;
	}


	// used to change the display name in the mining action
	string GetMiningYield(string itemName)	{ return ""; }
	/*
	* used for spawning ore yields. allows other mods to add here instead of being forced into my names
	* ore type is present so modders can change the name based on the ores they are adding/registering
	*/
	string GetOrePrefixName(string oreType)
	{
		oreType.ToLower();
		switch(oreType)
		{
			case "iron":
			case "copper":
			case "aluminium":
			case "lead":
			case "zinc":
			case "tin":
			case "silver":
			case "gold":
			case "coal":
			case "saltpeter":
			case "sulfur":
			case "saltcrystals":
			case "clay":
				return "IAT_MiningOre";
			break;
			case "quartz":
			case "amethyst":
			case "topaz":
			case "ruby":
			case "sapphire":
			case "diamond":
				return "IAT_MiningGem";
			break;
		}
		return "";
	}

	// used to play smoke particles when a wall opens
	void PlaySmokeParticles() {}

	// the items to spawn then a full animation cycle is complete
	void SpawnMaterialAndQuantityYield(vector playerPosition) {}

	// the damage to apply to an item each full animation action
	float GetDamageToMiningItemEachYield(string itemName)	{ return 0; }

	// the damage to apply to a wall segment each full animation action
	float GetDamageToMineWallEachYield(string itemName) { return 0; }

	// Usesd for when a full action of mining is invoked from the mine action
	void OnServerWallMined(int doorIndex, string itemName) { }

	// Used for creating an entrance into the mining system. override in the land_iat_miningsegment_entrance
	void OnServerMineEntranceCreated(vector playerPosition, vector entrancePosition) {}

	/*
	*
	* Used to create a mining junction that can either be an exit or normal mining segment.
	* The persistent id is set AFTER the config creates the record.
	* Exits sync their status to the client for return teleport action prompts
	*
	*/
	IAT_MiningSegment_Colorbase CreateJunctionSegment(vector segmentPosition, vector returnPosition = vector.Zero, bool isExit = false)
	{
		land_iat_miningsegment_junction iat_junction;
		// create a junction at the location underneath the action target
		if (Class.CastTo(iat_junction, GetGame().CreateObjectEx("land_iat_miningsegment_junction", segmentPosition, ECE_SETUP|ECE_CREATEPHYSICS|ECE_KEEPHEIGHT)))
		{
			// get the mining config
			IAT_MiningConfig miningConfig;
			if (GetDayZGame() && Class.CastTo(miningConfig, GetDayZGame().GetIATMiningConfig()))
			{
				// create entry in the mining config
				string id = miningConfig.CreateSegmentJunctionNode(segmentPosition, returnPosition, isExit);
				// set the id of newly created junctions
				iat_junction.SetFormattedPersistentID(id);
				// only sync the exits because they are false by default
				if (isExit)
				{
					iat_junction.SetIsExit(isExit);
					iat_junction.SetSynchDirty();
				}
			}
			return iat_junction;
		}
		return null;
	}

	// searches the configs for this segments teleport destination
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
	// allows p3ds to set a memory point for controlling where a player spawns when teleports
	vector GetPlayerSpawnPosition()
	{
		// get the position we should spawn the player.
		// if the memory point in the p3d doesnt exist, use a default
		vector teleportPosition;
		if (MemoryPointExists(GetPlayerSpawnMemoryPoint()))
		{
			teleportPosition = GetMemoryPointPos(GetPlayerSpawnMemoryPoint());
			teleportPosition = ModelToWorld(teleportPosition);
			return teleportPosition;
		}
		return vector.Zero;
	}
	// memory point in a p3d to set where a player spawns
	string GetPlayerSpawnMemoryPoint()
	{
		return "player_spawn";
	}
	string GetFormattedPersistentID()
	{
		if (!m_FormattedPersistentID)
			Print("GetFormattedPersistentID::This should never be null, server handles creation of junctions.");

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
	override void OnServerMineEntranceCreated(vector playerPosition, vector entrancePosition)
	{
		// get the mining config
		IAT_MiningConfig miningConfig;
		if (GetDayZGame() && Class.CastTo(miningConfig, GetDayZGame().GetIATMiningConfig()))
		{
			// look in the entrance p3d and try to get where the player should teleport back to on an exit
			vector exitTeleportPosition = GetPlayerSpawnPosition();
			if (exitTeleportPosition == vector.Zero)
			{
				// default to the entrance position
				exitTeleportPosition = entrancePosition;
			}

			// calculate where to place the first junction for this entrance
			vector segmentPosition = miningConfig.GetExitJunctionSpawnPosition(entrancePosition);
			// the teleport destination of the entrance
			vector entranceTeleportPosition;
			// check to see if there is an existing junction present
			IAT_MiningSegmentConfig segmentConfig;
			if (Class.CastTo(segmentConfig, miningConfig.IsExistingJunctionPresent(segmentPosition)))
			{
				// junction exists, link the entrance to the junction in the config
				entranceTeleportPosition = segmentConfig.GetSegmentPosition();
				// link the junction to the entrance in the config
				miningConfig.UpdateJunctionToExit(segmentConfig.GetID(), entrancePosition);
				// update the in game object
				UpdateNearbyJunction(entranceTeleportPosition);
			}
			else // create a new junction at the indicated position
			{
				IAT_MiningSegment_Colorbase iat_ExitJunction;
				if (Class.CastTo(iat_ExitJunction, CreateJunctionSegment(segmentPosition, exitTeleportPosition, true)))
				{
					// get the position we should spawn the player.
					// if the memory point in the p3d doesnt exist, use a default
					entranceTeleportPosition = iat_ExitJunction.GetPlayerSpawnPosition();
					if (entranceTeleportPosition == vector.Zero)
					{
						entranceTeleportPosition = segmentPosition;
					}
					// ensure the first junction has some supports
					iat_ExitJunction.OpenDoor(12);
					iat_ExitJunction.OpenDoor(13);
					iat_ExitJunction.OpenDoor(14);
					iat_ExitJunction.OpenDoor(15);
					iat_ExitJunction.OpenDoor(16);
					iat_ExitJunction.OpenDoor(17);
				}
			}
			// save the entrance in the json config
			string id = miningConfig.CreateSegmentEntranceNode(entrancePosition, entranceTeleportPosition);
			// set the persistent id
			SetFormattedPersistentID(id);
		}
	}
	override bool CanEnterMine()
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
	//=============================================== VANILLA OVERRIDE (AND SIMILAR)
	override bool IsRock()
	{
		return true;
	}
	// this is only used for the action prompt name
	override string GetMiningYield(string itemName)
	{
		return "Various Ores";
	}
	override float GetDamageToMiningItemEachYield(string itemName)
	{
		if (itemName != "")
		{
			switch (itemName)
			{
			case "SledgeHammer":
			case "Pickaxe":
			case "Iceaxe":
				return 2;
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

	// the items to spawn then a full animation cycle is complete
	override void SpawnMaterialAndQuantityYield(vector playerPosition)
	{
		super.SpawnMaterialAndQuantityYield(playerPosition);
		// get the mining config if exists
		IAT_MiningConfig miningConfig;
		if (GetDayZGame() && Class.CastTo(miningConfig, GetDayZGame().GetIATMiningConfig()))
		{
			TFloatArray oreChances = miningConfig.GetMiningSegmentOreChances(GetFormattedPersistentID());
			if (oreChances && oreChances.Count() > 0)
			{
				float oreChanceRoll;
				bool shouldSpawnOre;
				foreach (int index, float chance : oreChances)
				{
					shouldSpawnOre = false;
					// ore chance is above 100% (high intensity)
					if (chance > 1)
					{
						// Print("super ore, spawn it with no chance");
						// spawn ore here on playerPosition
						shouldSpawnOre = true;
					}
					else
					{
						oreChanceRoll = Math.RandomFloatInclusive(0, 1);
						/*
						* i dont want to 1 - chance to get the probability so
						* we are just going to do it this way because its easier atm
						*/
						// if the roll is less than the chance
						// PrintFormat("Random Roll: %1 OreChance: %2", oreChanceRoll, chance);
						if (oreChanceRoll < chance)
						{
							// spawn ore here on playerPosition
							shouldSpawnOre = true;
						}
					}

					if (shouldSpawnOre)
					{
						string oreType = miningConfig.GetOreTypeByChanceIndex(index); // get ore type by index
						string oreClassName = string.Format("%1_%2", GetOrePrefixName(oreType), oreType);
						if (oreType == "")
						{
							oreClassName = "Stone";
						}
						// create the ore object
						GetGame().CreateObjectEx(oreClassName, playerPosition, ECE_SETUP|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY);
					}
				}
			}
		}
	}


	//=============================================== CUSTOM CODE
	override void OnServerWallMined(int doorIndex, string itemName)
	{
		// do damage to the target door based on whatever item is in hands
		string componentName = DamageMineWallDoor(doorIndex, itemName);

		// get the mining config if exists
		IAT_MiningConfig miningConfig;
		if (GetDayZGame() && Class.CastTo(miningConfig, GetDayZGame().GetIATMiningConfig()))
		{
			// if the damage is sufficient to open the door
			if (GetHealth(componentName, "Health") <= 0)
			{
				// open it
				OpenDoor(doorIndex);
				miningConfig.UpdateJunctionDoorState(GetFormattedPersistentID(), doorIndex, 1);
				// spawn the next junction if this wall was an inner wall
				// up down, left right, forward back is 6, 0 ordinal makes 5. door index less than 6 is an inner door. yay shortcuts
				if (doorIndex < 6)
				{
					// create a new junction at the indicated position
					vector newSegmentPosition = miningConfig.GetNextJunctionSpawnPosition(GetPosition(), doorIndex);

					int doorToLock = IsJunctionOutOfMap(newSegmentPosition, miningConfig.GetSkySurfaceY(), miningConfig.GetMaxDepth(), miningConfig.GetMapEdgeBuffer());
					// if the junction would be out of bounds
					if (doorToLock > -1)
					{
						// lock the outter door of this junction in the specific direction
						LockDoor(doorToLock, true);
						miningConfig.UpdateJunctionDoorState(GetFormattedPersistentID(), doorToLock, 2);
					}
					else
					{
						// if the new position is zero, dont create a junction
						if (newSegmentPosition == vector.Zero)
							return;

						IAT_MiningSegment_Colorbase iat_ExitJunction;
						if (Class.CastTo(iat_ExitJunction, CreateJunctionSegment(newSegmentPosition)))
						{
							// Print("new junction created successfully");
						}
					}
				}
				// play client side smoke particles
				SetPlaySmokeParticles(true);
				// sync with the server
				SetSynchDirty();
			}
		}
	}
	string DamageMineWallDoor(int doorIndex, string itemName)
	{
		// add one to the index because the door names start at 1 not 0
		int modifiedDoorIndex = doorIndex + 1;
		// format the component name to match what is in the p3d
		string componentName = string.Format("door%1", modifiedDoorIndex);
		float doorDamage = GetDamageToMineWallEachYield(itemName);
		// reduce hp based on item in hands
		DecreaseHealth(componentName, "Health", doorDamage);

		// convenience return
		return componentName;
	}

	// lets new items be mining tools if wanted
	override float GetDamageToMineWallEachYield(string itemName)
	{
		if (itemName != "")
		{
			switch (itemName)
			{
			case "SledgeHammer":
			case "Pickaxe":
			case "Iceaxe":
				return 20;
			case "Wrench":
			case "Screwdriver":
			case "MeatTenderizer":
				return 4;
			case "PipeWrench":
			case "Crowbar":
				return 6;
			case "Hammer":
			case "Mace":
				return 10;
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
			// PrintFormat("wall particle position: %1", headingDirection);
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
			// PrintFormat("cloud particle position: %1", headingDirection);
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