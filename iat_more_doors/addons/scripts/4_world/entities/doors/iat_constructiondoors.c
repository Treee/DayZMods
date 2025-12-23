//========================= CONSTRUCTION DOORS
class IAT_ConstructionDoor_Colorbase extends ItemBase
{
	protected const int DOOR_ROTATION_TIME_APPROX			= 2000;		//ms

	protected const string ATTACHMENT_SLOT_COMBINATION_LOCK 	= "Att_CombinationLock";
	protected const string FIRST_DOOR_ANIMATION               = "DoorRotate1";
	protected const string SECOND_DOOR_ANIMATION              = "DoorRotate2";
	protected const string SELECTION_INTERACT_DOOR1 = "door1";
	protected const string SELECTION_INTERACT_DOOR2 = "door2";

	// server side synced variables
	protected bool m_IsDoor1Open;
	protected bool m_IsDoor2Open;

	protected EffectSound m_SoundDoor_Start;
	protected EffectSound m_SoundDoor_End;

	void IAT_ConstructionDoor_Colorbase()
	{
		// register netsyncs
		RegisterNetSyncVariableBool("m_IsDoor1Open");
		RegisterNetSyncVariableBool("m_IsDoor2Open");
	}
	//======================================================= VANILLA
	override void SetActions()
	{
		super.SetActions();
		// enscript-suppress
		AddAction(IAT_ActionOpenConstructionDoor);
		// enscript-suppress
		AddAction(IAT_ActionCloseConstructionDoor);
	}
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		// client side door logic

