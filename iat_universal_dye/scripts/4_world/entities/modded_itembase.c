modded class ItemBase
{
	protected string m_BaseClassName;
    protected ref TStringArray m_DyableColorVariants;

	override void InitItemVariables()
    {
        super.InitItemVariables();
        InitializeColorVariants();
    };

	// helper to initialize dye variables found in the config this will probly eventually change to json config
    void InitializeColorVariants()
    {
        m_BaseClassName = "";
        if (ConfigIsExisting("rootClassName"))
        {
            m_BaseClassName = ConfigGetString("rootClassName");
        }
        m_DyableColorVariants = new TStringArray;
        if (ConfigIsExisting("colorVariants"))
        {
            ConfigGetTextArray("colorVariants", m_DyableColorVariants);
        }
    }
	// getter for dyable color variants
    TStringArray GetDyableColorVariants()
    {
        return m_DyableColorVariants;
    }
	// setter for dye base class name
    void SetDyableBaseClassName(string baseClassName)
    {
        m_BaseClassName = baseClassName;
    }
	// returns if there are variant options
    bool HasDyableOptions()
    {
        return m_DyableColorVariants.Count() > 0;
    }
	// get the base class name for this item (meant for building a new item name)
    string GetDyableBaseClassName()
    {
        return m_BaseClassName;
    }
	// get a dye option given a valid index
    string GetDyeOption(int index)
    {
		// if there are options AND the index is valid
        if (HasDyableOptions() && m_DyableColorVariants.IsValidIndex(index))
        {
			// return the option
            return m_DyableColorVariants.Get(index);
        }
		// return empty string
        return "";
    }
	// Return the total number of variants for this items dye options
    int GetTotalColorVariations()
    {
        return m_DyableColorVariants.Count();
    }
};