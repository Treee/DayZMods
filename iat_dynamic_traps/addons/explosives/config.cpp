class CfgPatches
{
	class IAT_Dynamic_Traps_Explosives
	{
		requiredAddons[] = { "DZ_Weapons_Explosives" };
	};
};
class CfgAmmo
{
	class DefaultAmmo;
	class IAT_LightTrapExplosion_Ammo : DefaultAmmo
	{
		indirectHit = 3;
		indirectHitRange = 1;
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		simulation = "shotShell";
		simulationStep = 0.15000001;
		soundSetExplosion[] = { "ClaymoreMine_explosion_SoundSet", "Grenade_Tail_SoundSet" };
		class DamageApplied
		{
			type = "FragGrenade";
			bleedThreshold = 5;
			class Health
			{
				damage = 2;
			};
			class Blood
			{
				damage = 2;
			};
			class Shock
			{
				damage = 35;
			};
		};
		class NoiseExplosion
		{
			strength = 100;
			type = "shot";
		};
	};
	class IAT_HeavyTrapExplosion_Ammo : DefaultAmmo
	{
		indirectHit = 3;
		indirectHitRange = 1;
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		simulation = "shotShell";
		simulationStep = 0.15000001;
		soundSetExplosion[] = { "GasStation_Explosion_SoundSet", "GasStation_Explosion_Tail_SoundSet" };
		class DamageApplied
		{
			type = "FragGrenade";
			bleedThreshold = 5;
			class Health
			{
				damage = 4;
			};
			class Blood
			{
				damage = 4;
			};
			class Shock
			{
				damage = 60;
			};
		};
		class NoiseExplosion
		{
			strength = 100;
			type = "shot";
		};
	};
};

class CfgVehicles
{
	class Grenade_Base;
	class IAT_LightTrapExplosion : Grenade_Base
	{
		scope = 2;
		model = "\dz\weapons\explosives\frag_RGD5.p3d";
	};
	class IAT_HeavyTrapExplosion : Grenade_Base
	{
		scope = 2;
		model = "\dz\weapons\explosives\frag_RGD5.p3d";
	};
};