		if (IsSingleDoor())
		{
			if (IsDoor1Open())
			{
				OpenDoor1();
			}
			else
			{
				CloseDoor1();
			}
		}
		else if (IsDoubleDoor())
		{
			if (IsDoor1Open())
			{
				OpenDoor1();
			}
			else
			{
				CloseDoor1();
			}
			if (IsDoor2Open())
			{
				OpenDoor2();
			}
			else
			{
				CloseDoor2();
			}
		}
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
	// override int GetMeleeTargetType()
	// {
	// 	return EMeleeTargetType.NONALIGNABLE;
	// }
	protected void UpdateNavmesh()
	{
		// update door path graph for AI
		SetAffectPathgraph( true, false );
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 100, false, this );
	}
	protected void SoundDoorOpenStart()
	{
		//client or single player
		if ( !GetGame().IsDedicatedServer() )
		{
			PlaySoundSet( m_SoundDoor_Start, GetDoorOpenStartSoundSet(), 0.1, 0.1 );
		}
	}
	protected void SoundDoorCloseStart()
	{
		//client or single player
		if ( !GetGame().IsDedicatedServer() )
		{
			PlaySoundSet( m_SoundDoor_Start, GetDoorCloseStartSoundSet(), 0.1, 0.1 );
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( SoundDoorCloseEnd, DOOR_ROTATION_TIME_APPROX, false );
		}
	}
	protected void SoundDoorCloseEnd()
	{
		//client or single player
		if ( !GetGame().IsDedicatedServer() )
		{
			PlaySoundSet( m_SoundDoor_End, GetDoorCloseEndSoundSet(), 0.1, 0.1 );
		}
	}

	//======================================================= CUSTOM CODE
	void UpdateDoor1Visuals(int phase = 0)
	{
		SetAnimationPhase(FIRST_DOOR_ANIMATION, phase);
	}
	void UpdateDoor2Visuals(int phase = 0)
	{
		SetAnimationPhase(SECOND_DOOR_ANIMATION, phase);
	}
	void OpenDoor(string componentName) // server only
	{
		if (GetGame().IsDedicatedServer())
		{
			if (componentName == SELECTION_INTERACT_DOOR1)
			{
				OpenDoor1();
			}
			else if (componentName == SELECTION_INTERACT_DOOR2)
			{
				OpenDoor2();
			}
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdateNavmesh, DOOR_ROTATION_TIME_APPROX, false );
		}
	}
	void OpenDoor1() // client/server
	{
		SetDoor1Open(true);
		UpdateDoor1Visuals(1);
		SetSynchDirty();

		// client only
		if (!GetGame().IsDedicatedServer())
		{
			SoundDoorOpenStart();
		}
	}
	void OpenDoor2()
	{
		SetDoor2Open(true);
		UpdateDoor2Visuals(1);
		SetSynchDirty();

		// client only
		if (!GetGame().IsDedicatedServer())
		{
			SoundDoorOpenStart();
		}
	}
	void CloseDoor(string componentName)
	{
		if (GetGame().IsDedicatedServer())
		{
			if (componentName == SELECTION_INTERACT_DOOR1)
			{
				CloseDoor1();
			}
			else if (componentName == SELECTION_INTERACT_DOOR2)
			{
				CloseDoor2();
			}
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdateNavmesh, DOOR_ROTATION_TIME_APPROX, false );
		}
	}
	void CloseDoor1()
	{
		SetDoor1Open(false);
		UpdateDoor1Visuals(0);
		SetSynchDirty();

		// client only
		if (!GetGame().IsDedicatedServer())
		{
			SoundDoorCloseStart();
		}
	}
	void CloseDoor2()
	{
		SetDoor2Open(false);
		UpdateDoor2Visuals(0);
		SetSynchDirty();

		// client only
		if (!GetGame().IsDedicatedServer())
		{
			SoundDoorCloseStart();
		}
	}
	bool CanOpenDoor(PlayerIdentity invokingPlayer, string componentName)
	{
		// doors already open cannot be opened
		if (IsSingleDoor())
		{
			if (IsDoor1Open())
			{
				return false;
			}
		}
		if (IsDoubleDoor())
		{
			if (componentName == SELECTION_INTERACT_DOOR1)
			{
				if (IsDoor1Open())
				{
					return false;
				}
			}
			if (componentName == SELECTION_INTERACT_DOOR2)
			{
				if (IsDoor2Open())
				{
					return false;
				}
			}
		}
		if (IsLocked(invokingPlayer))
		{
			return false;
		}
		return true;
	}
	bool CanCloseDoor(string componentName)
	{
		// doors already closed cannot be closed
		if (IsSingleDoor())
		{
			if (!IsDoor1Open())
			{
				return false;
			}
		}
		if (IsDoubleDoor())
		{
			if (componentName == SELECTION_INTERACT_DOOR1)
			{
				if (!IsDoor1Open())
				{
					return false;
				}
			}
			if (componentName == SELECTION_INTERACT_DOOR2)
			{
				if (!IsDoor2Open())
				{
					return false;
				}
			}
		}
		return true;
	}
	bool IsLocked(PlayerIdentity invokingPlayer)
	{
		// IAT CODELOCK COMPATIBILITY
		#ifdef IAT_Codelock
		IAT_Codelock_Colorbase iatCodelock;
		if (Class.CastTo(iatCodelock, GetCombinationLock_IAT()))
		{
			// if the codelock is actually locked
			if (iatCodelock.IAT_IsLocked())
			{
				// if the player performing the action has access
				if (iatCodelock.HasAccess(invokingPlayer))
				{
					return false;
				}
				return true;
			}
		}
		#endif

		// EXPANSION COMPATIBILITY
		#ifdef EXPANSIONMODBASEBUILDING
		ExpansionCodeLock expansionCodelock;
		if (Class.CastTo(expansionCodelock, ExpansionGetCodeLock()))
		{
			if (ExpansionIsLocked())
			{
				if (IsKnownUser(invokingPlayer.GetPlayer()))
				{
					return false;
				}
			}
			return true;
		}
		#endif

		// VANILLA CODELOCK
		CombinationLock combination_lock;
		if (Class.CastTo(combination_lock, GetCombinationLock_Vanilla()))
		{
			if (combination_lock.IsLocked())
			{
				return true;
			}
		}

		return false;
	}

	#ifdef IAT_Codelock
	// special override for our codelock
	override bool CanAttachCodelockToObject()
	{
		return true;
	}
	#endif

	bool CanDismantleDoor()
	{
		// if anything is attached to the door, cannot dismantle
		if (GetCombinationLock_Vanilla())
		{
			return false;
		}
		#ifdef IAT_Codelock
		if (GetCombinationLock_IAT())
		{
			return false;
		}
		#endif

		return true;
	}

	//======================================================= SETTERS & GETTERS
	CombinationLock GetCombinationLock_Vanilla()
	{
		CombinationLock combination_lock;
		if (Class.CastTo(combination_lock, FindAttachmentBySlotName(ATTACHMENT_SLOT_COMBINATION_LOCK)))
		{
			return combination_lock;
		}
		return null;
	}
	#ifdef IAT_Codelock
	IAT_Codelock_Colorbase GetCombinationLock_IAT()
	{
		IAT_Codelock_Colorbase combination_lock;
		if (Class.CastTo(combination_lock, FindAttachmentBySlotName(ATTACHMENT_SLOT_COMBINATION_LOCK)))
		{
			return combination_lock;
		}
		return null;
	}
	#endif

	bool IsDoor1Open()
	{
		return m_IsDoor1Open;
	}
	void SetDoor1Open(bool value)
	{
		m_IsDoor1Open = value;
	}
	bool IsDoor2Open()
	{
		return m_IsDoor2Open;
	}
	void SetDoor2Open(bool value)
	{
		m_IsDoor2Open = value;
	}
	bool IsSingleDoor()
	{
		return false;
	}
	bool IsDoubleDoor()
	{
		return false;
	}
	string GetDoorOpenStartSoundSet()
	{
		return "DoorWoodTowerOpen_SoundSet";
	}
	string GetDoorCloseStartSoundSet()
	{
		return "DoorWoodTowerClose_start_SoundSet";
	}
	string GetDoorCloseEndSoundSet()
	{
		return "DoorWoodTowerClose_end_SoundSet";
	}
};

