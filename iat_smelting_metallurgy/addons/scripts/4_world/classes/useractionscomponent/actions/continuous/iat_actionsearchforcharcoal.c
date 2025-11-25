class IAT_ActionSearchForCharcoalCB: ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
        m_ActionData.m_ActionComponent = new CAContinuousTime(2.0);
    };
};

class IAT_ActionSearchForCharcoal: ActionContinuousBase
{
    void IAT_ActionSearchForCharcoal()
    {
		m_CallbackClass = IAT_ActionSearchForCharcoalCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_Text = "Search for Charcoal";
	}

	override void CreateConditionComponents()
	{
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
		m_ConditionItem = new CCINotPresent;
	}
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	override bool HasProgress()
	{
		return true;
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		FireplaceBase targetIB;
		if (Class.CastTo(targetIB, target.GetObject()))
		{
			if (targetIB.IsFireplace())
			{
				if (!targetIB.IsDamageDestroyed())
				{
      				return targetIB.HasAshes();
				}
			}
		}
		return false;
	}
    override void OnFinishProgressServer(ActionData action_data)
    {
		super.OnFinishProgressServer(action_data);
		string newItemName = "IAT_MiningOre_Charcoal";
		if (Math.RandomFloat01() > 0.9)
    	{
			newItemName = "IAT_MiningOre_Coke";
		}

		ItemBase fuel;
		if (Class.CastTo(fuel, GetGame().CreateObjectEx(newItemName, action_data.m_Player.GetPosition(), ECE_SETUP|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY)))
		{
			// 1 - max / 2
			fuel.SetQuantity(1, (fuel.GetQuantityMax() / 2));

			// remove the fireplace
			FireplaceBase targetIB;
			if (Class.CastTo(targetIB, action_data.m_Target.GetObject()))
			{
				targetIB.DeleteSafe();
			}
		}
    };
};