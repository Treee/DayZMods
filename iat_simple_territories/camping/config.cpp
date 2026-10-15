class CfgPatches
{
	class IAT_Simple_Territories_Camping
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Camping" };
	};
};
class CfgVehicles
{
	class BaseBuildingBase;

	class TerritoryFlag : BaseBuildingBase
	{
		attachments[] += {"IAT_FlagRaiseTax"};
		class GUIInventoryAttachmentsProps
		{
			class Flag
			{
				attachmentSlots[] += {"IAT_FlagRaiseTax"};
			};
		};
	};
};

class CfgSlots
{
	class Slot_IAT_FlagRaiseTax
	{
		name = "IAT_FlagRaiseTax";
		displayName = "Flag Raise Tax";
		ghostIcon = "set:dayz_inventory image:cat_common_cargo";
		stackMax = 5;
	};
};