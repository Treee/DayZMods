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
		// hiddenSelections[] = { "zbytek"};
		// hiddenSelectionsTextures[] = { "DZ\gear\consumables\data\pile_of_planks_co.paa" };
	};

	class land_iat_miningsegment_entrance : IAT_MiningSegment_Colorbase
	{
		scope = 1;
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
		};
		class AnimationSources
		{
			class support_d
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class support_e
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class support_n
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class support_s
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class support_u
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class support_w
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
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