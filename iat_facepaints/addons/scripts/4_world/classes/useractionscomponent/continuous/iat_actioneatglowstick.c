class IAT_ActionEatGlowStickCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(5);
	}
};

class IAT_ActionEatGlowStick: ActionContinuousBase
{
	void IAT_ActionEatGlowStick()
	{
		m_CallbackClass = IAT_ActionEatGlowStickCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EAT;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_EAT;
		m_Text = "Eat Glowstick";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem 	= new CCINotRuinedAndEmpty();
		m_ConditionTarget 	= new CCTSelf();
	}
	override bool HasProneException()
	{
		return true;
	}
	override bool HasTarget()
	{
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (!super.ActionCondition(player, target, item))
			return false;

		if (GetDayZGame())
		{
			IAT_FacePaintsConfig iat_fp_config;
			if (Class.CastTo(iat_fp_config, GetDayZGame().GetIATFacePaintConfig()))
			{
				// dont allow eating glowsticks
				if (!iat_fp_config.IsEnableEatGlowStickAction())
				{
					return false;
				}
			}
		}

		Chemlight_ColorBase chemLight;
		if ( Class.CastTo(chemLight, item) )
		{
			if (chemLight.IsDamageDestroyed() )
				return false;

			if (chemLight.GetCompEM().GetEnergy() > 24)
			{
				return true;
			}
		}

		return false;
	}

	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);
		if (GetDayZGame())
		{
			IAT_FacePaintsConfig iat_fp_config;
			if (Class.CastTo(iat_fp_config, GetDayZGame().GetIATFacePaintConfig()))
			{
				IAT_FacePaintOptions fp_options = iat_fp_config.GetFacePaintOptions();
				int categoryIndex = fp_options.GetCategories().Find("masks_&_tattoos");
				if (categoryIndex > -1)
				{
					string color = action_data.m_MainItem.GetType();
					color.ToLower();
					color.Replace("chemlight_", "");
					int categoryItem = fp_options.GetCategoryItems("masks_&_tattoos").Find(string.Format("glowstick_%1", color));
					if (categoryItem > -1)
					{
						float consumption = action_data.m_MainItem.GetCompEM().GetEnergyMax() * 0.25;
						action_data.m_MainItem.GetCompEM().ConsumeEnergy(consumption);
						action_data.m_Player.GetStatToxicity().Add(50);
						action_data.m_Player.SetFacePaint(categoryIndex, categoryItem);
					}
				}
			}
		}
	};
}
