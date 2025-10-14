modded class SeedBase
{
	protected string m_SeedToChangeInto = "";

	override void InitItemVariables()
    {
        super.InitItemVariables();
        IAT_InitSeedVariables();
    };

	void IAT_InitSeedVariables()
	{
        if (ConfigIsExisting("IAT_SeedToReplace"))
        {
            m_SeedToChangeInto = ConfigGetString("IAT_SeedToReplace");
        }
	}

	string IAT_GetSeedToChangeInto()
	{
		return m_SeedToChangeInto;
	}
};