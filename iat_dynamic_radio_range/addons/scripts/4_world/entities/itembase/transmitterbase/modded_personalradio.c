modded class PersonalRadio
{
	protected int m_IAT_RadioRange;

	void PersonalRadio()
	{
		IAT_InitRadioData();
	}

	// ============================================== VANILLA OVERRIDE
	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionSwitchRadioRange);
	}

	override string GetTooltip()
	{
		string toolTipDescription = super.GetTooltip();

		if (IAT_GetRadioRange() > 0)
			toolTipDescription = string.Format("%1m - %2", IAT_GetRadioRange(), toolTipDescription);
		return toolTipDescription;
	}

	override void OnWork( float consumed_energy )
	{
		super.OnWork(consumed_energy);

		// track how much we need to modify our math given other mods
		float iat_UsageModifier = 0;

		#ifdef AdmiralsWorldRadioModMod
		// when in radio mode, act like normal
		if (IsRadioMode())
		{
			// 90% battery reduction
			iat_UsageModifier = 0.1;
		}
		#endif

		ItemBase energySource;
		if (Class.CastTo(energySource, GetCompEM().GetEnergySource()))
		{
			IAT_DynamicRadioConfig iat_dr_config;
			if (Class.CastTo(iat_dr_config, GetDayZGame().GetIATDynamicRadioConfig()))
			{
				float extraEnergyDelta = iat_dr_config.GetEnergyDelta(IAT_GetRadioRange());
				extraEnergyDelta *= 7.5; // default update interval is 15 so scale our consumption by that

				// if other mods are reducing energy usage
				if (iat_UsageModifier > 0)
				{
					// we are adding to the delta because muted and world radios are consuming less power by default
					// this keeps players from gaming the system to recharge batteries here.
					extraEnergyDelta = (extraEnergyDelta * iat_UsageModifier);
				}
				// values less than 0 represent ranges less than default (5000)
				if (extraEnergyDelta < 0)
				{
					extraEnergyDelta *= -1;
					energySource.GetCompEM().AddEnergy( extraEnergyDelta );
				}
				else // value is less than 0 so we remove extra energy from the source
				{
					GetCompEM().ConsumeEnergy( extraEnergyDelta );
				}
			}
		}

	};

	// ============================================== Custom OVERRIDE
	void IAT_InitRadioData()
	{
		m_IAT_RadioRange = ConfigGetInt("range");
	}

	int IAT_GetRadioRange()
	{
		if (m_IAT_RadioRange > 0)
			return m_IAT_RadioRange;
		return 5000; // default radio range
	}
};