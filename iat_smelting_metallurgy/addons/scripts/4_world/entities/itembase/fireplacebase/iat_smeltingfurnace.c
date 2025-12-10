class IAT_SmeltingFurnace_ColorBase extends FireplaceBase
{
	static const string IAT_FIRE_POSITION = "oven_point1";
	static const string IAT_SMOKE_POSITION = "oven_smoke1";
	static const int IAT_NOTIFICATION_DISPLAY_TIME = 4;

	protected bool m_IAT_HasAccelerantAttached = false;
	protected bool m_IAT_HasOre1Attached = false;
	protected bool m_IAT_HasOre2Attached = false;
	protected int m_IAT_AccelerantMaxTemperature = 500;
	protected int m_IAT_AccelerantMinTemperature = 15;

	protected bool m_IAT_HasClientResultUpdate = false;
	protected bool m_IAT_CurrentResult = false;
	protected bool m_IAT_CurrentIsOver = false;
	protected int m_IAT_CurrentAccelHPWager = -1;
	protected int m_IAT_CurrentOre1Wager = -1;
	protected int m_IAT_CurrentOre2Wager = -1;

	protected string m_IAT_CurrentUser = ""; // ensure only 1 person can interact with the furnace minigame at a time

	protected EffectSound m_CountDownSound;

	void IAT_SmeltingFurnace_ColorBase()
    {
		PARTICLE_FIRE_START 	= ParticleList.BARREL_FIRE_START;
		PARTICLE_SMALL_FIRE 	= ParticleList.BARREL_SMALL_FIRE;
		PARTICLE_NORMAL_FIRE	= ParticleList.BARREL_NORMAL_FIRE;
		PARTICLE_SMALL_SMOKE 	= ParticleList.BARREL_SMALL_SMOKE;
		PARTICLE_NORMAL_SMOKE	= ParticleList.BARREL_NORMAL_SMOKE;
		PARTICLE_FIRE_END 		= ParticleList.BARREL_FIRE_END;
		PARTICLE_STEAM_END		= ParticleList.BARREL_FIRE_STEAM_2END;

        ProcessInvulnerabilityCheck(GetInvulnerabilityTypeString());
    }
	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionToggleFurnaceLock);
	}
	override protected void InitializeTemperatureSources()
	{
		m_UTSLFireplace = new UniversalTemperatureSourceLambdaFireplace();
		m_UTSLFireplace.SetSmallFireplaceTemperatureMax(500);
		m_UTSLFireplace.SetNormalFireplaceTemperatureMax(500);

		m_UTSource = new UniversalTemperatureSource(this, m_UTSSettings, m_UTSLFireplace);
	}

	override string GetDisplayName()
	{
        string itemName = super.GetDisplayName();
		itemName = string.Format("%1 | %2 C", itemName, GetTemperature());
		return itemName;
	}
	override void RefreshFireplaceVisuals()
    {
        super.RefreshFireplaceVisuals();

		if (IAT_HasAccelerantAttached())
        {
            SetFuelBurnRateMP(0.01);
        }
		else
		{
			SetFuelBurnRateMP(0.3);
		}
    }
	//================================================== RPC'S
    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        switch (rpc_type)
        {
			case IAT_RPC_SMELTING.CLIENT_CANCEL_WAGER:
				HandleOnServerCancelWager(sender, ctx);
				break;
            case IAT_RPC_SMELTING.CLIENT_MAKE_WAGER: // client -> server call
                HandleOnServerReceiveWager(sender, ctx);
				break;
			case IAT_RPC_SMELTING.CLIENT_EVALUATE_RESULTS: // client -> server call
                HandleOnServerEvaluateResults(sender, ctx);
				break;

			case IAT_RPC_SMELTING.SERVER_SEND_RESULTS: // server -> client call
				HandleOnClientReceiveResults(sender, ctx);
				break;
        }
        super.OnRPC(sender, rpc_type, ctx);
    }
	// Undestroyable
    override string GetInvulnerabilityTypeString()
	{
		return "disableBaseDamage";
	}
	// false here because we do not want the ability to destroy the forge when nothing is attached (unlike a fire)
    override bool IsPrepareToDelete()
	{
		return false;
	}
	override bool IgnoreOutOfReachCondition()
	{
		return true;
	}
	override bool CanHaveWetness()
   	{
      return false;
   	}
	override bool CanPutInCargo( EntityAI parent )
    {
        return false;
    }
    override bool CanPutIntoHands( EntityAI parent )
    {
        return false;
    }
    override bool CanDisplayAttachmentCategory( string category_name )
	{
		return true;
	}
    override bool HasFlammableMaterial()
	{
		return true;
	}
	override bool IsHealthVisible()
	{
		return true;
	}
	override bool IsInventoryVisible()
	{
		return true;
	}
	override bool DisableVicinityIcon()
	{
		return false;
	}
	override bool CanBeIgnitedBy(EntityAI igniter = NULL)
	{
		return HasAnyKindling() && !IsBurning() && !GetHierarchyParent();
	}
	override bool CanIgniteItem(EntityAI ignite_target = NULL)
	{
		return IsBurning();
	}
	override bool IsIgnited()
	{
		return IsBurning();
	}
	override void OnIgnitedTarget( EntityAI target_item ){}

	override void OnIgnitedThis( EntityAI fire_source )
	{
		//remove grass
		// Object cc_object = g_Game.CreateObjectEx( OBJECT_CLUTTER_CUTTER , GetPosition(), ECE_PLACE_ON_SURFACE );
		// cc_object.SetOrientation ( GetOrientation() );
		// g_Game.GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( DestroyClutterCutter, 200, false, cc_object );

		//start fire
		StartFire();

		if ( fire_source )
		{
			Man player = fire_source.GetHierarchyRootPlayer();

			if ( player )
			{
				EFireIgniteType ignate_type = EFireIgniteType.Unknow;

				if ( fire_source.ClassName() == "Matchbox"  )
				{
					ignate_type = EFireIgniteType.Matchbox;
				}
				else if ( fire_source.ClassName() == "Roadflare"  )
				{
					ignate_type = EFireIgniteType.Roadflare;
				}
				else if ( fire_source.ClassName() == "HandDrillKit"  )
				{
					ignate_type = EFireIgniteType.HandDrill;
				}


				SyncEvents.SendPlayerIgnatedFireplace( player, ignate_type );
			}
		}
	}
	override bool IsThisIgnitionSuccessful( EntityAI item_source = NULL )
	{
		SetIgniteFailure( false );
		Param1<bool> failure;

		//check kindling
		if ( !HasAnyKindling() )
		{
			return false;
		}

		//check roof
		if ( !IsOven() )
		{
			if ( !IsCeilingHighEnoughForSmoke() && IsOnInteriorSurface() )
			{
				return false;
			}
		}

		//check surface
		if ( IsOnWaterSurface() )
		{
			return false;
		}

		//check wetness
		if ( IsWet() )
		{
			SetIgniteFailure( true );

			failure = new Param1<bool>( GetIgniteFailure() );
			g_Game.RPCSingleParam( this, FirePlaceFailure.WET, failure, true );
			return false;
		}

		// check if the fireplace isnt below a roof
		//  excluding this check whein oven stage
		CheckForRoofLimited(0);
		if ( !IsOven() && !IsRoofAbove() )
		{
			// if not, check if there is strong rain or wind
			if ( IsRainingAbove() )
			{
				SetIgniteFailure( true );

				failure = new Param1<bool>( GetIgniteFailure() );
				g_Game.RPCSingleParam( this, FirePlaceFailure.WET, failure, true );
				return false;
			}

			if ( IsWindy() )
			{
				SetIgniteFailure( true );

				failure = new Param1<bool>( GetIgniteFailure() );
				g_Game.RPCSingleParam( this, FirePlaceFailure.WIND, failure, true );
				return false;
			}
		}

		return true;
	}
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);

		ItemBase item_base = ItemBase.Cast(item);

		if (IsKindling(item_base) || IsFuel(item_base))
		{
			AddToFireConsumables(item_base);
		}
		if (slot_name == "IAT_RawOre1")
		{
			m_IAT_HasOre1Attached = true;
		}
		if (slot_name == "IAT_RawOre2")
		{
			m_IAT_HasOre2Attached = true;
		}

		IAT_SetMinMaxFurnaceTemperature();
		RefreshFireplaceVisuals();
	}
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);

		ItemBase item_base = ItemBase.Cast(item);

		if (IsKindling(item_base) || IsFuel(item_base))
		{
			RemoveFromFireConsumables(GetFireConsumableByItem(item_base));
		}
		if (slot_name == "IAT_RawOre1")
		{
			m_IAT_HasOre1Attached = false;
		}
		if (slot_name == "IAT_RawOre2")
		{
			m_IAT_HasOre2Attached = false;
		}

		IAT_SetMinMaxFurnaceTemperature();
		RefreshFireplaceVisuals();
	}
	override protected vector GetFireEffectPosition()
	{
		if (MemoryPointExists(IAT_FIRE_POSITION))
		{
			return GetMemoryPointPos(IAT_FIRE_POSITION);
		}
		return Vector(0, 0.05, 0);
	}
	override protected vector GetSmokeEffectPosition()
	{
		if (MemoryPointExists(IAT_SMOKE_POSITION))
		{
			return GetMemoryPointPos(IAT_SMOKE_POSITION);
		}
		return Vector(0, 0.05, 0);
	}

	bool IAT_CanOpenMiniGameMenu()
	{
		return IAT_HasOreAttached() && IAT_AreSlotsLocked();
	}
	void IAT_OpenMiniGameMenu()
	{
		// client only;
		if (!g_Game.IsDedicatedServer())
		{
			// if there are no ores attached OR no accelerant attached
			if (!IAT_HasOreAttached() || !IAT_HasAccelerantAttached())
			{
				IAT_CloseMiniGameMenu();
			}
			else
			{
				g_Game.GetMission().OnItemUsed(this, g_Game.GetPlayer());
			}
		}
	}
	void IAT_CloseMiniGameMenu()
	{
		// client only;
		if (!g_Game.IsDedicatedServer())
		{
			// close the current menu
			g_Game.GetUIManager().FindMenu(IAT_MENU_SMELTING_MINIGAME).Close();
		}
	}
	// Client UI -> Server
	void ClientRPC_MakeWager(bool isOver, int accelerantHpWager, int ore1Wager, int ore2Wager)
	{
		if (!g_Game.IsDedicatedServer())
		{
			ScriptRPC rpc;
			// if there are no ores attached OR no accelerant attached
			if (!IAT_HasOreAttached() || !IAT_HasAccelerantAttached())
			{
				IAT_CloseMiniGameMenu();
				rpc = new ScriptRPC();
				rpc.Send(this, IAT_RPC_SMELTING.CLIENT_CANCEL_WAGER, true, g_Game.GetPlayer().GetIdentity());
				return;
			}

			rpc = new ScriptRPC();
			rpc.Write(isOver);
			rpc.Write(accelerantHpWager);
			rpc.Write(ore1Wager);
			rpc.Write(ore2Wager);
			rpc.Send(this, IAT_RPC_SMELTING.CLIENT_MAKE_WAGER, true, g_Game.GetPlayer().GetIdentity());

			IAT_PlayCountDownSounds();
		}
	}
	// Executed on server after receiving the ClientRPC_MakeWager rpc
	void HandleOnServerCancelWager(PlayerIdentity sender, ParamsReadContext ctx)
    {
		// server only
        if (g_Game.IsDedicatedServer())
        {
			// no data to deserialize. if this is hit, send a message to the player about needing more ore or accelerant
			// basically let them know hwy the UI was suddenly closed.
			string oreMsg = "";
			string accelerantMsg = "";
			if (!IAT_HasOreAttached())
			{
				oreMsg = string.Format("Attach More Ore");
			}
			if (!IAT_HasAccelerantAttached())
			{
				accelerantMsg = string.Format("Attach More Accelerant");
			}
			string msg = string.Format("UI Closed - %1 | %2", oreMsg, accelerantMsg);
			NotificationSystem.SendNotificationToPlayerIdentityExtended(sender, IAT_NOTIFICATION_DISPLAY_TIME, "CANCEL WAGER", msg, "set:ccgui_enforce image:Icon40Emergency");
        }
    }
	// Executed on server after receiving the ClientRPC_MakeWager rpc
	void HandleOnServerReceiveWager(PlayerIdentity sender, ParamsReadContext ctx)
    {
		// server only
        if (g_Game.IsDedicatedServer())
        {
			// furnace is reserved by someone else
			if (IAT_HasWagerOwner())
			{
				string msg1 = "Another player has this furnace reserved.";
				NotificationSystem.SendNotificationToPlayerIdentityExtended(sender, IAT_NOTIFICATION_DISPLAY_TIME, "WAGER", msg1, "set:ccgui_enforce image:Icon40Emergency");
				return;
			}
			else
			{
				IAT_SetCurrentUser(sender.GetPlainId());
			}

			// if we run into issues deserializing the data
			if (!ctx.Read(m_IAT_CurrentIsOver))
			{
				PrintFormat("[HandleOnServerReceiveWager] Unable to read player over/under wager. Furnace Position: %1", GetPosition());
				return;
			}
			if (!ctx.Read(m_IAT_CurrentAccelHPWager))
			{
				PrintFormat("[HandleOnServerReceiveWager] Unable to read player accelerant HP wager. Furnace Position: %1", GetPosition());
				return;
			}
			if (!ctx.Read(m_IAT_CurrentOre1Wager))
			{
				PrintFormat("[HandleOnServerReceiveWager] Unable to read player ore 1 wager. Furnace Position: %1", GetPosition());
				return;
			}
			if (!ctx.Read(m_IAT_CurrentOre2Wager))
			{
				PrintFormat("[HandleOnServerReceiveWager] Unable to read player ore 2 wager. Furnace Position: %1", GetPosition());
				return;
			}

			// if (!HasValidWager())
			// {
			// 	string msg2 = "BAD WAGER VALUES.";
			// 	NotificationSystem.SendNotificationToPlayerIdentityExtended(sender, IAT_NOTIFICATION_DISPLAY_TIME, "WAGER", msg2, "set:ccgui_enforce image:Icon40Emergency");
			// 	return;
			// }


			string overUnder = "Under";
			if (m_IAT_CurrentIsOver)
			{
				overUnder = "Over";
			}
			string msg = string.Format("Player Wager - Accelerant HP: %1 - Ore1: %2 - Ore2: %3 - Over/Under: %4", m_IAT_CurrentAccelHPWager, m_IAT_CurrentOre1Wager, m_IAT_CurrentOre2Wager, overUnder);
			NotificationSystem.SendNotificationToPlayerIdentityExtended(sender, IAT_NOTIFICATION_DISPLAY_TIME, "WAGER", msg, "set:ccgui_enforce image:Icon40Emergency");
        }
    }
	void ClientRPC_EvaluateResults(float meanTemperature, float actualTemperature)
	{
		if (!g_Game.IsDedicatedServer())
		{
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(meanTemperature);
			rpc.Write(actualTemperature);
			rpc.Send(this, IAT_RPC_SMELTING.CLIENT_EVALUATE_RESULTS, true, g_Game.GetPlayer().GetIdentity());
		}
	}
	// Executed on server after receiving the ClientRPC_EvaluateResults rpc
	void HandleOnServerEvaluateResults(PlayerIdentity sender, ParamsReadContext ctx)
	{
		// server only
        if (g_Game.IsDedicatedServer())
        {
			float meanTemperature;
			float actualTemperature;
			if (!ctx.Read(meanTemperature))
			{
				PrintFormat("[HandleOnServerReceiveWager] Unable to read mean temperature. Furnace Position: %1", GetPosition());
				return;
			}
			if (!ctx.Read(actualTemperature))
			{
				PrintFormat("[HandleOnServerReceiveWager] Unable to read mean temperature. Furnace Position: %1", GetPosition());
				return;
			}

			// do server work to pick winner
			PlayerBase player;
			bool isWinner = IAT_EvaluateResults(meanTemperature, actualTemperature);
			if (isWinner)
			{
				NotificationSystem.SendNotificationToPlayerIdentityExtended(sender, IAT_NOTIFICATION_DISPLAY_TIME, "WINNER!!!", "You have chosen correctly.", "set:ccgui_enforce image:Icon40Emergency");
				// update player win stats (for writing on the server)
				if (Class.CastTo(player, sender.GetPlayer()))
				{
					player.IAT_IncrementSmeltingWins(sender);
				}
			}
			else
			{
				NotificationSystem.SendNotificationToPlayerIdentityExtended(sender, IAT_NOTIFICATION_DISPLAY_TIME, "LOSER! :(", "You have chosen incorrectly.", "set:ccgui_enforce image:Icon40Emergency");
				// update player loss stats (for writing on the server)
				if (Class.CastTo(player, sender.GetPlayer()))
				{
					player.IAT_IncrementSmeltingLoss(sender);
				}
			}
			// rpc back to client the result
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(isWinner);
			rpc.Send(this, IAT_RPC_SMELTING.SERVER_SEND_RESULTS, true, sender);

			// reset the furnace wager user
			IAT_ResetCurrentUser();
		}
	}
	void HandleOnClientReceiveResults(PlayerIdentity sender, ParamsReadContext ctx)
	{
		// client side only
		if (!g_Game.IsDedicatedServer())
        {
			// reset the player wager for the next round
			ResetPlayerWager();

			if (!ctx.Read(m_IAT_CurrentResult))
			{
				PrintFormat("[HandleOnServerReceiveWager] Unable to read server result on client. Furnace Position: %1", GetPosition());
				return;
			}
			m_IAT_HasClientResultUpdate = true;

			// update player win stats (for client side rendering)
			PlayerBase player;
			if (m_IAT_CurrentResult)
			{
				// update player win stats (for writing on the server)
				if (Class.CastTo(player, g_Game.GetPlayer()))
				{
					player.IAT_IncrementSmeltingWins(sender);
				}
			}
			else
			{
				// update player loss stats (for writing on the server)
				if (Class.CastTo(player, g_Game.GetPlayer()))
				{
					player.IAT_IncrementSmeltingLoss(sender);
				}
			}

			// the above bool is a shortcut to allow me to use the same open menu code but
			// not actually create a new menu on this invocation but rather us it as an update (upsert)
			IAT_OpenMiniGameMenu();
		}
	}
	bool IAT_EvaluateResults(float meanTemperature, float actualTemperature)
	{
		// unlock slots so we can remove quantity
		IAT_UnlockOreSlots();
		bool isPlayerWinner = false;
		bool isOver = actualTemperature > meanTemperature;
		// if these are the same, we have a win
		if (m_IAT_CurrentIsOver == isOver)
		{
			// spawn materials, consume accelerant by 25% the wager
			IAT_PlayerWin();
			isPlayerWinner = true;
		}
		else // player lost the bet
		{
			// consume half the accelerant and half materials
			IAT_PlayerLose();
		}
		// relock ore slots
		IAT_LockOreSlots();
		return isPlayerWinner;
	}
	bool GetCurrentClientResult()
	{
		return m_IAT_CurrentResult;
	}
	bool HasClientResultUpdate()
	{
		return m_IAT_HasClientResultUpdate;
	}
	bool HasValidWager()
	{
		// do not allow values below 0
		if (m_IAT_CurrentAccelHPWager > 0)
			return false;
		if (m_IAT_CurrentOre1Wager > 0)
			return false;
		if (m_IAT_CurrentOre2Wager > 0)
			return false;

		return true;
	}
	void ResetHasClientResultUpdate(bool state = false)
	{
		m_IAT_HasClientResultUpdate = state;
	}
	void ResetPlayerWager()
	{
		m_IAT_CurrentIsOver = false;
		m_IAT_CurrentAccelHPWager = -1;
		m_IAT_CurrentOre1Wager = -1;
		m_IAT_CurrentOre2Wager = -1;
	}

	// the base yield of bars per iron ore
	int IAT_GetBaseBars(int oreWager, int orePerBar = 2)
	{
		// 2 ore = 1 bar by default
		return Math.Max(1, Math.Floor(oreWager / orePerBar));
	}
	// normalized risk value derived from accelerant wager
	float IAT_GetPlayerStake(int accelWager, int accelMaxHp)
	{
		// get the normalized (between 0 - 1) value of the players accelerant wager
		return Math.Clamp((accelWager / accelMaxHp), 0, 1);
	}
	// bar yield multiplier.
	float IAT_GetResultTierMultiplier(float playerStake)
	{
		float multiplier = 1;
		// crit result spread
		float PNormal = Math.Lerp(0.90, 0.30, playerStake);
		float PCrit = Math.Lerp(0.09, 0.45, playerStake);
		float PUltra = Math.Lerp(0.01, 0.25, playerStake);

		// multiplier spread
		float multiplierMin = 1.0;
		float multiplierMax = Math.Lerp(1.5, 3.0, playerStake);
		float chance = Math.RandomFloat01();
		if (chance < PNormal)
		{
			// normal result
			multiplierMax = Math.Lerp(1.5, 3.0, playerStake);
		}
		else if (chance < (PNormal + PCrit))
		{
			// crit result
			multiplierMin = Math.Lerp(1.5, 3.0, playerStake);
			multiplierMax = Math.Lerp(3.0, 7.0, playerStake);
		}
		else
		{
			// ultra crit
			multiplierMin = Math.Lerp(3.0, 7.0, playerStake);
			multiplierMax = Math.Lerp(7.0, 10.0, playerStake);
		}
		multiplier = Math.RandomFloatInclusive(multiplierMin, multiplierMax);

		return multiplier;
	}
	// calculate actual yield of bars
	int IAT_CalculateFinalBarYield()
	{
		ItemBase fuel;
		if (Class.CastTo(fuel, FindAttachmentBySlotName("IAT_Accelerant")))
		{
			int totalOreWager = m_IAT_CurrentOre1Wager + m_IAT_CurrentOre2Wager;
			int numBaseBars = IAT_GetBaseBars(totalOreWager);

			float playerStake = IAT_GetPlayerStake(m_IAT_CurrentAccelHPWager, fuel.GetMaxHealth());
			float multiplier = IAT_GetResultTierMultiplier(playerStake);

			int finalBars = Math.Max(1, Math.Floor(numBaseBars * multiplier));

			return finalBars;
		}
		return 1;
	}
	string IAT_GetOreType(string slotName)
	{
		ItemBase ore;
		if (Class.CastTo(ore, FindAttachmentBySlotName(slotName)))
		{
			return ore.ConfigGetString("color");
		}
		return "";
	}
	void IAT_PlayerWin()
	{
		// spawn materials, consume accelerant by 25% the wager
		IAT_ConsumeAccelerant(0.25);

		// spawn loot
		IAT_SpawnResults(IAT_GetOreType("IAT_RawOre1"), IAT_GetOreType("IAT_RawOre2"), IAT_CalculateFinalBarYield());
	}
	void IAT_PlayerLose()
	{
		// consume half the accelerant and half materials
		IAT_ConsumeAccelerant(0.5);
		IAT_ConsumeOres("IAT_RawOre1", m_IAT_CurrentOre1Wager);
		IAT_ConsumeOres("IAT_RawOre2", m_IAT_CurrentOre2Wager);
	}
	void IAT_ConsumeAccelerant(float percentage)
	{
		ItemBase fuel;
		if (Class.CastTo(fuel, FindAttachmentBySlotName("IAT_Accelerant")))
		{
			int quantityModifier = m_IAT_CurrentAccelHPWager * percentage;
			fuel.AddHealth(-quantityModifier);
			// get rid of it if we are ruined
			if (fuel.IsRuined())
			{
				fuel.AddQuantity(-1);
			}
		}
	}
	void IAT_ConsumeOres(string slotName, int wager)
	{
		ItemBase ore;
		if (Class.CastTo(ore, FindAttachmentBySlotName(slotName)))
		{
			int newQuantity;
			// this should fix any exploit nonsense with negative numbers
			newQuantity = Math.Max(1, Math.Floor(wager / 2));
			ore.AddQuantity(-newQuantity);
		}
	}
	void IAT_SpawnResults(string ore1, string ore2, int numBars)
	{
		// check to see if the ores in question are part of a recipe
		if (g_Game.IsDedicatedServer())
		{
			// default to a scrap bar, 100hp and 1 quantity
			string newClassName = "IAT_SmeltingIngot_Scrap";
			int resultHp = -1; // max hp
			int resultQuantity = numBars; // base bars
			// get the config
			IAT_SmeltingConfig smeltingConfig;
			if (GetDayZGame() && Class.CastTo(smeltingConfig, GetDayZGame().GetIATSmeltingConfig()))
			{
				IAT_SmeltingRecipe recipe;
				if (Class.CastTo(recipe, smeltingConfig.IAT_GetSmeltingRecipe(ore1, ore2, m_IAT_AccelerantMaxTemperature)))
				{
					newClassName = recipe.GetResultClassName();
					resultHp = recipe.GetResultHp();
					resultQuantity += recipe.GetResultQuantity();
				}
			}

			ItemBase alloy;
			if (Class.CastTo(alloy, g_Game.CreateObjectEx(newClassName, GetResultSpawnPosition(), ECE_SETUP|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY)))
			{
				// -1 means full hp
				if (resultHp == -1)
				{
					alloy.SetHealth(alloy.GetMaxHealth());
				}
				else
				{
					alloy.SetHealth(resultHp);
				}
				// -1 means full quantity
				if (resultQuantity == -1)
				{
					alloy.SetQuantity(alloy.GetQuantityMax());
				}
				else
				{
					alloy.SetQuantity(resultQuantity);
				}
			}
		}
	}
	void IAT_PlayCountDownSounds()
	{
		if (!g_Game.IsDedicatedServer())
		{
			if (m_CountDownSound)
			{
				StopSoundSet(m_CountDownSound);
			}
			PlaySoundSet(m_CountDownSound, "IAT_Smelting_MiniGame_CountDown_SoundSet", 1, 1);
		}
	}
	void IAT_SetMinMaxFurnaceTemperature()
	{
		// best case scenario, user attached bark first then coal etc
		ItemBase fuel;
		// accelerant takes priority
      	if (Class.CastTo(fuel, FindAttachmentBySlotName("IAT_Accelerant")))
		{
			m_IAT_HasAccelerantAttached = true;
			if (fuel.ConfigIsExisting("IAT_MinTemp"))
			{
				m_IAT_AccelerantMinTemperature = fuel.ConfigGetInt("IAT_MinTemp");
			}
			if (fuel.ConfigIsExisting("IAT_MaxTemp"))
			{
				m_IAT_AccelerantMaxTemperature = fuel.ConfigGetInt("IAT_MaxTemp");
			}
		}
		// bark is secondary
		else if (Class.CastTo(fuel, FindAttachmentBySlotName("Bark")))
		{
			// we know at this point no accelerant is attached and bark is not good enough for bigger smelting
			m_IAT_HasAccelerantAttached = false;
			if (fuel.ConfigIsExisting("IAT_MinTemp"))
			{
				m_IAT_AccelerantMinTemperature = fuel.ConfigGetInt("IAT_MinTemp");
			}
			if (fuel.ConfigIsExisting("IAT_MaxTemp"))
			{
				m_IAT_AccelerantMaxTemperature = fuel.ConfigGetInt("IAT_MaxTemp");
			}
		}
		// the default values
		else
		{
			m_IAT_HasAccelerantAttached = false;
			m_IAT_AccelerantMinTemperature = 15;
			m_IAT_AccelerantMaxTemperature = 500;

		}
		if (m_UTSLFireplace)
		{
			m_UTSLFireplace.SetSmallFireplaceTemperatureMax(m_IAT_AccelerantMaxTemperature);
			m_UTSLFireplace.SetNormalFireplaceTemperatureMax(m_IAT_AccelerantMaxTemperature);
		}
	}
	void IAT_LockOreSlots()
	{
		int slotId = InventorySlots.GetSlotIdFromString("IAT_Accelerant");
		GetInventory().SetSlotLock(slotId, true);

		slotId = InventorySlots.GetSlotIdFromString("IAT_RawOre1");
		GetInventory().SetSlotLock(slotId, true);

		slotId = InventorySlots.GetSlotIdFromString("IAT_RawOre2");
		GetInventory().SetSlotLock(slotId, true);
	}
	void IAT_UnlockOreSlots()
	{
		int slotId = InventorySlots.GetSlotIdFromString("IAT_Accelerant");
		GetInventory().SetSlotLock(slotId, false);

		slotId = InventorySlots.GetSlotIdFromString("IAT_RawOre1");
		GetInventory().SetSlotLock(slotId, false);

		slotId = InventorySlots.GetSlotIdFromString("IAT_RawOre2");
		GetInventory().SetSlotLock(slotId, false);
	}
	bool IAT_AreSlotsLocked()
	{
		if (!GetInventory().GetSlotLock( InventorySlots.GetSlotIdFromString( "IAT_Accelerant" )))
			return false;
		if (!GetInventory().GetSlotLock( InventorySlots.GetSlotIdFromString( "IAT_RawOre1" )))
			return false;
		if (!GetInventory().GetSlotLock( InventorySlots.GetSlotIdFromString( "IAT_RawOre2" )))
			return false;
		return true;
	}
	bool IAT_HasAccelerantAttached()
	{
		return m_IAT_HasAccelerantAttached;
	}
	bool IAT_HasOreAttached()
	{
		return m_IAT_HasOre1Attached || m_IAT_HasOre2Attached;
	}
	int IAT_GetMinTemperature()
	{
		return m_IAT_AccelerantMinTemperature;
	}
	int IAT_GetAccelerantHP()
	{
		ItemBase fuel;
		// accelerant takes priority
      	if (Class.CastTo(fuel, FindAttachmentBySlotName("IAT_Accelerant")))
		{
			int healthLevel = fuel.GetHealthLevel();
			if (healthLevel == GameConstants.STATE_PRISTINE)
			{
				return fuel.GetMaxHealth();
			}
			else if (healthLevel == GameConstants.STATE_WORN)
			{
				return fuel.GetMaxHealth() - (0.3 * fuel.GetMaxHealth());
			}
			else if (healthLevel == GameConstants.STATE_DAMAGED)
			{
				return fuel.GetMaxHealth() - (0.5 * fuel.GetMaxHealth());
			}
			else if (healthLevel == GameConstants.STATE_BADLY_DAMAGED)
			{
				return fuel.GetMaxHealth() - (0.7 * fuel.GetMaxHealth());
			}
			else
			{
				return 10;
			}
		}
		return -1;
	}
	int IAT_GetMaxTemperature()
	{
		return m_IAT_AccelerantMaxTemperature;
	}
	float IAT_GetMeanTemperature()
	{
		int difference = m_IAT_AccelerantMaxTemperature - m_IAT_AccelerantMinTemperature;
		float half = difference / 2;
		float mean = m_IAT_AccelerantMaxTemperature + half;
		return mean;
	}
	int IAT_GetMaxOreQuantity(int slot)
	{
		ItemBase ore;
		if (slot == 0)
		{
			if (Class.CastTo(ore, FindAttachmentBySlotName("IAT_RawOre1")))
			{
				return ore.GetQuantity();
			}
		}
		else if (slot == 1)
		{
			if (Class.CastTo(ore, FindAttachmentBySlotName("IAT_RawOre1")))
			{
				return ore.GetQuantity();
			}
		}
		return -1;
	}
	bool IAT_HasWagerOwner()
	{
		return m_IAT_CurrentUser != "";
	}
	bool IAT_IsCurrentUser(string playerId)
	{
		if (m_IAT_CurrentUser == playerId)
		{
			return true;
		}
		return false;
	}
	void IAT_SetCurrentUser(string playerId)
	{
		m_IAT_CurrentUser = playerId;
	}
	void IAT_ResetCurrentUser()
	{
		m_IAT_CurrentUser = "";
	}
	vector GetResultSpawnPosition(string selection = "spawn_position")
	{
		if(MemoryPointExists(selection))
		{
			vector position = GetMemoryPointPos(selection);
			return ModelToWorld(position);
		}
		return GetPosition();
	}
};

