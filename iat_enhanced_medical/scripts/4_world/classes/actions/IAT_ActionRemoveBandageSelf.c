// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Medical action availability and server completion.
// Integration: action dispatch and patient targeting.
// Documentation: iat_enhanced_medical/README.md

class IAT_ActionRemoveBandageCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(IAT_PluginMedical.IAT_BANDAGE_REMOVAL_SECONDS);
	}
}

class IAT_ActionRemoveBandageSelf : ActionContinuousBase
{
	protected static ref TStringArray s_IAT_BandageSlots = {"WZBandageHead", "WZBandageChest", "WZBandageLArm", "WZBandageRArm", "WZBandageLLeg", "WZBandageRLeg"};

	void IAT_ActionRemoveBandageSelf()
	{
		m_CallbackClass = IAT_ActionRemoveBandageCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_BANDAGE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#IAT_EM_ACTION_REMOVE_BANDAGE_SELF";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}

	override bool HasTarget()
	{
		return false;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		// Worn attachments are replicated, so availability needs no medical-state mirror.
		return player && player.IsAlive() && !player.IsInVehicle() && item && !item.IsRuined() && item.IAT_CanRemoveBandage() && IAT_FindBandageSlot(player) != "";
	}

	protected static string IAT_FindBandageSlot(PlayerBase patient)
	{
		if (!patient)
			return "";
		foreach (string slot : s_IAT_BandageSlots)
		{
			EntityAI bandage = patient.FindAttachmentBySlotName(slot);
			if (bandage && bandage.IsInherited(WZ_Bandage_Base))
				return slot;
		}
		return "";
	}

	void IAT_Remove(ActionData actionData, PlayerBase patient)
	{
		if (!actionData.m_Player || !actionData.m_Player.IsAlive() || actionData.m_Player.IsInVehicle() || !patient || !patient.IsAlive() || patient.IsInVehicle())
			return;
		ItemBase tool = actionData.m_MainItem;
		if (!tool || tool.IsRuined() || !tool.IAT_CanRemoveBandage())
			return;
		string slot = IAT_FindBandageSlot(patient);
		IAT_PluginMedical medical;
		if (slot == "" || !Class.CastTo(medical, GetPlugin(IAT_PluginMedical)))
			return;
		EntityAI bandage = patient.FindAttachmentBySlotName(slot);
		medical.LogEvent(patient, "BANDAGE_MANUAL_REMOVAL", "slot=" + slot + " tool=" + tool.GetType());
		// Cutting destroys the used dressing through the inventory-safe deletion path.
		bandage.DeleteSafe();
		// Deletion may be queued; detach hooks and the healing tick reconcile once it completes.
		// This immediate attempt is idempotent and only reopens wounds if the dressing is gone.
		medical.ReopenDressedWounds(patient, slot);
		actionData.m_Player.MessageStatus("#IAT_EM_BANDAGE_REMOVED");
		if (patient != actionData.m_Player)
			patient.MessageStatus("#IAT_EM_PATIENT_BANDAGE_REMOVED");
	}

	override protected void OnFinishProgressServer(ActionData action_data)
	{
		IAT_Remove(action_data, action_data.m_Player);
	}
}
