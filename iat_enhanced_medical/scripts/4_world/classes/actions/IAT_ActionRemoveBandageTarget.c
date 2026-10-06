// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Medical action availability and server completion.
// Integration: action dispatch and patient targeting.
// Documentation: iat_enhanced_medical/README.md

class IAT_ActionRemoveBandageTarget : IAT_ActionRemoveBandageSelf
{
	void IAT_ActionRemoveBandageTarget()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_BANDAGETARGET;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#IAT_EM_ACTION_REMOVE_BANDAGE_TARGET";
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
		if (!target || !player || !player.IsAlive() || player.IsInVehicle() || !item || item.IsRuined() || !item.IAT_CanRemoveBandage())
			return false;
		PlayerBase patient = PlayerBase.Cast(target.GetObject());
		return patient && patient != player && patient.IsAlive() && !patient.IsInVehicle() && IAT_FindBandageSlot(patient) != "";
	}

	override protected void OnFinishProgressServer(ActionData action_data)
	{
		if (ActionCondition(action_data.m_Player, action_data.m_Target, action_data.m_MainItem) && CanReceiveAction(action_data.m_Target))
			IAT_Remove(action_data, PlayerBase.Cast(action_data.m_Target.GetObject()));
	}
}