class IAT_SmeltingFurnace_BasicStone extends IAT_SmeltingFurnace_ColorBase
{
	protected ref EffectSound m_ValveManipulationSound;

	protected const string SOUND_NAME_VALVE_MANIPULATION = "WaterObjectUndergroundValve_SoundSet";
	protected const string SOUND_POSITION_MEMORY_POINT = "oven_point1";
	// 0=Down, 1=Up
	protected int m_IAT_LeverState = 0;
	protected int m_IAT_LeverStateClient = 0;

	void IAT_SmeltingFurnace_BasicStone()
	{
		RegisterNetSyncVariableInt("m_IAT_LeverState", 0, 8);
	}
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		IAT_UpdateFurnaceVisuals();
	}
	override bool HasTurnableValveBehavior()
	{
		return true;
	}
	override int GetTurnableValveIndex(int pComponentIndex)
	{
		string targetedValveName = GetActionComponentName(pComponentIndex);
		if (targetedValveName == "lever")
		{
			return 0;
		}
		return INDEX_NOT_FOUND;
	}
	override bool IsValveTurnable(int pValveIndex = 1)
	{
		return true;
	}
	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionTurnFurnaceValve);
		// special case. remove
		RemoveAction(IAT_ActionToggleFurnaceLock);
	}

	override bool IAT_CanOpenMiniGameMenu()
	{
		// this one can only show hte menu when lever is up
		if (super.IAT_CanOpenMiniGameMenu())
		{
			return IsLeverUp();
		}
		return false;
	}

	override void IAT_OpenMiniGameMenu()
	{
		// client only;
		if (!g_Game.IsDedicatedServer())
		{
			if (IsLeverUp())
			{
				g_Game.GetMission().OnItemUsed(this, g_Game.GetPlayer());
			}
		}
	}
	void IAT_UpdateFurnaceVisuals()
	{
		// if there was an actual change
		if (m_IAT_LeverState != m_IAT_LeverStateClient)
		{
			if (m_IAT_LeverState == 0)
			{
				LowerPour();
				TurnLeverCounterClockwise();
				PlayLeverSound();
			}
			else if (m_IAT_LeverState == 1)
			{
				RaisePour();
				TurnLeverClockwise();
				PlayLeverSound();
			}
			m_IAT_LeverStateClient = m_IAT_LeverState;
		}
	}

	void LowerPour()
	{
		SetAnimationPhase("pour", 0);
	}
	void RaisePour()
	{
		SetAnimationPhase("pour", 1);
	}
	void TurnLeverClockwise()
	{
		SetAnimationPhase("pourlever", 1);
	}
	void TurnLeverCounterClockwise()
	{
		SetAnimationPhase("pourlever", 0);
	}
	void PlayLeverSound()
	{
		if (!g_Game.IsDedicatedServer())
		{
			PlaySoundSet(m_ValveManipulationSound, SOUND_NAME_VALVE_MANIPULATION, 1, 0, false);
		}
	}
	void StopLeverSound()
	{
		if (!g_Game.IsDedicatedServer())
		{
			if (m_ValveManipulationSound)
			{
				StopSoundSet(m_ValveManipulationSound);
			}
		}
	}
	bool IsLeverUp()
	{
		return m_IAT_LeverState == 1;
	}

	void OnValveManipulationStart(int pValveIndex = 1)
	{
		if (g_Game.IsDedicatedServer())
		{
			// if the lever is up
			if (IsLeverUp())
			{
				// lower it
				m_IAT_LeverState = 0;
				IAT_UnlockOreSlots();
			}
			else
			{
				// raise it
				m_IAT_LeverState = 1;
				IAT_LockOreSlots();
			}
			SetSynchDirty();
		}
	}

	void OnValveManipulationEnd(int pValveIndex = 1)
	{
		if (g_Game.IsDedicatedServer())
		{
			SetSynchDirty();
		}
	}

	void OnValveManipulationCanceled(int pValveIndex)
	{
		if (g_Game.IsDedicatedServer())
		{
			// if the lever is up
			if (IsLeverUp())
			{
				// keep it up
				m_IAT_LeverState = 1;
			}
			else
			{
				// keep it down
				m_IAT_LeverState = 0;
			}
			SetSynchDirty();
		}
	}
};
class IAT_SmeltingFurnace_BasicBrick extends IAT_SmeltingFurnace_ColorBase{};
class IAT_SmeltingFurnace_AdvancedStone extends IAT_SmeltingFurnace_ColorBase{};
class IAT_SmeltingFurnace_Industrial extends IAT_SmeltingFurnace_ColorBase{};