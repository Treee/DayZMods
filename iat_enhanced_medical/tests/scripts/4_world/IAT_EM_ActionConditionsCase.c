// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_ActionConditionsCase : IAT_EM_PlayerCase
{
	void IAT_EM_ActionConditionsCase() { m_Suite = "Actions"; m_Name = "ExtractionAvailabilityAndRegistration"; }
	override bool Execute()
	{
		if (!m_Ready) return true;
		ItemBase tool = Item("Pliers");
		ItemBase material = Item("BandageDressing");
		if (!tool || !material) return true;
		IAT_ActionExtractBulletSelf self = new IAT_ActionExtractBulletSelf;
		IAT_ActionExtractBulletTarget target = new IAT_ActionExtractBulletTarget;
		self.CreateConditionComponents(); target.CreateConditionComponents();
		Check(!self.HasTarget() && target.HasTarget(), "Self and target action identities", "false/true", "checked");
		Check(self.ActionCondition(m_Player, null, tool), "Self action offered without retained-bullet client check", "true", "checked");
		Check(!self.ActionCondition(m_Player, null, material), "Ordinary item cannot extract", "false", "checked");
		Check(!self.ActionCondition(m_Player, null, null), "Missing item cannot extract", "false", "checked");
		Check(!target.ActionCondition(m_Player, null, tool), "Missing target rejected", "false", "checked");
		ActionTarget same = new ActionTarget(m_Player, null, -1, "0 0 0", 0);
		Check(!target.ActionCondition(m_Player, same, tool), "Target action cannot target self", "false", "checked");
		ActionTarget object = new ActionTarget(material, null, -1, "0 0 0", 0);
		Check(!target.ActionCondition(m_Player, object, tool), "Target action requires another player", "false", "checked");
		array<ActionBase_Basic> actions;
		tool.GetActions(self.GetInputType(), actions);
		bool foundSelf, foundTarget;
		if (actions)
		{
			foreach (ActionBase_Basic registered : actions)
			{
				if (registered.Type() == IAT_ActionExtractBulletSelf) foundSelf = true;
				if (registered.Type() == IAT_ActionExtractBulletTarget) foundTarget = true;
			}
		}
		Check(foundSelf && foundTarget, "Pliers registers both extraction actions through ActionConstructor", "true/true", foundSelf.ToString() + "/" + foundTarget.ToString());
		return true;
	}
}
#endif
#endif
