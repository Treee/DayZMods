// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Medical action availability and server completion.
// Integration: action dispatch and patient targeting.
// Documentation: iat_enhanced_medical/README.md

class IAT_ActionExtractBulletTarget : IAT_ActionExtractBulletSelf
{
	void IAT_ActionExtractBulletTarget()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_BANDAGETARGET;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#IAT_EM_ACTION_EXTRACT_BULLET_TARGET";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}

	override bool HasTarget()
	{
		return true;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!target || !super.ActionCondition(player, target, item))
			return false;
		PlayerBase patient = PlayerBase.Cast(target.GetObject());
		return patient && patient != player && patient.IsAlive() && !patient.IsInVehicle();
	}

	override protected void OnFinishProgressServer(ActionData action_data)
	{
		if (CanReceiveAction(action_data.m_Target))
			IAT_Extract(action_data, PlayerBase.Cast(action_data.m_Target.GetObject()));
	}
}
