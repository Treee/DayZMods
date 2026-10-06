// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_RemovalConditionsCase : IAT_EM_PlayerCase
{
	void IAT_EM_RemovalConditionsCase() { m_Suite = "ManualRemoval"; m_Name = "KnifeRemovalAvailabilityAndRegistration"; }
	override bool Execute()
	{
		if (!m_Ready) return true;
		IAT_ActionRemoveBandageSelf action = new IAT_ActionRemoveBandageSelf;
		IAT_ActionRemoveBandageTarget target = new IAT_ActionRemoveBandageTarget;
		Check(!action.HasTarget() && target.HasTarget(), "Distinct self and target actions", "false/true", "checked");
		ItemBase knife = Item("HuntingKnife");
		if (!knife) return true;
		Check(!action.ActionCondition(m_Player, null, knife), "No dressing offers no self action", "false", "checked");
		if (!Dress("LeftArm")) return true;
		Check(action.ActionCondition(m_Player, null, knife), "Knife and dressing offer self action without target", "true", "checked");
		Check(!target.ActionCondition(m_Player, null, knife), "Missing target rejected", "false", "checked");
		ActionTarget same = new ActionTarget(m_Player, null, -1, "0 0 0", 0);
		Check(!target.ActionCondition(m_Player, same, knife), "Self is not another patient", "false", "checked");
		ItemBase pliers = Item("Pliers");
		Check(!action.ActionCondition(m_Player, null, pliers), "Pliers cannot cut dressing", "false", "checked");
		Check(!action.ActionCondition(m_Player, null, null), "Missing tool rejected", "false", "checked");
		TStringArray types = {"HuntingKnife", "CombatKnife", "KitchenKnife", "SteakKnife", "StoneKnife", "BoneKnife", "FangeKnife", "KukriKnife"};
		foreach (string type : types)
		{
			ItemBase tool = Item(type);
			if (!tool) continue;
			Check(tool.IAT_CanRemoveBandage(), "Knife capability: " + type, "true", "checked");
			array<ActionBase_Basic> actions;
			tool.GetActions(action.GetInputType(), actions);
			bool foundSelf = false;
			bool foundTarget = false;
			if (actions) foreach (ActionBase_Basic registered : actions)
			{
				if (registered.Type() == IAT_ActionRemoveBandageSelf) foundSelf = true;
				if (registered.Type() == IAT_ActionRemoveBandageTarget) foundTarget = true;
			}
			Check(foundSelf && foundTarget, "Both actions registered on " + type, "true/true", "checked");
		}
		knife.SetHealth("", "Health", 0);
		Check(!action.ActionCondition(m_Player, null, knife), "Ruined knife rejected", "false", "checked");
		return true;
	}
}
#endif
#endif
