class CfgPatches
{
	class IAT_Universal_Dye_Characters_Backpacks
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Backpacks"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class TaloonBag_ColorBase : Clothing
	{
		rootClassName = "TaloonBag";
		colorVariants[] =
		{
			"Blue",
			"Green",
			"Orange",
			"Violet",
			"Black1",
			"Black2"
		};
	};
	class TortillaBag : Clothing
	{
		rootClassName = "TortillaBag";
		colorVariants[] =
		{
			"MTP",
			"ATAC",
			"ATACSFG",
			"USNAOR1",
			"USNAOR2",
			"SURPAT",
			"MARPATWinter",
			"EMP6",
		};
	};
	class CourierBag : Clothing
	{
		rootClassName = "CourierBag";
		colorVariants[] =
		{
		  "Black",
		};
	};
	class DryBag_ColorBase : Clothing
	{
		rootClassName = "DryBag";
		colorVariants[] =
		{
		  "Orange",
		  "Yellow",
		  "Blue",
		  "Green",
		  "Black",
		  "Red",
		  "Pink",
		  "MintBlue",
		  "Camo",
		  "ChernaRussian",
		  "NordicStripe",
		  "Soviet",
		  "UnionJack",
		};
	};
	class HuntingBag : Clothing
	{
		rootClassName = "HuntingBag";
		colorVariants[] =
		{
		  "Hannah",
		  "Black",
		  "Gorka",
		  "MTP",
		  "ATAC",
		  "ATACSFG",
		  "USNAOR1",
		  "USNAOR2",
		  "SURPAT",
		  "MARPATWinter",
		  "EMP6",
		  "Blue",
		  "Red",
		  "Yellow",
		  "Travel",
		};
	};
	class MountainBag_ColorBase : Clothing
	{
		rootClassName = "MountainBag";
		colorVariants[] =
		{
		  "Red",
		  "Blue",
		  "Orange",
		  "Green",
		  "Black",
		  "MTP",
		  "ATAC",
		  "ATACSFG",
		  "USNAOR1",
		  "USNAOR2",
		  "SURPAT",
		  "MARPATWinter",
		  "EMP6",
		  "Survivor1",
		  "Survivor2",
		  "Survivor3",
		  "Survivor4"
		};
	};
	class SmershBag : Clothing
	{
		rootClassName = "SmershBag";
		colorVariants[] =
		{
		  "White",
		  "Black",
		  "Green",
		  "Tan",
		  "NBC",
		  "Red",
		  "Purple",
		  "Blue",
		  "Pink",
		  "Olive",
		  "Storm",
		};
	};
	class ChildBag_ColorBase : Clothing
	{
		rootClassName = "ChildBag";
		colorVariants[] =
		{
		  "Green",
		  "Red",
		  "Blue",
		};
	};
	class GhillieBushrag_ColorBase : Clothing
	{
		rootClassName = "GhillieBushrag";
		colorVariants[] =
		{
		  "Tan",
		  "Woodland",
		  "Orange",
		  "Mossy",
		  "Winter",
		  "White",
		  "Black"
		};
	};
	class GhillieTop_ColorBase : Clothing
	{
		rootClassName = "GhillieTop";
		colorVariants[] =
		{
		  "Tan",
		  "Woodland",
		  "Orange",
		  "Mossy",
		  "Winter",
		  "White",
		  "Black"
		};
	};
	class GhillieSuit_ColorBase : Clothing
	{
		rootClassName = "GhillieSuit";
		colorVariants[] =
		{
		  "Tan",
		  "Woodland",
		  "Orange",
		  "Mossy",
		  "Winter",
		  "White",
		  "Black"
		};
	};
	class LeatherSack_ColorBase : Clothing
	{
		rootClassName = "LeatherSack";
		colorVariants[] =
		{
		  "Natural",
		  "Black",
		  "Beige",
		  "Brown",
		};
	};
	class AssaultBag_ColorBase : Clothing
	{
		rootClassName = "AssaultBag";
		colorVariants[] =
		{
		  "Ttsko",
		  "Black",
		  "Green",
		  "Denim",
		  "MTP",
		  "ATAC",
		  "ATACSFG",
		  "USNAOR1",
		  "USNAOR2",
		  "SURPAT",
		  "MARPATWinter",
		  "EMP6",
		};
	};
	class CoyoteBag_ColorBase : Clothing
	{
		rootClassName = "CoyoteBag";
		colorVariants[] =
		{
		  "Brown",
		  "Green"
		};
	};
	class AliceBag_ColorBase : Clothing
	{
		rootClassName = "AliceBag";
		colorVariants[] =
		{
		  "Green",
		  "Black",
		  "Camo",
		  "Camo1",
		  "MTP",
		  "ATAC",
		  "ATACSFG",
		  "USNAOR1",
		  "USNAOR2",
		  "SURPAT",
		  "MARPATWinter",
		  "EMP6",
		};
	};
	class SlingBag_ColorBase : Clothing
	{
		rootClassName = "SlingBag";
		colorVariants[] =
		{
		  "Brown",
		  "Gray",
		  "Black",
		};
	};
	class ArmyPouch_ColorBase : Clothing
	{
		rootClassName = "ArmyPouch";
		colorVariants[] =
		{
		  "Beige",
		  "Black",
		  "Camo",
		  "Green",
		  "Drugs",
		  "Grenade",
		  "Kitty",
		  "Meat",
		  "Tomato",
		};
	};
	class DuffelBagSmall_ColorBase : Clothing
	{
		rootClassName = "DuffelBagSmall";
		colorVariants[] =
		{
		  "Green",
		  "Camo",
		  "Medical",
		};
	};
	class CanvasBag_ColorBase : Clothing
	{
		rootClassName = "CanvasBag";
		colorVariants[] =
		{
		  "Olive",
		  "Medical",
		  "WaldoRescue",
		};
	};
	class DrysackBag_ColorBase : Clothing
	{
		rootClassName = "DrysackBag";
		colorVariants[] =
		{
		  "Green",
		  "Orange",
		  "Yellow",
		};
	};
};