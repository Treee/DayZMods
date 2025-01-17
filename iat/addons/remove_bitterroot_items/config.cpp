class CfgPatches
{
	class IAT_Remove_Bitterroot_Items
	{
		requiredAddons[] =
		{
			"Remnants_Beards",
			"Remnants_HeroBackpack",
			"Remnants_Mini14",
			"Remnants_Sako85Hunter",
			"Remnants_Immortal_Scope",
			"Remnants_Ammo_300WinMag",
			"MFClothing_Tops",
			"MFClothing_Vests",
			"GolfClub",
			"MF_Melee_Tomahawk",
			"MF_Books",
			"MF_Other_Folders",
			"MF_Items_Firearms_AR15",
			"MF_Items_Firearms_Banshee",
			"MF_Items_Firearms_Busjmaster",
			"MF_Items_Firearms_G12",
			"MF_Items_Firearms_HK416",
			"MF_Items_Firearms_HoneyBadger",
			"MF_Items_Firearms_M110K1",
			"MF_M40A1",
			"MF_Items_Firearms_M91A2",
			"MF_Items_Firearms_MAC11",
			"MF_MK12",
			"MF_MK18",
			"MF_Firearms_MP5",
			"MF_MP7",
			"MF_Items_Firearms_R700",
			"MF_Items_Firearms_Rattler",
			"MF_Items_Firearms_Savage",
			"MF_Items_Firearms_SBR300",
			"MF_Items_Firearms_SCAR",
			"MF_Sig552",
			"MF_Springfield1903",
			"MF_SR25",
			"MF_Items_Firearms_Ammunition_300",
			"MF_Items_Firearms_Ammunition_300Savage",
			"MF_Items_Firearms_Ammunition_46x30",
			"MF_Items_Firearms_Ammunition_65",
			"MF_Items_Attachments_LeopardMark5",
			"MF_Suppressor",
		};
	};
};

class CfgVehicles
{
	class Clothing;
	class PlateCarrierVest;
	class PoliceVest;
	class ItemBook;
	class BaseballBat;
	// class HockeyStick;
	class Hatchet;
	class ItemOptics_Base;
	class Box_Base;
	class ItemSuppressor;

	class Remnants_Beard1_Base;
	class Remnants_Beard1_Black : Remnants_Beard1_Base { scope = 0; };
	class Remnants_Beard1_Blonde : Remnants_Beard1_Base { scope = 0; };
	class Remnants_Beard1_Brown : Remnants_Beard1_Base { scope = 0; };
	class Remnants_Beard1_Lightbrown : Remnants_Beard1_Base { scope = 0; };
	class Remnants_Beard1_White : Remnants_Beard1_Base { scope = 0; };

	class Remnants_HeroBackpack_Base;
	class Remnants_HeroBackpack : Remnants_HeroBackpack_Base { scope = 0; };
	class Remnants_HeroBackpack_Black : Remnants_HeroBackpack_Base { scope = 0; };

	class Remnants_Immortal_Scope : ItemOptics_Base { scope = 0; };

	class MF_LeopardMark5HD_Optic : ItemOptics_Base { scope = 0; };

	class Remnants_UniversalAmmobox;
	class Remnants_Ammobox_300WinMag : Remnants_UniversalAmmobox { scope = 0; };

	class MF_Book_Revelations : ItemBook { scope = 0; };

	class MF_Folder_Base;
	class MF_Folder_Red : MF_Folder_Base { scope = 0; };
	class MF_Folder_Yellow : MF_Folder_Base { scope = 0; };

	class MF_GolfClub : BaseballBat { scope = 0; };

	// class MF_GolfClub : HockeyStick { scope = 0; };

	class MF_Tomahawk : Hatchet { scope = 0; };

	class M1903Optic : ItemOptics_Base { scope = 0; };

	class MF_AmmoBox_300BLK_20Rnd : Box_Base { scope = 0; };
	class MF_AmmoBox_300BLK_AP_20Rnd : Box_Base { scope = 0; };

	class MF_AmmoBox_300Savage_20Rnd : Box_Base { scope = 0; };

	class MF_AmmoBox_46x30AP_20Rnd : Box_Base { scope = 0; };

	class MF_AmmoBox_65Creedmoor_20Rnd : Box_Base { scope = 0; };

	class MF_MK12Suppressor : ItemSuppressor { scope = 0; };

};

class CfgWeapons
{
	class Remnants_Mini14_Base;
	class Remnants_Mini14 : Remnants_Mini14_Base { scope = 0; };

	class Remnants_Sako85Hunter_Base;
	class Remnants_Sako85Hunter_Wood : Remnants_Sako85Hunter_Base { scope = 0; };
	class Remnants_Sako85Hunter_Plastic : Remnants_Sako85Hunter_Base { scope = 0; };

	class MF_AR15_Base;
	class MF_AR15 : MF_AR15_Base { scope = 0; };

	class MF_Banshee_Base;
	class MF_Banshee : MF_Banshee_Base { scope = 0; };

