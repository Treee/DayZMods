class CfgPatches
{
	class IAT_Illness_Checker_Medical
	{
		requiredAddons[] = { "DZ_Gear_Medical" };
	};
};
class CfgVehicles
{
	class Inventory_Base;

	class IAT_Admin_Thermometer : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Thermometer0";
		descriptionShort = "$STR_CfgVehicles_Thermometer1";
		model = "\dz\gear\medical\med_tmeter.p3d";
		debug_ItemCategory = 7;
		rotationFlags = 17;
		itemSize[] = { 1, 2 };
		weight = 15;
		fragility = 0.5;
		soundImpactType = "glass";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 15;
					healthLevels[] = { {1, {"DZ\gear\medical\data\med_tmeter.rvmat"}}, {0.7, {"DZ\gear\medical\data\med_tmeter.rvmat"}}, {0.5, {"DZ\gear\medical\data\med_tmeter_damage.rvmat"}}, {0.3, {"DZ\gear\medical\data\med_tmeter_damage.rvmat"}}, {0, {"DZ\gear\medical\data\med_tmeter_destruct.rvmat"}} };
				};
			};
		};
		class AnimationSources
		{
			class cover
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};
};