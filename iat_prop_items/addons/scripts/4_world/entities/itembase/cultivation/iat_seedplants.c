class IAT_SeedPlant_ColorBase extends ItemBase
{
	protected string m_IAT_SeedToChangeInto = "";

	override void InitItemVariables()
    {
        super.InitItemVariables();
        IAT_InitSeedVariables();
    };
	void IAT_InitSeedVariables()
	{
        if (ConfigIsExisting("IAT_SeedToReplace"))
        {
            m_IAT_SeedToChangeInto = ConfigGetString("IAT_SeedToReplace");
        }
	}
	string IAT_GetSeedToChangeInto()
	{
		return m_IAT_SeedToChangeInto;
	}
};

class IAT_SeedPlant_TomatoSeeds1 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_TomatoSeeds2 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_TomatoSeeds3 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_TomatoSeeds4 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_TomatoSeeds5 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_TomatoSeeds6 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_TomatoSeeds7 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_TomatoSeeds8 extends IAT_SeedPlant_ColorBase{};

class IAT_SeedPlant_PepperSeeds1 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PepperSeeds2 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PepperSeeds3 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PepperSeeds4 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PepperSeeds5 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PepperSeeds6 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PepperSeeds7 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PepperSeeds8 extends IAT_SeedPlant_ColorBase{};

class IAT_SeedPlant_PotatoSeed1 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PotatoSeed2 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PotatoSeed3 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PotatoSeed4 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PotatoSeed5 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PotatoSeed6 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PotatoSeed7 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PotatoSeed8 extends IAT_SeedPlant_ColorBase{};

class IAT_SeedPlant_PumpkinSeeds1 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PumpkinSeeds2 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PumpkinSeeds3 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PumpkinSeeds4 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PumpkinSeeds5 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PumpkinSeeds6 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PumpkinSeeds7 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_PumpkinSeeds8 extends IAT_SeedPlant_ColorBase{};

class IAT_SeedPlant_ZucchiniSeeds1 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_ZucchiniSeeds2 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_ZucchiniSeeds3 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_ZucchiniSeeds4 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_ZucchiniSeeds5 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_ZucchiniSeeds6 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_ZucchiniSeeds7 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_ZucchiniSeeds8 extends IAT_SeedPlant_ColorBase{};

class IAT_SeedPlant_CannabisSeeds1 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_CannabisSeeds2 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_CannabisSeeds3 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_CannabisSeeds4 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_CannabisSeeds5 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_CannabisSeeds6 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_CannabisSeeds7 extends IAT_SeedPlant_ColorBase{};
class IAT_SeedPlant_CannabisSeeds8 extends IAT_SeedPlant_ColorBase{};