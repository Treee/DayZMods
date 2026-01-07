class CfgPatches
{
	class IAT_Simple_Carpentry_Camping
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Camping" };
	};
};
class CfgVehicles
{
	// StaticObj_IAT_Symbol_Blah

	// IAT_CarvedSymbol_ColorBase;
	// a-z, 0-9, symbols
	class Inventory_Base;

	class IAT_CarvedSymbol_Kit : Inventory_Base
	{
		scope = 2;
		displayName = "Carved Symbol Kit";
		descriptionShort = "A kit that has several options for placing crafting different symbols.";
        model="\dz\gear\cooking\log01.p3d";
        animClass="NoFireClass";
        weight=2000;
        absorbency=0.3;
        itemSize[]={2, 2};
		itemBehaviour = 1;
		debug_ItemCategory = 10;
		soundImpactType = "wood";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = { {1, {}}, {0.7, {}}, {0.5, {}}, {0.3, {}}, {0, {}} };
				};
				class GlobalArmor
				{
					class Projectile
					{
						class Health
						{
							damage = 0;
						};
						class Blood
						{
							damage = 0;
						};
						class Shock
						{
							damage = 0;
						};
					};
					class FragGrenade
					{
						class Health
						{
							damage = 0;
						};
						class Blood
						{
							damage = 0;
						};
						class Shock
						{
							damage = 0;
						};
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
            {
                class woodenlog_drop
                {
                    soundset="woodenlog_drop_SoundSet";
                    id=898;
                };
            };
		};
	};

