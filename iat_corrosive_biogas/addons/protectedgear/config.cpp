class CfgPatches
{
	class IAT_Corrosive_BioGas_ProtectedGear
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Characters_Backpacks", "DZ_Gear_Containers", "DZ_Characters_Pants", "DZ_Characters_Tops" };
	};
};
class CfgVehicles
{
	class Clothing;
	class Container_Base;
	// Backpacks
	class DryBag_ColorBase : Clothing
	{
		class Protection
		{
			corrosion = 1;
		};
	};

	// Tops
	class NBCJacketBase : Clothing
	{
		class Protection
		{
			corrosion = 1;
		};
	};

	// Pants
	class NBCPantsBase : Clothing
	{
		class Protection
		{
			corrosion = 1;
		};
	};

	// Containers
	class SmallProtectorCase : Container_Base
	{
		class Protection
		{
			corrosion = 1;
		};
	};
	class WaterproofBag_ColorBase : Container_Base
	{
		class Protection
		{
			corrosion = 1;
		};
	};
	class ScientificBriefcase : Container_Base
	{
		class Protection
		{
			corrosion = 1;
		};
	};
};