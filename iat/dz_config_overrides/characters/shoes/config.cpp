class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Characters_Shoes
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Shoes"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class AthleticShoes_ColorBase : Clothing
	{
		itemSize[] = { 2,2 };
	};
	class HikingBoots_ColorBase : Clothing
	{
		soundAttType = "Boots";
		itemSize[] = { 2,2 };
		attachments[] += { "IAT_Weapon_Derringer" };
	};
	class HikingBootsLow_ColorBase : Clothing
	{
		itemSize[] = { 2,2 };
	};
	class Wellies_ColorBase : Clothing
	{
		itemSize[] = { 2,2 };
		attachments[] += { "IAT_Weapon_Derringer" };
	};
	class WorkingBoots_ColorBase : Clothing
	{
		itemSize[] = { 2,2 };
	};
	class JungleBoots_ColorBase : Clothing
	{
		itemSize[] = { 2,2 };
		attachments[] += { "IAT_Weapon_Derringer" };
	};
	class DressShoes_ColorBase : Clothing
	{
		itemSize[] = { 2,2 };
	};
	class MilitaryBoots_ColorBase : Clothing
	{
		itemSize[] = { 2,2 };
		attachments[] += { "IAT_Weapon_Derringer" };
	};
	class CombatBoots_ColorBase : Clothing
	{
		itemSize[] = { 2,2 };
	};
	class JoggingShoes_ColorBase : Clothing
	{
		itemSize[] = { 2,2 };
	};
	class LeatherShoes_ColorBase : Clothing
	{
		itemSize[] = { 2,2 };
	};
	class Sneakers_ColorBase : Clothing
	{
		itemSize[] = { 2,2 };
	};
	class Ballerinas_ColorBase : Clothing
	{
		itemSize[] = { 2,2 };
	};
	class NBCBootsBase : Clothing
	{
		soundAttType = "Sneakers";
	};
	class TTSKOBoots : Clothing
	{
		soundAttType = "Boots";
		attachments[] += { "IAT_Weapon_Derringer" };
	};
};