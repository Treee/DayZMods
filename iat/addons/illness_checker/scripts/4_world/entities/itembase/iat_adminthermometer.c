class IAT_Admin_Thermometer extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionMeasureIllnessTarget);
		AddAction(IAT_ActionMeasureIllnessSelf);
	}

	string GetAgentSeverity(int maxAgents, int currentAgents)
	{
		// Print("Max Agents " + maxAgents + " current Agents: " + currentAgents);
		string severity = "N/A";
		if (currentAgents >= (maxAgents * 0.10) && currentAgents < (maxAgents * 0.25))
			severity = "Mild";
		else if (currentAgents >= (maxAgents * 0.25) && currentAgents < (maxAgents * 0.5))
			severity = "Moderate";
		else if (currentAgents >= (maxAgents * 0.5) && currentAgents < (maxAgents * 0.75))
			severity = "Severe";
		else if (currentAgents >= (maxAgents * 0.75))
			severity = "Critical";

      	return string.Format("%1 %2 of %3", severity, currentAgents, maxAgents);
  	}
};