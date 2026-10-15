class CfgPatches
{
	class IAT_DZ_ALV_Gear_ConfigOverrides_Gear_Drinks
	{
		requiredAddons[] = { "SRP_ALV_Gear_Drinks" };
	};
};
class CfgVehicles
{
	class ALV_MetalCup;

	//==================================================== VANILLA OVERRIDE
	class ALV_MetalCup_Healing: ALV_MetalCup
	{
		varLiquidTypeInit=512;
		liquidContainerType="513";
	};
	class ALV_MetalCup_CharcoalTablets: ALV_MetalCup
	{
		varLiquidTypeInit=512;
		liquidContainerType="513";
	};
	class ALV_MetalCup_Tetra: ALV_MetalCup
	{
		varLiquidTypeInit=512;
		liquidContainerType="513";
	};
	class ALV_MetalCup_MultiVitamins: ALV_MetalCup
	{
		varLiquidTypeInit=512;
		liquidContainerType="513";
	};
	class ALV_MetalCup_Metabilism: ALV_MetalCup
	{
		varLiquidTypeInit=512;
		liquidContainerType="513";
	};
	class ALV_MetalCup_Coffee: ALV_MetalCup
	{
		varLiquidTypeInit=512;
		liquidContainerType="513";
	};
	class ALV_MetalCup_Cholera: ALV_MetalCup
	{
		varLiquidTypeInit=512;
		liquidContainerType="513";
	};
	class ALV_MetalCup_Poison: ALV_MetalCup
	{
		varLiquidTypeInit=512;
		liquidContainerType="513";
	};
};