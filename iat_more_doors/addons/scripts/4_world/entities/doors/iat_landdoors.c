//========================= LAND DOORS
// these doors are land doors for map baking and scope 1
class IAT_LandDoor_Colorbase extends House
{
	protected const string ATTACHMENT_SLOT_COMBINATION_LOCK 	= "Att_CombinationLock";

	override bool IsInventoryVisible()
	{
		if (HasCodelockAttached())
			return true;

		return false;
	}
	override bool IsHealthVisible()
	{
		return false;
	}

	//======================================================= CUSTOM CODE
	bool HasCodelockAttached()
	{
		// IAT CODELOCK COMPATIBILITY
		#ifdef IAT_Codelock
		IAT_Codelock_Colorbase iatCodelock;
		if (Class.CastTo(iatCodelock, GetCombinationLock_IAT()))
		{
			return true;
		}
		#endif

		// EXPANSION COMPATIBILITY
		// #ifdef EXPANSIONMODBASEBUILDING
		// ExpansionCodeLock expansionCodelock;
		// if (Class.CastTo(expansionCodelock, GetCombinationLock_Expansion()))
		// {
		// 	return true;
		// }
		// #endif

		// VANILLA CODELOCK
		CombinationLock combination_lock;
		if (Class.CastTo(combination_lock, GetCombinationLock_Vanilla()))
		{
			return true;
		}
		return false;
	}

	//======================================================= SETTERS & GETTERS
	CombinationLock GetCombinationLock_Vanilla()
	{
		CombinationLock combination_lock;
		if (FindAttachmentBySlotName(ATTACHMENT_SLOT_COMBINATION_LOCK))
		{
			return combination_lock;
		}
		return null;
	}
	#ifdef IAT_Codelock
	IAT_Codelock_Colorbase GetCombinationLock_IAT()
	{
		IAT_Codelock_Colorbase combination_lock;
		if (FindAttachmentBySlotName(ATTACHMENT_SLOT_COMBINATION_LOCK))
		{
			return combination_lock;
		}
		return null;
	}
	#endif
};

class IAT_LandDoor_SingleDoor_Colorbase extends IAT_LandDoor_Colorbase{};
class IAT_LandDoor_DoubleDoor_Colorbase extends IAT_LandDoor_Colorbase{};

class land_iat_singledoor_left_wooden extends IAT_LandDoor_SingleDoor_Colorbase{};
class land_iat_singledoor_right_wooden extends IAT_LandDoor_SingleDoor_Colorbase{};
class land_iat_singledoor_left_metal extends IAT_LandDoor_SingleDoor_Colorbase{};
class land_iat_singledoor_right_metal extends IAT_LandDoor_SingleDoor_Colorbase{};
class land_iat_singledoor_left_iron extends IAT_LandDoor_SingleDoor_Colorbase{};
class land_iat_singledoor_right_iron extends IAT_LandDoor_SingleDoor_Colorbase{};

class land_iat_doubledoor_wooden extends IAT_LandDoor_DoubleDoor_Colorbase{};
class land_iat_doubledoor_metal extends IAT_LandDoor_DoubleDoor_Colorbase{};
class land_iat_doubledoor_iron extends IAT_LandDoor_DoubleDoor_Colorbase{};
