// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! R-001: slower illness effects through public modifier and symptom entry points.
// Integration: diagnostic engine fixture; isolates stomach, agents, and symptom queues.
// Documentation: iat_enhanced_medical/tests/VERIFICATION.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_IllnessCase : IAT_EM_PlayerCase
{
	protected int m_Mode;
	protected ref PlayerStomach m_OldStomach;
	protected ref PlayerAgentPool m_OldAgentPool;
	protected ref SymptomManager m_OldSymptoms;
	protected ModifierBase m_Disease;
	protected bool m_OldDiseaseActive;
	protected bool m_DiseaseChanged;
	protected float m_OldToxicity;
	protected bool m_OldVomitRecovery;
	protected bool m_OldVomitDepletion;
	protected ModifierBase m_Contamination;
	protected bool m_OldContaminationActive;

	void IAT_EM_IllnessCase(string caseName, int mode)
	{
		m_Suite = "Illnesses";
		m_Name = caseName;
		m_Mode = mode;
	}

	override bool Prepare()
	{
		if (!super.Prepare()) return false;
		if (!m_Ready) return true;
		m_OldStomach = m_Player.m_PlayerStomach;
		m_OldAgentPool = m_Player.m_AgentPool;
		m_OldSymptoms = m_Player.m_SymptomManager;
		m_OldToxicity = m_Player.GetStatToxicity().Get();
		m_OldVomitRecovery = m_Player.GetStaminaHandler().m_ActiveRecoveryModifiers.Find(EStaminaMultiplierTypes.VOMIT_EXHAUSTION) >= 0;
		m_OldVomitDepletion = m_Player.GetStaminaHandler().m_ActiveDepletionModifiers.Find(EStaminaMultiplierTypes.VOMIT_EXHAUSTION) >= 0;
		m_Player.m_PlayerStomach = new PlayerStomach(m_Player);
		m_Player.m_AgentPool = new PlayerAgentPool(m_Player);
		m_Player.m_SymptomManager = new SymptomManager(m_Player);
		m_Player.GetStatWater().Set(5000);
		m_Player.GetStatEnergy().Set(5000);
		m_Player.SetHealth("", "Blood", 5000);
		m_Player.SetHealth("", "Health", 90);
		return true;
	}

	void EnableDisease(int id)
	{
		m_Disease = m_Player.GetModifiersManager().GetModifier(id);
		m_OldDiseaseActive = m_Disease.m_IsActive;
		m_Disease.m_IsActive = true;
		m_DiseaseChanged = true;
	}

	void PrimeTick(ModifierBase modifier)
	{
		modifier.InitBase(m_Player, m_Player.GetModifiersManager());
		modifier.m_IsActive = true;
		modifier.m_TickType = eModifiersTickType.TICK;
	}

	override bool Execute()
	{
		if (!m_Ready) return true;
		if (m_Mode == 0)
		{
			WoundInfectStage2Mdfr wound = new WoundInfectStage2Mdfr;
			PrimeTick(wound);
			float regen = m_Player.GetHealthRegenSpeed();
			wound.Tick(15);
			float damage = 90 - m_Player.GetHealth("", "Health");
			float netDamagePerSecond = damage / 15 - regen;
			float projectedSeconds = 100 / netDamagePerSecond;
			Check(projectedSeconds >= 2700 && projectedSeconds <= 3600, "Stage-two infection net damage allows 45-60 minutes from 100 Health", "2700..3600 seconds", projectedSeconds.ToString());
			Check(damage > 0, "Untreated wound infection remains harmful", "positive damage", damage.ToString());
			return true;
		}
		if (m_Mode == 1)
		{
			m_Player.InsertAgent(eAgents.CHOLERA, 1000);
			CholeraMdfr cholera = new CholeraMdfr;
			PrimeTick(cholera);
			cholera.Tick(10);
			Near(m_Player.GetStatWater().Get(), 4998.5, "Full cholera load drains 0.15 water per second", 0.01);
			Near(m_Player.GetStatEnergy().Get(), 5000, "No vomiting without stomach contents", 0.01);
			return true;
		}
		if (m_Mode == 2)
		{
			PluginTransmissionAgents agents = PluginTransmissionAgents.Cast(GetPlugin(PluginTransmissionAgents));
			Check(agents != null, "Transmission plugin available", "true", (agents != null).ToString());
			if (agents) Near(agents.GetAgentInvasibilityEx(eAgents.SALMONELLA, m_Player), 0.225, "Registered salmonella growth reduced from 0.75 to 0.225");
			return true;
		}

		m_Player.m_PlayerStomach.AddToStomach(Liquid.GetLiquidClassname(LIQUID_WATER), 1000);
		m_Player.m_PlayerStomach.Update(0);
		Near(m_Player.GetStomach().GetStomachVolume(), 1000, "Fixture contains 1000 mL water", 0.01);
		VomitSymptom vomit;
		if (m_Mode == 3 || m_Mode == 4)
		{
			int diseaseId = eModifiers.MDF_CHOLERA;
			int agentId = eAgents.CHOLERA;
			int count = 1000;
			if (m_Mode == 4) { diseaseId = eModifiers.MDF_SALMONELLA; agentId = eAgents.SALMONELLA; count = 300; }
			EnableDisease(diseaseId);
			m_Player.InsertAgent(agentId, count);
			// Find and replay a deterministic first roll below either disease's base chance.
			int seed;
			for (seed = 0; seed < 1000; seed++)
			{
				Math.Randomize(seed);
				if (Math.RandomInt(0, 100) < 10) break;
			}
			Check(seed < 1000, "Deterministic vomit roll found", "seed below 1000", seed.ToString());
			ModifierBase illness;
			if (m_Mode == 3) illness = new CholeraMdfr;
			else illness = new SalmonellaMdfr;
			PrimeTick(illness);
			Math.Randomize(seed);
			illness.Tick(4);
			float expectedWater = 4865;
			if (m_Mode == 3) expectedWater = 4864.4;
			Near(m_Player.GetStatWater().Get(), expectedWater, "Illness vomit costs 135 water plus cholera's continuous drain", 0.01);
			Near(m_Player.GetStatEnergy().Get(), 4907, "Illness vomit costs 93 energy", 0.01);
			array<ref SymptomBase> queue = m_Player.GetSymptomManager().m_SymptomQueuePrimary;
			foreach (SymptomBase symptom : queue)
			{
				if (symptom.GetType() == SymptomIDs.SYMPTOM_VOMIT) vomit = VomitSymptom.Cast(symptom);
			}
			Check(vomit != null, "Vanilla illness tick queues vomiting", "true", (vomit != null).ToString());
		}
		else
		{
			vomit = new VomitSymptom;
			vomit.Init(m_Player.GetSymptomManager(), m_Player, 0);
			if (m_Mode == 7)
			{
				EnableDisease(eModifiers.MDF_CHOLERA);
				m_Contamination = m_Player.GetModifiersManager().GetModifier(eModifiers.MDF_CONTAMINATION2);
				m_OldContaminationActive = m_Contamination.m_IsActive;
				m_Contamination.m_IsActive = true;
			}
			if (m_Mode == 5 || m_Mode == 7) vomit.SetParam(new Param1<float>(50));
			else vomit.SetDuration(5);
		}
		if (!vomit) return true;
		vomit.OnAnimationStart();
		float expectedVolume = 805;
		if (m_Mode == 4) expectedVolume = 850;
		if (m_Mode == 5) expectedVolume = 500;
		if (m_Mode == 6) expectedVolume = 750;
		if (m_Mode == 7) expectedVolume = 500;
		Near(m_Player.GetStomach().GetStomachVolume(), expectedVolume, "Illness stomach losses reduced; ordinary vomiting retains vanilla behavior", 0.01);
		return true;
	}

	override bool Cleanup()
	{
		if (m_Player && m_OldStomach)
		{
			if (m_DiseaseChanged) m_Disease.m_IsActive = m_OldDiseaseActive;
			if (m_Contamination) m_Contamination.m_IsActive = m_OldContaminationActive;
			if (m_OldVomitRecovery) m_Player.GetStaminaHandler().ActivateRecoveryModifier(EStaminaMultiplierTypes.VOMIT_EXHAUSTION);
			else m_Player.GetStaminaHandler().DeactivateRecoveryModifier(EStaminaMultiplierTypes.VOMIT_EXHAUSTION);
			if (m_OldVomitDepletion) m_Player.GetStaminaHandler().ActivateDepletionModifier(EStaminaMultiplierTypes.VOMIT_EXHAUSTION);
			else m_Player.GetStaminaHandler().DeactivateDepletionModifier(EStaminaMultiplierTypes.VOMIT_EXHAUSTION);
			m_Player.GetStatToxicity().Set(m_OldToxicity);
			m_Player.m_PlayerStomach = m_OldStomach;
			m_Player.m_AgentPool = m_OldAgentPool;
			m_Player.m_SymptomManager = m_OldSymptoms;
			m_OldStomach = null;
			m_OldAgentPool = null;
			m_OldSymptoms = null;
			m_Disease = null;
			m_Contamination = null;
		}
		Math.Randomize(-1);
		return super.Cleanup();
	}
}
#endif
#endif