class IAT_ConstructionDoor_Single_Colorbase extends IAT_ConstructionDoor_Colorbase
{
	override bool IsSingleDoor()
	{
		return true;
	}
};
class IAT_ConstructionDoor_Double_Colorbase extends IAT_ConstructionDoor_Colorbase
{
	override bool IsDoubleDoor()
	{
		return true;
	}
};

class IAT_ConstructionDoor_Single_Left_Wooden extends IAT_ConstructionDoor_Single_Colorbase{};
class IAT_ConstructionDoor_Single_Right_Wooden extends IAT_ConstructionDoor_Single_Colorbase{};

class IAT_ConstructionDoor_Single_Left_WoodenLargeHatch extends IAT_ConstructionDoor_Single_Colorbase{};
class IAT_ConstructionDoor_Single_Right_WoodenLargeHatch extends IAT_ConstructionDoor_Single_Colorbase{};

class IAT_ConstructionDoor_Single_Left_Metal extends IAT_ConstructionDoor_Single_Colorbase
{
	override string GetDoorOpenStartSoundSet()
	{
		return "IAT_Door_MetalSmallOpen_SoundSet";
	}
};
class IAT_ConstructionDoor_Single_Right_Metal extends IAT_ConstructionDoor_Single_Colorbase
{
	override string GetDoorOpenStartSoundSet()
	{
		return "IAT_Door_MetalSmallOpen_SoundSet";
	}
};
class IAT_ConstructionDoor_Single_Left_Iron extends IAT_ConstructionDoor_Single_Colorbase
{
	override string GetDoorOpenStartSoundSet()
	{
		return "IAT_Door_MetalContainerOpen_SoundSet";
	}
};
class IAT_ConstructionDoor_Single_Right_Iron extends IAT_ConstructionDoor_Single_Colorbase
{
	override string GetDoorOpenStartSoundSet()
	{
		return "IAT_Door_MetalContainerOpen_SoundSet";
	}
};
class IAT_ConstructionDoor_Double_Wooden extends IAT_ConstructionDoor_Double_Colorbase{};
class IAT_ConstructionDoor_Double_WoodenHatch extends IAT_ConstructionDoor_Double_Colorbase{};
class IAT_ConstructionDoor_Double_Metal extends IAT_ConstructionDoor_Double_Colorbase
{
	override string GetDoorOpenStartSoundSet()
	{
		return "IAT_Door_MetalSmallOpen_SoundSet";
	}
};
class IAT_ConstructionDoor_Double_Iron extends IAT_ConstructionDoor_Double_Colorbase
{
	override string GetDoorOpenStartSoundSet()
	{
		return "IAT_Door_MetalContainerOpen_SoundSet";
	}
};

class IAT_ConstructionDoor_Double_WoodenMedium extends IAT_ConstructionDoor_Double_Colorbase{};
class IAT_ConstructionDoor_Double_MetalMedium extends IAT_ConstructionDoor_Double_Colorbase
{
	override string GetDoorOpenStartSoundSet()
	{
		return "IAT_Door_MetalSmallOpen_SoundSet";
	}
};
class IAT_ConstructionDoor_Double_IronMedium extends IAT_ConstructionDoor_Double_Colorbase
{
	override string GetDoorOpenStartSoundSet()
	{
		return "IAT_Door_MetalContainerOpen_SoundSet";
	}
};
