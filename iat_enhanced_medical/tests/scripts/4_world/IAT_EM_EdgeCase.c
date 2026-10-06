// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_EdgeCase : IAT_EM_PlayerCase
{
	int m_Mode;
	void IAT_EM_EdgeCase(string caseName, int mode) { m_Suite = "MedicalEdges"; m_Name = caseName; m_Mode = mode; }
	override bool Execute()
	{
		if (!m_Ready) return true;
		int arm = m_Medical.IAT_GetBulletBoneBit("leftarm");
		int hand = m_Medical.IAT_GetBulletBoneBit("leftforearmroll");
		if (m_Mode == 0)
		{
			m_State.m_DressedWounds = arm | hand;
			Blood("LeftArm", 1); Blood("LeftHand", 0.75);
			m_Medical.ReopenDressedWounds(m_Player, "WZBandageLArm");
			EqualInt(m_State.m_DressedWounds, 0, "Healed entry cleared and incomplete entry reopened");
			EqualInt(m_Player.GetBleedingBits(), hand, "Only incomplete bone reopens without dressing");
		}
		if (m_Mode == 1)
		{
			if (!Dress("LeftArm")) return true;
			m_Manager.AttemptAddBleedingSourceBySelection("leftarm");
			m_State.m_DressedWounds = arm | hand;
			m_Medical.UpdateHealing(m_Player);
			EqualInt(m_State.m_DressedWounds, arm, "Active source preserves history even at full zone Blood");
		}
		if (m_Mode == 2)
		{
			Blood("LeftArm", 0.75);
			m_State.m_DressedWounds = arm;
			m_Manager.AttemptAddBleedingSourceBySelection("leftarm");
			// Simulate a stored treated bit whose source already exists.
			m_State.m_DressedWounds = arm;
			m_Medical.ReopenDressedWounds(m_Player, "WZBandageLArm");
			EqualInt(m_State.m_DressedWounds, arm, "Failed source creation preserves treated bit");
		}
		if (m_Mode == 3)
		{
			m_State.m_DressedWounds = arm;
			m_Medical.ReopenDressedWounds(m_Player, "unknownSlot");
			EqualInt(m_State.m_DressedWounds, arm, "Unknown slot does not change history");
			Check(!m_Medical.IAT_EM_TestCanRemove(m_Player, "unknownSlot"), "Unknown slot cannot be removed", "false", "checked");
		}
		if (m_Mode == 4)
		{
			ItemBase material = Item("BandageDressing");
			EntityAI wrong = m_Player.GetInventory().CreateAttachmentEx("IAT_EM_IncompatibleDressing", InventorySlots.GetSlotIdFromString("WZBandageLArm"));
			Check(wrong != null, "Create incompatible occupied-slot fixture", "true", (wrong != null).ToString());
			if (!wrong || !material) return true;
			m_Items.Insert(wrong);
			m_Manager.AttemptAddBleedingSourceBySelection("leftarm");
			Check(!m_Medical.IsWearingBandage(m_Player, "LeftArm"), "Nonmedical attachment is not a usable dressing", "false", "checked");
			Check(!m_Medical.PrepareDressing(m_Player, material), "Incompatible attachment blocks replacement", "false", "checked");
			Check(!m_Medical.IAT_EM_TestCanRemove(m_Player, "WZBandageLArm"), "Cleanup cannot delete nonmedical attachment", "false", "checked");
		}
		if (m_Mode == 5)
		{
			EntityAI ruined = Dress("LeftArm");
			if (!ruined) return true;
			ruined.SetHealth("", "Health", 0); Blood("LeftArm", 0.25);
			Check(!m_Medical.IsWearingBandage(m_Player, "LeftArm"), "Ruined dressing is unusable", "false", "checked");
			Check(!m_Medical.CanRegenerateZone(m_Player, "LeftArm"), "Ruined covering does not permit severe regeneration", "false", "checked");
		}
		if (m_Mode == 6)
		{
			// Detach notification exercises the medical plugin boundary; the
			// offline PlayerBase callback itself remains dedicated-only.
			EntityAI detached = Item(m_Medical.IAT_GetBandageClass("LeftArm"));
			if (!detached) return true;
			Blood("LeftArm", 0.75); m_State.m_DressedWounds = arm;
			m_Medical.OnBandageDetached(m_Player, detached, "WZBandageLArm");
			EqualInt(m_Player.GetBleedingBits(), arm, "Medical detach notification reopens wound");
		}
		if (m_Mode == 7)
		{
			ItemBase other = Item("Pliers");
			if (!other) return true;
			Blood("LeftArm", 0.75); m_State.m_DressedWounds = arm;
			m_Medical.OnBandageDetached(m_Player, null, "WZBandageLArm");
			m_Medical.OnBandageDetached(m_Player, other, "WZBandageLArm");
			m_Medical.OnBandageAttached(m_Player, null, "WZBandageLArm");
			m_Medical.OnBandageAttached(m_Player, other, "WZBandageLArm");
			EqualInt(m_Player.GetBleedingBits(), 0, "Unrelated attachment events do not reopen wounds");
			EqualInt(m_State.m_DressedWounds, arm, "Unrelated attachment events preserve history");
		}
		if (m_Mode == 8)
		{
			ScriptReadWriteContext buffer = new ScriptReadWriteContext;
			ParamsWriteContext writer = buffer.GetWriteContext();
			writer.Write(1); writer.Write(1); writer.Write(4);
			IAT_MedicalState restored = new IAT_MedicalState;
			int previous = m_Medical.IAT_EM_TestSetRegisteredMask(0);
			bool loaded = restored.Load(buffer.GetReadContext());
			m_Medical.IAT_EM_TestSetRegisteredMask(previous);
			Check(!loaded, "Loading without bleeding definitions rejected", "false", loaded.ToString());
			Check(restored.m_LoadResult == "bleeding_definitions_unavailable", "Unavailable definitions diagnostic", "bleeding_definitions_unavailable", restored.m_LoadResult);
		}
		if (m_Mode == 9)
		{
			BloodRegenMdfr modifier = BloodRegenMdfr.Cast(m_Player.GetModifiersManager().GetModifier(eModifiers.MDF_BLOOD_REGEN));
			Check(modifier != null, "Existing blood regeneration modifier", "true", (modifier != null).ToString());
			if (!modifier) return true;
			m_Player.SetHealth("", "Blood", 5000);
			Check(!m_Medical.IAT_NeedsMedicalTick(m_Player), "Full zones without dressings need no tick", "false", "checked");
			Check(modifier.DeactivateCondition(m_Player), "No medical work allows deactivation at full blood", "true", "checked");
			if (!Dress("LeftArm")) return true;
			Check(m_Medical.IAT_NeedsMedicalTick(m_Player) && !modifier.DeactivateCondition(m_Player), "Healed dressing keeps cleanup tick at full global blood", "true/not deactivated", "checked");
		}
		if (m_Mode == 10)
		{
			Check(!m_Medical.IsWearingBandage(m_Player, "unknownZone"), "Unknown zone has no usable dressing", "false", "checked");
			Check(!m_Medical.HasBulletInZone(m_Player, "unknownZone"), "Unknown zone has no retained bullet", "false", "checked");
			Check(m_Medical.IAT_EM_TestResolve(m_Player, "BRAIN") == "Head", "Additional anatomy alias resolves case-insensitively", "Head", m_Medical.IAT_EM_TestResolve(m_Player, "BRAIN"));
			Check(m_Medical.IAT_EM_TestResolve(m_Player, "dmgzone_leftfoot") == "LeftFoot", "Config component fallback resolves modded selections", "LeftFoot", m_Medical.IAT_EM_TestResolve(m_Player, "dmgzone_leftfoot"));
			Check(m_Medical.IAT_EM_TestResolve(m_Player, "not_a_component") == "", "Unresolvable anatomy returns empty", "", m_Medical.IAT_EM_TestResolve(m_Player, "not_a_component"));
		}
		return true;
	}
}
#endif
#endif
