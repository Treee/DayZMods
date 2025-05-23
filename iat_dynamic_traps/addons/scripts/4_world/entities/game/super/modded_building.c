modded class House
{
	protected bool m_IAT_HasBeenChecked = false;
	protected bool m_IAT_RandomEventPerformed = false;
	protected bool m_IAT_IsInCooldown = false;

	// ==================================================================================
	// Events
	// ==================================================================================

	// ==================================================================================
	// Helpers
	// ==================================================================================
	bool IAT_DoRandomDoorOpenEvent()
	{
		// Print("Doing Door Event");
		bool trapActivated = false;
		if (!m_IAT_HasBeenChecked)
		{
			// Print("Has Not Been Checked");
			// get the trap config from the game
			IAT_DynamicTrapsConfig trapConfig = GetDayZGame().GetIATDynamicTrapsConfig();
			// get the trap from the current object
			IAT_DynamicTrap dynamicTrap = trapConfig.GetTrapResults(GetType(), Type());
			if (dynamicTrap)
			{
				// roll the dice to see what we get
				int chance = trapConfig.RollTrapChance();
				// PrintFormat("Object has trap. Rolled: %1", chance);
				// get the results based on the dice roll
				IAT_DynamicTrapResult trapResult = dynamicTrap.GetResultByChance(chance);
				if (trapResult)
				{
					// wrap it all in one helper function
					IAT_CreateTrapResults(trapResult);
					// signal this building has done an event
					IAT_SetHasRandomEventPerformed(true);
					// reset that status after some time
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ResetEventStatus, 15000, false);
					trapActivated = true;
				}
				// reset checked if applicable
				if (dynamicTrap.HasTrapCooldown())
				{
					IAT_SetIsInCooldown(true);
					int cooldown = dynamicTrap.GetTrapCooldown() * 1000;
					// PrintFormat("Resetting %1 trap with cooldown: %2", GetType(), cooldown);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ResetCheckedStatus, cooldown, false);
				}
			}
			// signal this building has been checked
			IAT_SetHasBeenChecked(true);
		}
		return trapActivated;
	}

	bool IsTrappedObject()
	{
		IAT_DynamicTrapsConfig trapConfig = GetDayZGame().GetIATDynamicTrapsConfig();
		if (trapConfig.IsObjectAPotentialTrap(GetType(), Type()))
		{
			return true;
		}
		return false;
	}

	// this resets the event status so doors can be closed after some time since this extends to more than just shipping container doors
	void ResetEventStatus()
	{
		IAT_SetHasRandomEventPerformed(false);
	}
	void ResetCheckedStatus()
	{
		IAT_SetHasBeenChecked(false);
		IAT_SetIsInCooldown(false);
	}

	void IAT_CreateTrapResults(IAT_DynamicTrapResult trapResult)
	{
		ItemBase item;
		string randomResult;
		vector position = GetPosition();
		// for the number of things to create
		int randomResults = Math.RandomIntInclusive(1, trapResult.GetNumResults());
		for (int i = 0; i < randomResults; i++)
		{
			// get a string result
			randomResult = trapResult.GetRandomResult();
			randomResult.ToLower();

			// wiggle placement
			position[0] = position[0] + Math.RandomFloatInclusive(-0.5, 0.5);
			// position[1] = position[1] + Math.RandomFloatInclusive(-0.5, 0.5);
			position[2] = position[2] + Math.RandomFloatInclusive(-0.5, 0.5);
			// PrintFormat("x: %1 y: %2 z: %3", position[0], position[1], position[2]);

			// do a memory point placement
			if (trapResult.HasCustomSpawnLocations())
			{
				string memoryPoint = trapResult.GetRandomMemoryPoint();
				if (MemoryPointExists(memoryPoint))
				{
					position = ModelToWorld(GetMemoryPointPos(memoryPoint));
					// add += 0.5 to this so they are somewhat randomly placed
					position[0] = position[0] + Math.RandomFloatInclusive(-0.5, 0.5);
					// position[1] = position[1] + Math.RandomFloatInclusive(-0.5, 0.5);
					position[2] = position[2] + Math.RandomFloatInclusive(-0.5, 0.5);
				}
			}
			// PrintFormat("Creating new item: %1 at position %2", randomResult, position);
			// create them
			if (Class.CastTo(item, GetGame().CreateObjectEx(randomResult, position, trapResult.GetResultSpawnFlag())))
			{
				// random quantity (capped at 1/3rd max)
				if (item.HasQuantity())
				{
					int randomMax = item.GetQuantityMax() / 3;
					item.SetQuantity(Math.RandomIntInclusive(1, randomMax));
				}

				// random hp between ruined and pristine
				int randomHp = Math.RandomIntInclusive(GameConstants.STATE_PRISTINE, GameConstants.STATE_RUINED);
				item.SetHealthLevel(randomHp);
			}
		}
	}
	// ==================================================================================
	// Getters & Setters
	// ==================================================================================
	bool IAT_HasBeenChecked()
	{
		return m_IAT_HasBeenChecked;
	}
	void IAT_SetHasBeenChecked(bool isChecked)
	{
		m_IAT_HasBeenChecked = isChecked;
	}
	bool IAT_HasRandomEventPerformed()
	{
		return m_IAT_RandomEventPerformed;
	}
	void IAT_SetHasRandomEventPerformed(bool isChecked)
	{
		m_IAT_RandomEventPerformed = isChecked;
	}

	bool IAT_IsInCooldown()
	{
		return m_IAT_IsInCooldown;
	}
	void IAT_SetIsInCooldown(bool isCooldown)
	{
		m_IAT_IsInCooldown = isCooldown;
	}
};