	class IAT_CarvedSymbol_ColorBase : Inventory_Base
	{
		scope = 0;
		displayName = "Carved Symbol";
		descriptionShort = "A symbol carved from a piece of wood.";
		model = "iat_simple_carpentry\camping\letters\iat_a.p3d";
		lootCategory = "Crafted";
		weight = 2000;
		itemSize[] = { 2, 2 };
		itemBehaviour = 1;
		itemsCargoSize[] = { 0 , 0 };
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "DZ\gear\consumables\data\oak_bark_co.paa" };
	};

	class IAT_CarvedSymbol_A : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "A"; model = "iat_simple_carpentry\camping\letters\iat_a.p3d"; };
	class IAT_CarvedSymbol_B : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "B"; model = "iat_simple_carpentry\camping\letters\iat_b.p3d"; };
	class IAT_CarvedSymbol_C : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "C"; model = "iat_simple_carpentry\camping\letters\iat_c.p3d"; };
	class IAT_CarvedSymbol_D : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "D"; model = "iat_simple_carpentry\camping\letters\iat_d.p3d"; };
	class IAT_CarvedSymbol_E : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "E"; model = "iat_simple_carpentry\camping\letters\iat_e.p3d"; };
	class IAT_CarvedSymbol_F : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "F"; model = "iat_simple_carpentry\camping\letters\iat_f.p3d"; };
	class IAT_CarvedSymbol_G : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "G"; model = "iat_simple_carpentry\camping\letters\iat_g.p3d"; };
	class IAT_CarvedSymbol_H : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "H"; model = "iat_simple_carpentry\camping\letters\iat_h.p3d"; };
	class IAT_CarvedSymbol_I : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "I"; model = "iat_simple_carpentry\camping\letters\iat_i.p3d"; };
	class IAT_CarvedSymbol_J : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "J"; model = "iat_simple_carpentry\camping\letters\iat_j.p3d"; };
	class IAT_CarvedSymbol_K : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "K"; model = "iat_simple_carpentry\camping\letters\iat_k.p3d"; };
	class IAT_CarvedSymbol_L : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "L"; model = "iat_simple_carpentry\camping\letters\iat_l.p3d"; };
	class IAT_CarvedSymbol_M : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "M"; model = "iat_simple_carpentry\camping\letters\iat_m.p3d"; };
	class IAT_CarvedSymbol_N : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "N"; model = "iat_simple_carpentry\camping\letters\iat_n.p3d"; };
	class IAT_CarvedSymbol_O : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "O"; model = "iat_simple_carpentry\camping\letters\iat_o.p3d"; };
	class IAT_CarvedSymbol_P : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "P"; model = "iat_simple_carpentry\camping\letters\iat_p.p3d"; };
	class IAT_CarvedSymbol_Q : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "Q"; model = "iat_simple_carpentry\camping\letters\iat_q.p3d"; };
	class IAT_CarvedSymbol_R : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "R"; model = "iat_simple_carpentry\camping\letters\iat_r.p3d"; };
	class IAT_CarvedSymbol_S : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "S"; model = "iat_simple_carpentry\camping\letters\iat_s.p3d"; };
	class IAT_CarvedSymbol_T : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "T"; model = "iat_simple_carpentry\camping\letters\iat_t.p3d"; };
	class IAT_CarvedSymbol_U : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "U"; model = "iat_simple_carpentry\camping\letters\iat_u.p3d"; };
	class IAT_CarvedSymbol_V : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "V"; model = "iat_simple_carpentry\camping\letters\iat_v.p3d"; };
	class IAT_CarvedSymbol_W : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "W"; model = "iat_simple_carpentry\camping\letters\iat_w.p3d"; };
	class IAT_CarvedSymbol_X : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "X"; model = "iat_simple_carpentry\camping\letters\iat_x.p3d"; };
	class IAT_CarvedSymbol_Y : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "Y"; model = "iat_simple_carpentry\camping\letters\iat_y.p3d"; };
	class IAT_CarvedSymbol_Z : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "Z"; model = "iat_simple_carpentry\camping\letters\iat_z.p3d"; };

	class IAT_CarvedSymbol_0 : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "0"; model = "iat_simple_carpentry\camping\numbers\iat_0.p3d"; };
	class IAT_CarvedSymbol_1 : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "1"; model = "iat_simple_carpentry\camping\numbers\iat_1.p3d"; };
	class IAT_CarvedSymbol_2 : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "2"; model = "iat_simple_carpentry\camping\numbers\iat_2.p3d"; };
	class IAT_CarvedSymbol_3 : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "3"; model = "iat_simple_carpentry\camping\numbers\iat_3.p3d"; };
	class IAT_CarvedSymbol_4 : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "4"; model = "iat_simple_carpentry\camping\numbers\iat_4.p3d"; };
	class IAT_CarvedSymbol_5 : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "5"; model = "iat_simple_carpentry\camping\numbers\iat_5.p3d"; };
	class IAT_CarvedSymbol_6 : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "6"; model = "iat_simple_carpentry\camping\numbers\iat_6.p3d"; };
	class IAT_CarvedSymbol_7 : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "7"; model = "iat_simple_carpentry\camping\numbers\iat_7.p3d"; };
	class IAT_CarvedSymbol_8 : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "8"; model = "iat_simple_carpentry\camping\numbers\iat_8.p3d"; };
	class IAT_CarvedSymbol_9 : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "9"; model = "iat_simple_carpentry\camping\numbers\iat_9.p3d"; };

	class IAT_CarvedSymbol_Ampersand   : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "&";            model = "iat_simple_carpentry\camping\symbols\iat_ampersand.p3d"; };
	class IAT_CarvedSymbol_ArrowDown   : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "Arrow Down";   model = "iat_simple_carpentry\camping\symbols\iat_arrowdown.p3d"; };
	class IAT_CarvedSymbol_ArrowLeft   : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "Arrow Left";   model = "iat_simple_carpentry\camping\symbols\iat_arrowleft.p3d"; };
	class IAT_CarvedSymbol_ArrowRight  : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "Arrow Right";  model = "iat_simple_carpentry\camping\symbols\iat_arrowright.p3d"; };
	class IAT_CarvedSymbol_ArrowUp     : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "Arrow Up";     model = "iat_simple_carpentry\camping\symbols\iat_arrowup.p3d"; };
	class IAT_CarvedSymbol_Asterisk    : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "*";            model = "iat_simple_carpentry\camping\symbols\iat_asterisk.p3d"; };
	class IAT_CarvedSymbol_Dollar      : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "$";            model = "iat_simple_carpentry\camping\symbols\iat_dollars.p3d"; };
	class IAT_CarvedSymbol_Equals      : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "=";            model = "iat_simple_carpentry\camping\symbols\iat_equals.p3d"; };
	class IAT_CarvedSymbol_Exclamation : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "!";            model = "iat_simple_carpentry\camping\symbols\iat_exclamation.p3d"; };
	class IAT_CarvedSymbol_Hash        : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "#";            model = "iat_simple_carpentry\camping\symbols\iat_hash.p3d"; };
	class IAT_CarvedSymbol_Parenthesis : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "Parenthesis";  model = "iat_simple_carpentry\camping\symbols\iat_parenthesis.p3d"; };
	class IAT_CarvedSymbol_Percent     : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "%";            model = "iat_simple_carpentry\camping\symbols\iat_percent.p3d"; };
	class IAT_CarvedSymbol_Plus        : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "+";            model = "iat_simple_carpentry\camping\symbols\iat_plus.p3d"; };
	class IAT_CarvedSymbol_Question    : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "?";            model = "iat_simple_carpentry\camping\symbols\iat_question.p3d"; };
	class IAT_CarvedSymbol_Slash       : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "/";            model = "iat_simple_carpentry\camping\symbols\iat_slash.p3d"; };
	class IAT_CarvedSymbol_Times       : IAT_CarvedSymbol_ColorBase { scope = 2; displayName = "Times";        model = "iat_simple_carpentry\camping\symbols\iat_times.p3d"; };
};