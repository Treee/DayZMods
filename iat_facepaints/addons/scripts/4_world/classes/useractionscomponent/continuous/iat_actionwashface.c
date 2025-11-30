class IAT_ActionWashFaceCB: ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(1.0);
	}
};
class IAT_ActionWashFace: ActionContinuousBase
{
  	void IAT_ActionWashFace()
	{
		m_CallbackClass = IAT_ActionWashFaceCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_SHAVE;
		m_FullBody = false;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
    	m_Text = "Wash Face";
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}
 	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!player)
			return false;
		if (player.IsBleeding())
			return false;

		if (player.GetFacePaintIndex() > -1)
			return true;
    	return false;
	}
	override bool HasTarget()
	{
		return false;
	}
  	override void OnFinishProgressServer(ActionData action_data)
	{
		if (action_data.m_Player)
			action_data.m_Player.ClearPaint();
	}
};

class IAT_ActionWashFaceTarget: ActionContinuousBase
{
	void IAT_ActionWashFaceTarget()
	{
		m_CallbackClass = IAT_ActionWashFaceCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
    	m_Text = "Wash Face - Target";
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}
  	override bool ActionCondition (PlayerBase player, ActionTarget target, ItemBase item)
	{
		PlayerBase man;
		if (target && !Class.CastTo(man, target.GetObject()) )
			return false;
		if (man.IsBleeding())
			return false;
		if (man.GetFacePaintIndex() == -1)
			return false;

		return true;
	}
  	override void OnFinishProgressServer( ActionData action_data )
	{
		PlayerBase man;
		if (action_data.m_Target && Class.CastTo(man, action_data.m_Target.GetObject()))
			man.ClearPaint();
	}
};