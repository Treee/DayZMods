class CfgPatches
{
	class IAT_Powered_Radio_Towers_Structures
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Structures" };
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class StaticObj_iat_wallconsole : HouseNoDestruct
	{
		scope = 1;
		model = "iat_powered_radio_towers\structures\iat_wallconsole.p3d";
		hiddenSelections[] = { "screen", "console", "buttons" };
		hiddenSelectionsTextures[] =
		{
			"iat_powered_radio_towers\structures\data\iat_wallconsole_screenempty_co.paa",
			"iat_powered_radio_towers\structures\data\iat_wallconsole_rusted_co.paa",
			"iat_powered_radio_towers\structures\data\iat_wallconsole_buttons_rusted_co.paa",
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
					healthLevels[] =
					{
						{1,{"iat_powered_radio_towers\structures\data\iat_wallconsole.rvmat", "iat_powered_radio_towers\structures\data\iat_wallconsole.rvmat", "iat_powered_radio_towers\structures\data\iat_wallconsole_buttons.rvmat"}},
						{0.7,{"iat_powered_radio_towers\structures\data\iat_wallconsole.rvmat", "iat_powered_radio_towers\structures\data\iat_wallconsole.rvmat", "iat_powered_radio_towers\structures\data\iat_wallconsole_buttons.rvmat"}},
						{0.5,{"iat_powered_radio_towers\structures\data\iat_wallconsole_damage.rvmat", "iat_powered_radio_towers\structures\data\iat_wallconsole_damage.rvmat", "iat_powered_radio_towers\structures\data\iat_wallconsole_buttons_damage.rvmat"}},
						{0.3,{"iat_powered_radio_towers\structures\data\iat_wallconsole_damage.rvmat", "iat_powered_radio_towers\structures\data\iat_wallconsole_damage.rvmat", "iat_powered_radio_towers\structures\data\iat_wallconsole_buttons_damage.rvmat"}},
						{0,{"iat_powered_radio_towers\structures\data\iat_wallconsole_destruct.rvmat", "iat_powered_radio_towers\structures\data\iat_wallconsole_destruct.rvmat", "iat_powered_radio_towers\structures\data\iat_wallconsole_buttons_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimationSources
		{
			class relay
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 0;
			};
			class server
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 0;
			};
			class cpu
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 0;
			};
			class power
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 0;
			};
			class dial
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 0;
			};
		};
	};
};