class CfgPatches
{
	class IAT_Molotov_Grenades_Weapons_Explosives
	{
		requiredAddons[] = { "DZ_Weapons_Explosives" };
	};
};
class CfgVehicles
{
	class Grenade_Base;
	class IAT_Molotov_Grenade_Incendiary : Grenade_Base
	{
		scope = 2;
		displayName = "Incendiary Grenade";
		descriptionShort = "A grenade that bursts into a ball of fire when thrown. Creates an area effect of fire for some time.";
		model = "\dz\weapons\explosives\Grenade_ChemGas.p3d";
		weight = 500;
		itemSize[] = { 1, 1 };
		inventorySlot[] = { "IEDExplosiveA", "IEDExplosiveB" };
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_molotov_firegrenades\weapons\explosives\data\grenade_incendiary_co.paa" };
		hiddenSelectionsMaterials[] = {};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 5;
					healthLevels[] = { {1, {"iat_molotov_firegrenades\weapons\explosives\data\grenade_incendiary.rvmat"}}, {0.7, {"iat_molotov_firegrenades\weapons\explosives\data\grenade_incendiary.rvmat"}}, {0.5, {"iat_molotov_firegrenades\weapons\explosives\data\grenade_incendiary_damage.rvmat"}}, {0.3, {"iat_molotov_firegrenades\weapons\explosives\data\grenade_incendiary_damage.rvmat"}}, {0, {"iat_molotov_firegrenades\weapons\explosives\data\grenade_incendiary_destruct.rvmat"}} };
				};
			};
		};
	};


	class IAT_Molotov_Grenade_Molotov : Grenade_Base
	{
		scope = 2;
		displayName = "Molotov";
		descriptionShort = "A alcohol filled bottle ready to cause some mayhem. Light and throw to make a boom.";
		model = "\dz\gear\drinks\VodkaBottles.p3d";
		weight = 550;
		itemSize[] = { 1, 3 };
		inventorySlot[] = { "IEDExplosiveA", "IEDExplosiveB" };
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_molotov_firegrenades\weapons\explosives\data\vodkabottles_molotov_ca.paa" };
		hiddenSelectionsMaterials[] = { "dz\gear\drinks\data\vodkabottles.rvmat" };
		soundImpactType = "glass";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = { {1, {"DZ\gear\drinks\data\VodkaBottles.rvmat"}}, {0.7, {"DZ\gear\drinks\data\VodkaBottles.rvmat"}}, {0.5, {"DZ\gear\drinks\data\VodkaBottles_damage.rvmat"}}, {0.3, {"DZ\gear\drinks\data\VodkaBottles_damage.rvmat"}}, {0, {"DZ\gear\drinks\data\VodkaBottles_destruct.rvmat"}} };
				};
			};
		};
	};
};