	class MF_Bushmaster_Base;
	class MF_Bushmaster : MF_Bushmaster_Base { scope = 0; };

	class MF_G12_Base;
	class MF_G12 : MF_G12_Base { scope = 0; };

	class MF_HK416_Base;
	class MF_HK416 : MF_HK416_Base { scope = 0; };
	class MF_HK416_Tan : MF_HK416_Base { scope = 0; };

	class MF_HoneyBadger_Base;
	class MF_HoneyBadger_Black : MF_HoneyBadger_Base { scope = 0; };
	class MF_HoneyBadger_Tan : MF_HoneyBadger_Base { scope = 0; };

	class MF_M110K1_Base;
	class MF_M110K1 : MF_M110K1_Base { scope = 0; };

	class MF_M40A1_Base;
	class MF_M40A1 : MF_M40A1_Base { scope = 0; };
	class MF_M40A1_Green : MF_M40A1_Base { scope = 0; };
	class MF_M40A1_Digital : MF_M40A1_Base { scope = 0; };

	class MF_M91A2_Base;
	class MF_M91A2_Tan : MF_M91A2_Base { scope = 0; };
	class MF_M91A2_Black : MF_M91A2_Base { scope = 0; };
	class MF_M91A2_Green : MF_M91A2_Base { scope = 0; };

	class MF_MAC11_Base;
	class MF_MAC11 : MF_MAC11_Base { scope = 0; };

	class MF_MK12_Base;
	class MF_MK12 : MF_MK12_Base { scope = 0; };

	class MF_MK18_Base;
	class MF_MK18 : MF_MK18_Base { scope = 0; };

	class MF_MP5SDA2_Base;
	class MF_MP5SDA2 : MF_MP5SDA2_Base { scope = 0; };
	class MF_MP5SDA2_FDE : MF_MP5SDA2 { scope = 0; };

	class MF_MP7_Base;
	class MF_MP7 : MF_MP7_Base { scope = 0; };

	class MF_R700_Base;
	class MF_R700 : MF_R700_Base { scope = 0; };

	class MF_Rattler_Base;
	class MF_Rattler : MF_Rattler_Base { scope = 0; };

	class MF_Savage_Base;
	class MF_Savage : MF_Savage_Base { scope = 0; };

	class MF_SBR300_Base;
	class MF_SBR300 : MF_SBR300_Base { scope = 0; };

	class MF_SCAR_Base;
	class MF_SCAR : MF_SCAR_Base { scope = 0; };

	class MF_Sig552_Base;
	class MF_Sig552 : MF_Sig552_Base { scope = 0; };

	class MF_Springfield1903_Base;
	class MF_Springfield1903 : MF_Springfield1903_Base { scope = 0; };

	class MF_Woodsmaster_Base;
	class MF_Woodsmaster : MF_Woodsmaster_Base { scope = 0; };

	class MF_SR25_Base;
	class MF_SR25 : MF_SR25_Base { scope = 0; };
};

class CfgMagazines
{
	class Ammunition_Base;
	class Magazine_Base;

	class Remnants_Mini14_Mag_Base;
	class Remnants_Mini14_Mag : Remnants_Mini14_Mag_Base { scope = 0; };

	class Remnants_Ammo_300WinMag : Ammunition_Base { scope = 0; };

	class MF_Mag_AR15_30rnd : Magazine_Base { scope = 0; };
	class MF_Mag_Banshee_25rnd : Magazine_Base { scope = 0; };

	class MF_Mag_G12_10Rnd : Magazine_Base { scope = 0; };

	class MF_Mag_HoneyBadger_30rnd : Magazine_Base { scope = 0; };

	class MF_Mag_M110K1_10rnd : Magazine_Base { scope = 0; };
	class MF_Mag_M110K1_20rnd : Magazine_Base { scope = 0; };

	class MF_Mag_MAC11_25rnd : Magazine_Base { scope = 0; };

	class MF_Mag_MK12_20rnd : Magazine_Base { scope = 0; };

	class MF_Mag_MP5_30rnd : Magazine_Base { scope = 0; };
	class MF_Mag_MP5_50rnd : Magazine_Base { scope = 0; };

	class MF_Mag_MP7_40rnd : Magazine_Base { scope = 0; };

	class MF_Mag_Rattler_30rnd : Magazine_Base { scope = 0; };

	class MF_Mag_SBR300_10rnd : Magazine_Base { scope = 0; };

	class MF_Mag_SCAR_20rnd : Magazine_Base { scope = 0; };

	class MF_Mag_Sig552_30rnd : Magazine_Base { scope = 0; };

	class MF_Mag_SR25_20rnd : Magazine_Base { scope = 0; };

	class MF_Ammo_300BLK : Ammunition_Base { scope = 0; };
	class MF_Ammo_300BLK_AP : Ammunition_Base { scope = 0; };

	class MF_Ammo_300Savage : Ammunition_Base { scope = 0; };

	class MF_Ammo_46x30AP : Ammunition_Base { scope = 0; };

	class MF_Ammo_65Creedmoor : Ammunition_Base { scope = 0; };
};