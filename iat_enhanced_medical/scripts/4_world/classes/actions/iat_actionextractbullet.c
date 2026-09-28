class IAT_ActionExtractBulletCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(PluginIATMedical.IAT_BULLET_EXTRACTION_SECONDS);
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
		m_Text = "Extract bullet";
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

	void IAT_Extract(ActionData action_data, PlayerBase patient)
	{
		if (!patient || !patient.IsAlive() || !action_data.m_MainItem || action_data.m_MainItem.IsRuined() || !action_data.m_MainItem.IAT_CanExtractBullet())
			return;
		PluginIATMedical medical = PluginIATMedical.Get();
		string zone;
		if (medical && medical.ExtractBullet(patient, zone))
		{
			float hpDamage = Math.Max(0, action_data.m_MainItem.IAT_BulletExtractionHpDmg());
			float healthBefore = patient.GetHealth("", "Health");
			if (hpDamage > 0)
				patient.AddHealth("", "Health", -hpDamage);
			IAT_MedicalLog.Event(patient, "EXTRACTION_HP_DAMAGE", string.Format("tool=%1 damage=%2 before=%3 after=%4", action_data.m_MainItem.GetType(), hpDamage, healthBefore, patient.GetHealth("", "Health")));
			action_data.m_Player.MessageStatus("Removed a retained bullet from " + zone + ".");
			if (patient != action_data.m_Player)
				patient.MessageStatus("A retained bullet was removed from " + zone + ".");
		}
		else
			action_data.m_Player.MessageStatus("No retained bullet was found.");
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		IAT_Extract(action_data, action_data.m_Player);
	}
}

class IAT_ActionExtractBulletTarget : IAT_ActionExtractBulletSelf
{
	void IAT_ActionExtractBulletTarget()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_BANDAGETARGET;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "Extract person's bullet";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}

	override bool HasTarget()
	{
		return true;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!target || !super.ActionCondition(player, target, item))
			return false;
		PlayerBase patient = PlayerBase.Cast(target.GetObject());
		return patient && patient != player && patient.IsAlive() && !patient.IsInVehicle();
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		if (CanReceiveAction(action_data.m_Target))
			IAT_Extract(action_data, PlayerBase.Cast(action_data.m_Target.GetObject()));
	}
}

modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		actions.Insert(IAT_ActionExtractBulletSelf);
		actions.Insert(IAT_ActionExtractBulletTarget);
	}
}
