class CfgPatches
{
	class alv_personal_tent_Tent
	{
		requiredAddons[]=
		{
			"DZ_Data",
			"ALV_UN_Gear",
			"ALV_UN_Weapons_Proxy",
			"IAT_Crafting_Plus_Crafting"
		};
	};
};
class CfgVehicles
{
	class ALV_Deployable_Base;
	class ALV_Kit_Base;
	class IAT_PersonalTent_ColorBase: ALV_Deployable_Base
	{
		scope=0;
		displayName="PersonalTent";
		descriptionShort="A one man tent.";
		model="alv_personal_tent\Tent\Personal_Tent.p3d";
		hiddenSelections[]={"zbytek"};
		hiddenSelectionsTextures[]={"alv_personal_tent\Tent\data\TentFabric_CA.paa"};
		hologramMaterial="WoodenBarrel";
		hologramMaterialPath="alv_personal_tent\Tent\data";
		slopeTolerance=0.40000001;
		yawPitchRollLimit[]={45,45,45};
		physLayer="item_large";
		heavyItem=1;
		weight=10000;
		itemSize[]={10,10};
		itemBehaviour=0;
		carveNavmesh=1;
		canBeDigged=0;
		rotationFlags=2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10000;
					healthLevels[]=
					{
						{1,{"alv_personal_tent\Tent\data\TentFabric.rvmat"}},
						{0.69999999,{"alv_personal_tent\Tent\data\TentFabric.rvmat"}},
						{0.5,{"alv_personal_tent\Tent\data\TentFabric.rvmat"}},
						{0.30000001,{"alv_personal_tent\Tent\data\TentFabric.rvmat"}},
						{0,{"alv_personal_tent\Tent\data\TentFabric.rvmat"}}
					};
				};
			};
			class GlobalArmor
			{
				class FragGrenade
				{
					class Health
					{
						damage=8;
					};
					class Blood
					{
						damage=8;
					};
					class Shock
					{
						damage=8;
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.0099999998;
			};
		};
		soundImpactType="wood";
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet="barrel_movement_SoundSet";
					id=1;
				};
				class pickUpItem_Light
				{
					soundSet="pickUpBarrelLight_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpBarrel_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="barrel_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class IAT_PersonalTent_Canvas_kit: ALV_Kit_Base
	{
		scope=2;
		displayName="Personal Tent | Canvas";
		hiddenSelections[]=	{"zbytek"};
		hiddenSelectionsTextures[]=	{"ALV_UN_Gear\containers\data\Storage_Kit_CO.paa"};
	};
	class IAT_PersonalTent_Canvas: IAT_PersonalTent_ColorBase
	{
		scope=2;
		hiddenSelections[]=	{"zbytek"};
		hiddenSelectionsTextures[]=	{"alv_personal_tent\Tent\data\TentFabric_CA.paa"};
	};
};
