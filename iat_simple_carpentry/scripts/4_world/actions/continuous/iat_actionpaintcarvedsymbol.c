class IAT_ActionPaintCarvedSymbolCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(1.0);
	}
};

class IAT_ActionPaintCarvedSymbol: ActionContinuousBase
{
	void IAT_ActionPaintCarvedSymbol()
	{
		m_CallbackClass = IAT_ActionPaintCarvedSymbolCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_OPENITEM;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_Text = "Paint Symbol";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined();
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
	}

	override bool HasTarget()
	{
		return true;
	}


	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Spraycan_ColorBase sprayCan;
		if (Class.CastTo(sprayCan, item))
		{
			IAT_CarvedSymbol_ColorBase carvedSymbol;
			if (Class.CastTo(carvedSymbol, target.GetObject()))
			{
				if (sprayCan.IAT_HasCarvedSymbolColorSelection())
				{
					if (sprayCan.GetQuantity() >= 10)
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		Spraycan_ColorBase sprayCan;
		if (Class.CastTo(sprayCan, action_data.m_MainItem))
		{
			IAT_CarvedSymbol_ColorBase carvedSymbol;
			if (Class.CastTo(carvedSymbol, action_data.m_Target.GetObject()))
			{
				carvedSymbol.SetSelectedColor(sprayCan.IAT_GetCarvedLetterColorIndex());
				carvedSymbol.SetSynchDirty();
				sprayCan.AddQuantity(-10);
			}
		}
	}
};