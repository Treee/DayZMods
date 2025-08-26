class CfgPatches
{
	class IAT_Mining_Structures
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgVehicles
{
	class HouseNoDestruct;

	class IAT_MiningSegment_Colorbase : HouseNoDestruct
	{
		scope = 0;
		displayName = "Tunnel";
		descriptionShort = "A rock tunnel";
		model = "iat_mining_enhanced\structures\iat_miningsegment_junction.p3d";
		handheld = "false";
		physLayer = "item_large"; // give it collission
		debug_ItemCategory = 10;
		weight = 100000;
		itemSize[] = { 50, 50 };
		itemsCargoSize[] = { 0 , 0 };
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\structures\data\iat_cavestone_co.paa" };
	};

	class land_iat_miningsegment_entrance : IAT_MiningSegment_Colorbase
	{
		scope = 1;
		hiddenSelections[] = { "zbytek", "support" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\structures\data\iat_cavestone_co.paa", "dz\gear\consumables\data\pile_of_planks_co.paa" };
		model = "iat_mining_enhanced\structures\iat_miningsegment_entrance.p3d";
	};
	class land_iat_miningsegment_junction : IAT_MiningSegment_Colorbase
	{
		scope = 1;
		model = "iat_mining_enhanced\structures\iat_miningsegment_junction.p3d";
		class Doors
		{
			// inner segments
			class Door1
			{
				displayName = "Door 1";
				component = "Door1";
				soundPos = "door1_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "IAT_Mining_Enhanced_FallingRock";
				soundClose = "IAT_Mining_Enhanced_FallingRock";
				soundLocked = "IAT_Mining_Enhanced_FallingRock";
				soundOpenABit = "IAT_Mining_Enhanced_FallingRock";
			};
			class Door2
			{
				displayName = "Door 2";
				component = "Door2";
				soundPos = "door2_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "IAT_Mining_Enhanced_FallingRock";
				soundClose = "IAT_Mining_Enhanced_FallingRock";
				soundLocked = "IAT_Mining_Enhanced_FallingRock";
				soundOpenABit = "IAT_Mining_Enhanced_FallingRock";
			};
			class Door3
			{
				displayName = "Door 3";
				component = "Door3";
				soundPos = "door3_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "IAT_Mining_Enhanced_FallingRock";
				soundClose = "IAT_Mining_Enhanced_FallingRock";
				soundLocked = "IAT_Mining_Enhanced_FallingRock";
				soundOpenABit = "IAT_Mining_Enhanced_FallingRock";
			};
			class Door4
			{
				displayName = "Door 4";
				component = "Door4";
				soundPos = "door4_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "IAT_Mining_Enhanced_FallingRock";
				soundClose = "IAT_Mining_Enhanced_FallingRock";
				soundLocked = "IAT_Mining_Enhanced_FallingRock";
				soundOpenABit = "IAT_Mining_Enhanced_FallingRock";
			};
			class Door5
			{
				displayName = "Door 5";
				component = "Door5";
				soundPos = "door5_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "IAT_Mining_Enhanced_FallingRock";
				soundClose = "IAT_Mining_Enhanced_FallingRock";
				soundLocked = "IAT_Mining_Enhanced_FallingRock";
				soundOpenABit = "IAT_Mining_Enhanced_FallingRock";
			};
			class Door6
			{
				displayName = "Door 6";
				component = "Door6";
				soundPos = "door6_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "IAT_Mining_Enhanced_FallingRock";
				soundClose = "IAT_Mining_Enhanced_FallingRock";
				soundLocked = "IAT_Mining_Enhanced_FallingRock";
				soundOpenABit = "IAT_Mining_Enhanced_FallingRock";
			};
			// inner segments
			class Door7
			{
				displayName = "Door 7";
				component = "Door7";
				soundPos = "door7_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "IAT_Mining_Enhanced_FallingRock";
				soundClose = "IAT_Mining_Enhanced_FallingRock";
				soundLocked = "IAT_Mining_Enhanced_FallingRock";
				soundOpenABit = "IAT_Mining_Enhanced_FallingRock";
			};
			class Door8
			{
				displayName = "Door 8";
				component = "Door8";
				soundPos = "door8_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "IAT_Mining_Enhanced_FallingRock";
				soundClose = "IAT_Mining_Enhanced_FallingRock";
				soundLocked = "IAT_Mining_Enhanced_FallingRock";
				soundOpenABit = "IAT_Mining_Enhanced_FallingRock";
			};
			class Door9
			{
				displayName = "Door 9";
				component = "Door9";
				soundPos = "door9_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "IAT_Mining_Enhanced_FallingRock";
				soundClose = "IAT_Mining_Enhanced_FallingRock";
				soundLocked = "IAT_Mining_Enhanced_FallingRock";
				soundOpenABit = "IAT_Mining_Enhanced_FallingRock";
			};
			class Door10
			{
				displayName = "Door 10";
				component = "Door10";
				soundPos = "door10_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "IAT_Mining_Enhanced_FallingRock";
				soundClose = "IAT_Mining_Enhanced_FallingRock";
				soundLocked = "IAT_Mining_Enhanced_FallingRock";
				soundOpenABit = "IAT_Mining_Enhanced_FallingRock";
			};
			class Door11
			{
				displayName = "Door 11";
				component = "Door11";
				soundPos = "door11_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "IAT_Mining_Enhanced_FallingRock";
				soundClose = "IAT_Mining_Enhanced_FallingRock";
				soundLocked = "IAT_Mining_Enhanced_FallingRock";
				soundOpenABit = "IAT_Mining_Enhanced_FallingRock";
			};
			class Door12
			{
				displayName = "Door 12";
				component = "Door12";
				soundPos = "door12_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "IAT_Mining_Enhanced_FallingRock";
				soundClose = "IAT_Mining_Enhanced_FallingRock";
				soundLocked = "IAT_Mining_Enhanced_FallingRock";
				soundOpenABit = "IAT_Mining_Enhanced_FallingRock";
			};
			// supports
			class Door13 // down
			{
				displayName = "Door 13";
				component = "Door13";
				soundPos = "door13_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
			};
			class Door14 // up
			{
				displayName = "Door 14";
				component = "Door14";
				soundPos = "door14_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
			};
			class Door15 // east
			{
				displayName = "Door 15";
				component = "Door15";
				soundPos = "door15_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
			};
			class Door16 // west
			{
				displayName = "Door 16";
				component = "Door16";
				soundPos = "door16_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
			};
			class Door17 // north
			{
				displayName = "Door 17";
				component = "Door17";
				soundPos = "door17_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
			};
			class Door18 // south
			{
				displayName = "Door 18";
				component = "Door18";
				soundPos = "door18_action";
				animPeriod = 0.1;
				initPhase = 0;
				initOpened = 0.5;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health { hitpoints = 1200; };
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health { damage = 0; };
					class Blood { damage = 0; };
					class Shock { damage = 0; };
				};
				class Melee
				{
					class Health { damage = 0; };
					class Blood { damage = 0; };
					class Shock { damage = 0; };
				};
				class FragGrenade
				{
					class Health { damage = 0; };
					class Blood { damage = 0; };
					class Shock { damage = 0; };
				};
			};
			class DamageZones
			{
				class Door1
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door1" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class FragGrenade
						{
							// class Health { damage = 0.05; };
							class Health { damage = 1000; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
				class Door2
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door2" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class FragGrenade
						{
							// class Health { damage = 0.05; };
							class Health { damage = 1000; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
				class Door3
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door3" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class FragGrenade
						{
							// class Health { damage = 0.05; };
							class Health { damage = 1000; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
				class Door4
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door4" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class FragGrenade
						{
							// class Health { damage = 0.05; };
							class Health { damage = 1000; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
				class Door5
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door5" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class FragGrenade
						{
							// class Health { damage = 0.05; };
							class Health { damage = 1000; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
				class Door6
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door6" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class FragGrenade
						{
							// class Health { damage = 0.05; };
							class Health { damage = 1000; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
				class Door7
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door7" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class FragGrenade
						{
							// class Health { damage = 0.05; };
							class Health { damage = 1000; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
				class Door8
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door8" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class FragGrenade
						{
							// class Health { damage = 0.05; };
							class Health { damage = 1000; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
				class Door9
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door9" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class FragGrenade
						{
							// class Health { damage = 0.05; };
							class Health { damage = 1000; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
				class Door10
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door10" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class FragGrenade
						{
							// class Health { damage = 0.05; };
							class Health { damage = 1000; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
				class Door11
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door11" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class FragGrenade
						{
							// class Health { damage = 0.05; };
							class Health { damage = 1000; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
				class Door12
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door12" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 0; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class FragGrenade
						{
							// class Health { damage = 0.05; };
							class Health { damage = 1000; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
			};
		};
	};
};