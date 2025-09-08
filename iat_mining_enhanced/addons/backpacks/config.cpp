class CfgPatches
{
	class IAT_Mining_Backpacks
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Characters_Backpacks" };
	};
};
class CfgVehicles
{
	class Clothing;

	class IAT_LogBackpack_ColorBase : Clothing
	{
		scope = 0;
		displayName = "Log Backpack";
		descriptionShort = "A backpack meant for carrying several logs and firewood at one time.";
		model = "iat_mining_enhanced\backpacks\iat_logbackpack_g.p3d";
		debug_ItemCategory = 9;
		inventorySlot[] = { "Back" };
		attachments[] = { "Material_FPole_WoodenLog2", "Firewood", "WoodenStick", "Bark" };
		itemInfo[] = { "Clothing", "Back" };
		rotationFlags = 16;
		itemSize[] = { 12, 12 };
		itemsCargoSize[] = { 3, 2 };
		weight = 1600;
		varWetMax = 0.79;
		heatIsolation = 0.8;
		soundAttType = "Military";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\backpacks\data\iat_logbackpack_co.paa" };
		class ClothingTypes
		{
			male = "iat_mining_enhanced\backpacks\iat_logbackpack_m.p3d";
			female = "iat_mining_enhanced\backpacks\iat_logbackpack_m.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 160;
					transferToAttachmentsCoef = 0.5;
					healthLevels[] =
					{
						{1, {"iat_mining_enhanced\backpacks\data\iat_logbackpack.rvmat"}},
						{0.7, {"iat_mining_enhanced\backpacks\data\iat_logbackpack.rvmat"}},
						{0.5, {"iat_mining_enhanced\backpacks\data\iat_logbackpack_damage.rvmat"}},
						{0.3, {"iat_mining_enhanced\backpacks\data\iat_logbackpack_damage.rvmat"}},
						{0, {"iat_mining_enhanced\backpacks\data\iat_logbackpack_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpBackPack_Metal_Light_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpBackPack_Metal_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "taloonbag_drop_SoundSet";
					id = 898;
				};
			};
		};
	};

	class IAT_LogBackpack_Basic : IAT_LogBackpack_ColorBase
	{
		scope = 2;
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\backpacks\data\iat_logbackpack_co.paa" };
	};
};