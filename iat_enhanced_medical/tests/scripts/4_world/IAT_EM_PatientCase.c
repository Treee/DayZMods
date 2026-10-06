// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
// A second real player is necessary for target/corpse cases and for invoking
// persistence hooks without loading over the shared mission player. Its systems
// are initialized by CreatePlayer; tests never construct duplicate managers.
class IAT_EM_PatientCase : IAT_EM_PlayerCase
{
	PlayerBase m_Patient;
	int m_Mode;
	void IAT_EM_PatientCase(string caseName, int mode) { m_Suite = "PlayerIntegration"; m_Name = caseName; m_Mode = mode; }
	override bool Prepare()
	{
		if (!super.Prepare()) return false;
		if (!m_Ready) return true;
		vector position = m_Player.GetPosition() + "3 0 0";
		m_Patient = PlayerBase.Cast(g_Game.CreatePlayer(null, "SurvivorM_Mirek", position, 0, "NONE"));
		Check(m_Patient != null, "Create independent patient with normal player systems", "true", (m_Patient != null).ToString());
		if (m_Patient) m_Patient.m_IAT_EM_TestStateEnabled = true;
		return true;
	}
	override bool Execute()
	{
		if (!m_Ready || !m_Patient) return true;
		IAT_MedicalState state = m_Patient.IAT_GetMedicalState();
		int arm = m_Medical.IAT_GetBulletBoneBit("leftarm");
		state.m_Bullets = arm;
		if (m_Mode == 0)
		{
			ItemBase pliers = Item("Pliers");
			if (!pliers) return true;
			m_Player.SetHealth("", "Health", 90);
			m_Patient.SetHealth("", "Health", 90);
			ActionData data = new ActionData;
			data.m_Player = m_Player; data.m_MainItem = pliers;
			data.m_Target = new ActionTarget(m_Patient, null, -1, "0 0 0", 0);
			IAT_ActionExtractBulletTarget action = new IAT_ActionExtractBulletTarget;
			Check(action.ActionCondition(m_Player, data.m_Target, pliers), "Live other patient is offered target extraction", "true", "checked");
			action.IAT_Extract(data, m_Patient);
			EqualInt(state.m_Bullets, 0, "Target completion removes patient's bullet");
			Near(m_Patient.GetHealth("", "Health"), 80, "Target extraction damages patient");
			Near(m_Player.GetHealth("", "Health"), 90, "Target extraction does not damage actor");
		}
		if (m_Mode == 1)
		{
			ItemBase pliersDead = Item("Pliers");
			if (!pliersDead) return true;
			m_Patient.SetHealth("", "Health", 0);
			string zone = "stale";
			Check(!m_Medical.ExtractBullet(m_Patient, zone) && zone == "", "Dead patient rejected by medical extraction", "false/empty", zone);
			EqualInt(state.m_Bullets, arm, "Dead extraction preserves retained bullet");
			IAT_ActionExtractBulletTarget target = new IAT_ActionExtractBulletTarget;
			IAT_ActionExtractBulletSelf self = new IAT_ActionExtractBulletSelf;
			ActionTarget corpse = new ActionTarget(m_Patient, null, -1, "0 0 0", 0);
			Check(!target.ActionCondition(m_Player, corpse, pliersDead), "Dead target is unavailable", "false", "checked");
			Check(!self.ActionCondition(m_Patient, null, pliersDead), "Dead actor is unavailable", "false", "checked");
			m_Medical.UpdateHealing(m_Patient);
			m_Medical.ReopenDressedWounds(m_Patient, "WZBandageLArm");
			Check(!m_Medical.IAT_EM_TestCanRemove(m_Patient, "WZBandageLArm"), "Dead player cannot schedule dressing removal", "false", "checked");
			ActionData deadData = new ActionData;
			deadData.m_Player = m_Player; deadData.m_MainItem = pliersDead;
			self.IAT_Extract(deadData, m_Patient);
			EqualInt(state.m_Bullets, arm, "Action completion rejects dead patient");
		}
		if (m_Mode == 2)
		{
			state.m_DressedWounds = 65540;
			ScriptReadWriteContext buffer = new ScriptReadWriteContext;
			ParamsWriteContext writer = buffer.GetWriteContext();
			m_Patient.OnStoreSave(writer);
			writer.Write(9876);
			state.m_Bullets = 0; state.m_DressedWounds = 0;
			ParamsReadContext reader = buffer.GetReadContext();
			bool loaded = m_Patient.OnStoreLoad(reader, g_Game.SaveVersion());
			Check(loaded, "Player save/load hooks accept complete current record", "true", loaded.ToString());
			EqualInt(state.m_Bullets, arm, "Player hooks restore appended bullet mask");
			EqualInt(state.m_DressedWounds, 65540, "Player hooks restore appended dressed mask");
			int sentinel;
			reader.Read(sentinel);
			EqualInt(sentinel, 9876, "Player hook reads exactly the appended medical record");
			m_Patient.AfterStoreLoad();
			EqualInt(state.m_Bullets, arm, "AfterStoreLoad preserves medical state");
		}
		if (m_Mode == 3)
		{
			Check(!g_Game.IsDedicatedServer(), "Fixture is nondedicated", "false", g_Game.IsDedicatedServer().ToString());
			Check(m_Patient.IAT_EM_TestOriginalState() == null, "Production state getter remains dedicated-only", "null", (m_Patient.IAT_EM_TestOriginalState() != null).ToString());
			EntityAI bandage = Item(m_Medical.IAT_GetBandageClass("LeftArm"));
			if (!bandage) return true;
			m_Patient.SetHealth("LeftArm", "Blood", 75); state.m_DressedWounds = arm;
			m_Patient.EEItemAttached(bandage, "WZBandageLArm");
			m_Patient.EEItemDetached(bandage, "WZBandageLArm");
			EqualInt(state.m_DressedWounds, arm, "Nondedicated attachment hooks do not perform medical treatment");
			EqualInt(m_Patient.GetBleedingBits(), 0, "Nondedicated detach hook does not reopen medical wounds");
		}
		return true;
	}
	override bool Cleanup()
	{
		if (m_Patient)
		{
			IAT_MedicalState state = m_Patient.IAT_GetMedicalState();
			state.m_Bullets = 0; state.m_DressedWounds = 0;
			if (m_Patient.GetBleedingManagerServer()) m_Patient.GetBleedingManagerServer().RemoveAllSources();
			g_Game.ObjectDelete(m_Patient);
			m_Patient = null;
		}
		return super.Cleanup();
	}
}
#endif
#endif
