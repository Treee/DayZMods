class IAT_ActionToggleFurnaceLockCB: ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
        m_ActionData.m_ActionComponent = new CAContinuousTime(2.0);
    };
};

class IAT_ActionToggleFurnaceLock: ActionContinuousBase
{
    void IAT_ActionToggleFurnaceLock()
    {
		m_CallbackClass = IAT_ActionToggleFurnaceLockCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
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
	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		IAT_SmeltingFurnace_ColorBase furnace;
		if (Class.CastTo(furnace, target.GetObject()))
		{
			if (furnace.IAT_AreSlotsLocked())
			{
				m_Text = "#STR_IAT_UnLockSmeltingSlots";
			}
			else
			{
				m_Text = "#STR_IAT_LockSmeltingSlots";
			}
		}
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		return true;
	}
    override void OnFinishProgressServer(ActionData action_data)
    {
		super.OnFinishProgressServer(action_data);
        IAT_SmeltingFurnace_ColorBase furnace;
		if (Class.CastTo(furnace, action_data.m_Target.GetObject()))
		{
			if (furnace.IAT_AreSlotsLocked())
			{
				furnace.IAT_UnlockOreSlots();
			}
			else
			{
				furnace.IAT_LockOreSlots();
			}
		}
    };
};