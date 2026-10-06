// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_VomitCase : IAT_EM_PlayerCase
{
	void IAT_EM_VomitCase() { m_Suite = "Symptoms"; m_Name = "VomitActivationCommands"; }
	override bool Execute()
	{
		if (!m_Ready) return true;
		SymptomManager manager = m_Player.GetSymptomManager();
		int oldCommand = manager.m_CurrentCommandID;
		VomitSymptom symptom = VomitSymptom.Cast(manager.m_AvailableSymptoms.Get(SymptomIDs.SYMPTOM_VOMIT));
		Check(symptom != null, "Existing vomit symptom", "true", (symptom != null).ToString());
		if (!symptom) return true;
		manager.m_CurrentCommandID = DayZPlayerConstants.COMMANDID_MOVE;
		Check(symptom.CanActivate(), "Vanilla movement command remains allowed", "true", "checked");
		manager.m_CurrentCommandID = DayZPlayerConstants.COMMANDID_ACTION;
		Check(symptom.CanActivate(), "Vanilla action command remains allowed", "true", "checked");
		manager.m_CurrentCommandID = DayZPlayerConstants.STANCEMASK_CROUCH;
		Check(symptom.CanActivate(), "Current code permits crouch-mask command value", "true", "checked");
		manager.m_CurrentCommandID = -123;
		Check(!symptom.CanActivate(), "Other commands rejected", "false", "checked");
		manager.m_CurrentCommandID = oldCommand;
		return true;
	}
}
#endif
#endif
