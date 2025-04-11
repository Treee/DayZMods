class IAT_ActionEatGlowStickCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousQuantityEdible(25, UATimeSpent.DEFAULT);
	}
};

class IAT_ActionEatGlowStick: ActionEatBig
{
	void IAT_ActionEatGlowStick()
	{
		m_CallbackClass = IAT_ActionEatGlowStickCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EAT;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_EAT;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (!super.ActionCondition(player, target, item))
			return false;

		Chemlight_ColorBase chemLight;
		if ( Class.CastTo(chemLight, item) )
		{
			if (!chemLight.IsDamageDestroyed() )
				return true;
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
						action_data.m_MainItem.AddQuantity(-25);
						action_data.m_Player.GetStatToxicity().Add(50);
						action_data.m_Player.SetFacePaint(categoryIndex, categoryItem);
					}
				}
			}
		}
	};
}
