class CfgPatches
{
	class IAT_FacePaints_Consumables
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class IAT_FacePaintStick_ColorBase : Inventory_Base
	{
		scope = 0;
		displayName = "Face Paint Stick";
		descriptionShort = "Paint your face into a lion. Might take some time to stick on your face, be patient between applications.";
		model = "\dz\gear\medical\Epinephrine.p3d";
		rotationFlags = 17;
		itemSize[] = { 1,2 };
		weight = 60;
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_facepaints\consumables\data\iat_paintstick_default_co.paa" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] =
					{
						{1.0,{"DZ\gear\medical\data\epipen.rvmat"}},
						{0.69999999,{"DZ\gear\medical\data\epipen.rvmat"}},
						{0.5,{"DZ\gear\medical\data\epipen.rvmat"}},
						{0.30000001,{"DZ\gear\medical\data\epipen.rvmat"}},
						{0.0,{"DZ\gear\medical\data\epipen_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class IAT_FacePaintStick_Default : IAT_FacePaintStick_ColorBase
	{
		scope = 2;
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_facepaints\consumables\data\iat_paintstick_default_co.paa" };
	};
};