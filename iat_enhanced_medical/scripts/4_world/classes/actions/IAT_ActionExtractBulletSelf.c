// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Medical action availability and server completion.
// Integration: action dispatch and patient targeting.
// Documentation: iat_enhanced_medical/README.md

class IAT_ActionExtractBulletCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(IAT_PluginMedical.IAT_BULLET_EXTRACTION_SECONDS);
	}
}

class IAT_ActionExtractBulletSelf : ActionContinuousBase
{
	void IAT_ActionExtractBulletSelf()
	{
		m_CallbackClass = IAT_ActionExtractBulletCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_STITCHUPSELF;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#IAT_EM_ACTION_EXTRACT_BULLET_SELF";
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
		// No client medical-state mirror: availability is deliberately generic.
		return player.IsAlive() && !player.IsInVehicle() && item && item.IAT_CanExtractBullet();
	}

	void IAT_Extract(ActionData actionData, PlayerBase patient)
	{
		if (!patient || !patient.IsAlive() || !actionData.m_MainItem || actionData.m_MainItem.IsRuined() || !actionData.m_MainItem.IAT_CanExtractBullet())
			return;
		IAT_PluginMedical medical;
		string zone;
		if (Class.CastTo(medical, GetPlugin(IAT_PluginMedical)) && medical.ExtractBullet(patient, zone))
		{
			float hpDamage = Math.Max(0, actionData.m_MainItem.IAT_BulletExtractionHpDmg());
			float healthBefore = patient.GetHealth("", "Health");
			if (hpDamage > 0)
				patient.AddHealth("", "Health", -hpDamage);
			medical.LogEvent(patient, "EXTRACTION_HP_DAMAGE", string.Format("tool=%1 damage=%2 before=%3 after=%4", actionData.m_MainItem.GetType(), hpDamage, healthBefore, patient.GetHealth("", "Health")));
			actionData.m_Player.MessageStatus("#IAT_EM_BULLET_REMOVED_" + zone);
			if (patient != actionData.m_Player)
				patient.MessageStatus("#IAT_EM_PATIENT_BULLET_REMOVED_" + zone);
		}
		else
			actionData.m_Player.MessageStatus("#IAT_EM_NO_RETAINED_BULLET");
	}

	override protected void OnFinishProgressServer(ActionData action_data)
	{
		IAT_Extract(action_data, action_data.m_Player);
	}
}
