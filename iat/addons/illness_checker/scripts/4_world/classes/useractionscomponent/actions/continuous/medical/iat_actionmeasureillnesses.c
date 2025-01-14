class IAT_ActionMeasureIllnessTargetCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT);
	}
};

class IAT_ActionMeasureIllnessTarget : ActionContinuousBase
{
	void IAT_ActionMeasureIllnessTarget()
	{
		m_CallbackClass = IAT_ActionMeasureIllnessTargetCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_SALINEBLOODBAGTARGET;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_Text = "Admin - Check Illness";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		PlayerBase ntarget;
		if (Class.CastTo(ntarget, action_data.m_Target.GetObject()) && action_data.m_Player)
		{
			IAT_Admin_Thermometer thermometer;
			if (Class.CastTo(thermometer, action_data.m_MainItem))
			{
				SendMessageToClient( action_data.m_Player, string.Format("CHOLERA: %1", thermometer.GetAgentSeverity(1000, ntarget.GetSingleAgentCount(eAgents.CHOLERA))));
				SendMessageToClient( action_data.m_Player, string.Format("INFLUENZA: %1", thermometer.GetAgentSeverity(1000, ntarget.GetSingleAgentCount(eAgents.INFLUENZA))));
				SendMessageToClient( action_data.m_Player, string.Format("SALMONELLA: %1", thermometer.GetAgentSeverity(300, ntarget.GetSingleAgentCount(eAgents.SALMONELLA))));
				SendMessageToClient( action_data.m_Player, string.Format("KURU: %1", thermometer.GetAgentSeverity(5000, ntarget.GetSingleAgentCount(eAgents.BRAIN))));
				SendMessageToClient( action_data.m_Player, string.Format("FOOD_POISON: %1", thermometer.GetAgentSeverity(400, ntarget.GetSingleAgentCount(eAgents.FOOD_POISON))));
				SendMessageToClient( action_data.m_Player, string.Format("CHEMICAL_POISON: %1", thermometer.GetAgentSeverity(500, ntarget.GetSingleAgentCount(eAgents.CHEMICAL_POISON))));
				SendMessageToClient( action_data.m_Player, string.Format("WOUND_AGENT: %1", thermometer.GetAgentSeverity(1000, ntarget.GetSingleAgentCount(eAgents.WOUND_AGENT))));
				SendMessageToClient( action_data.m_Player, string.Format("NERVE_AGENT: %1", thermometer.GetAgentSeverity(500, ntarget.GetSingleAgentCount(eAgents.NERVE_AGENT))));
				SendMessageToClient( action_data.m_Player, string.Format("HEAVYMETAL: %1", thermometer.GetAgentSeverity(600, ntarget.GetSingleAgentCount(eAgents.HEAVYMETAL))));
			}
		}
	}
};


class IAT_ActionMeasureIllnessSelfCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT);
	}
};

class IAT_ActionMeasureIllnessSelf: ActionContinuousBase
{
	void IAT_ActionMeasureIllnessSelf()
	{
		m_CallbackClass = IAT_ActionMeasureIllnessSelfCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_TAKETEMPSELF;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_TAKETEMPSELF;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_Text = "Admin - Check Illness";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}

	override bool HasProneException()
	{
		return true;
	}

	override bool HasTarget()
	{
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		IAT_Admin_Thermometer thermometer;
		if (Class.CastTo(thermometer, action_data.m_MainItem))
		{
			SendMessageToClient( action_data.m_Player, string.Format("CHOLERA: %1", thermometer.GetAgentSeverity(1000, action_data.m_Player.GetSingleAgentCount(eAgents.CHOLERA))));
			SendMessageToClient( action_data.m_Player, string.Format("INFLUENZA: %1", thermometer.GetAgentSeverity(1000, action_data.m_Player.GetSingleAgentCount(eAgents.INFLUENZA))));
			SendMessageToClient( action_data.m_Player, string.Format("SALMONELLA: %1", thermometer.GetAgentSeverity(300, action_data.m_Player.GetSingleAgentCount(eAgents.SALMONELLA))));
			SendMessageToClient( action_data.m_Player, string.Format("KURU: %1", thermometer.GetAgentSeverity(5000, action_data.m_Player.GetSingleAgentCount(eAgents.BRAIN))));
			SendMessageToClient( action_data.m_Player, string.Format("FOOD_POISON: %1", thermometer.GetAgentSeverity(400, action_data.m_Player.GetSingleAgentCount(eAgents.FOOD_POISON))));
			SendMessageToClient( action_data.m_Player, string.Format("CHEMICAL_POISON: %1", thermometer.GetAgentSeverity(500, action_data.m_Player.GetSingleAgentCount(eAgents.CHEMICAL_POISON))));
			SendMessageToClient( action_data.m_Player, string.Format("WOUND_AGENT: %1", thermometer.GetAgentSeverity(1000, action_data.m_Player.GetSingleAgentCount(eAgents.WOUND_AGENT))));
			SendMessageToClient( action_data.m_Player, string.Format("NERVE_AGENT: %1", thermometer.GetAgentSeverity(500, action_data.m_Player.GetSingleAgentCount(eAgents.NERVE_AGENT))));
			SendMessageToClient( action_data.m_Player, string.Format("HEAVYMETAL: %1", thermometer.GetAgentSeverity(600, action_data.m_Player.GetSingleAgentCount(eAgents.HEAVYMETAL))));
		}
	}
};