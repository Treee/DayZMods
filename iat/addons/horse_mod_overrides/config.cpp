class CfgPatches
{
	class IAT_HorseMod_Overrides
	{
		requiredAddons[] = { "Dayz_Horse" };
	};
};

class CfgVehicles
{
	class HouseNoDestruct;
	class AnimalBase;
	class Inventory_Base;

	class Land_HorseStable : HouseNoDestruct
	{
		itemsCargoSize[] = { 5,2 };
	};
	class StallBox : HouseNoDestruct
	{
		itemsCargoSize[] = { 5,2 };
	};
	class Stable_dayz : Inventory_Base
	{
		itemsCargoSize[] = { 5,2 };
	};

	class Horse_Base : AnimalBase
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = { {1,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0,{}} };
				};
				class Blood
				{
					hitpoints = 800;
				};
				class Shock
				{
					hitpoints = 1000;
				};
			};
			class DamageZones
			{
				class Zone_Head
				{
					componentNames[] = { "Zone_Head" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.15;
					canBleed = 0;
					class Health
					{
						hitpoints = 120;
						transferToGlobalCoef = 1;
					};
					class Blood : Health
					{
						hitpoints = 0;
					};
					class Shock : Health
					{
						hitpoints = 0;
					};
				};
				class Zone_Neck : Zone_Head
				{
					componentNames[] = { "Zone_Neck" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.05;
					class Health : Health
					{
						hitpoints = 100;
					};
				};
				class Zone_Spine : Zone_Head
				{
					componentNames[] = { "Zone_Spine" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.05;
					class Health : Health
					{
						hitpoints = 150;
					};
				};
				class Zone_Pelvis : Zone_Head
				{
					componentNames[] = { "Zone_Pelvis" };
					transferToZonesNames[] = { "Zone_Spine" };
					transferToZonesCoefs[] = { 0.5 };
					fatalInjuryCoef = 0.05;
					class Health : Health
					{
						hitpoints = 180;
					};
				};
				class Zone_Legs : Zone_Head
				{
					componentNames[] = { "Zone_Legs_Front","Zone_Legs_Back" };
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0;
					class Health : Health
					{
						hitpoints = 100;
					};
				};
			};
		};
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "HorseSteakMeat";
				count = 1;
				itemZones[] = { "Zone_Spine","Zone_Pelvis" };
				countByZone[] = { 1,1 };
				quantityMinMaxCoef[] = { 0.3,1 };
			};
			class ObtainedPelt
			{
				item = "HorsePelt";
				count = 1;
				itemZones[] = { "Zone_Spine","Zone_Neck" };
				quantityCoef = 0.5;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 1;
				quantityMinMaxCoef[] = { 0.5,0.8 };
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 1;
				quantityMinMaxCoef[] = { 0.2,0.5 };
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 1;
				quantityMinMaxCoef[] = { 0.8,1 };
				transferToolDamageCoef = 1;
			};
		};
	};
};

class CfgSoundShaders
{
	class baseCharacter_SoundShader;
	class water_HoofMediumWalk_water_SoundShader : baseCharacter_SoundShader
	{
		volume = 0.5;
	};
	class water_HoofMediumRun_water_SoundShader : baseCharacter_SoundShader
	{
		volume = 0.5;
	};
	class Horse_Neigh_SoundShader
	{
		volume = 0.5;
	};
	class Horse_Neigh_tailDistant_SoundShader
	{
		volume = 0.5;
		range = 200;
		rangeCurve[] = { {0,0},{50,0.8},{75,1},{100,0.5},{200,1} };
	};
	class Horse_Hit_SoundShader
	{
		volume = 0.5;
	};
	class Horse_Death_SoundShader
	{
		volume = 0.5;
	};
	class Horse_Eating_SoundShader
	{
		volume = 0.5;
	};
	class Horse_Happy_SoundShader
	{
		volume = 0.5;
	};
	class Horse_DetectThread_SoundShader
	{
		volume = 0.5;
	};
	class Horse_Nicker_SoundShader
	{
		volume = 0.5;
	};
	class Horse_RandomStanding_SoundShader
	{
		volume = 0.5;
	};
	class Horse_SighHappyRelaxed_SoundShader
	{
		volume = 0.5;
	};
};