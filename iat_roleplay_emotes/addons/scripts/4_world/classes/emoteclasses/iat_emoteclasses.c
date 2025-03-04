class IAT_EmoteCoughing extends EmoteBase
{
	void IAT_EmoteCoughing()
	{
		m_ID = EmoteConstants.IAT_EMOTE_COUGH;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
  	}

	// because symptom manager has its own additive callback stuff so we just ignore ours.
	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		if (GetGame().IsDedicatedServer())
		{
			m_Player.GetSymptomManager().QueueUpPrimarySymptom( SymptomIDs.SYMPTOM_COUGH );
		}
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}
}

// doesnt do anything
class IAT_EmoteBlind extends EmoteBase
{
	void IAT_EmoteBlind()
	{
		m_ID = EmoteConstants.IAT_EMOTE_BLINDNESS;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
  	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		m_Player.GetSymptomManager().QueueUpSecondarySymptom(SymptomIDs.SYMPTOM_FEVERBLUR);
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}
}

class IAT_EmoteBulletHit extends EmoteBase
{
	void IAT_EmoteBulletHit()
	{
		m_ID = EmoteConstants.IAT_EMOTE_BULLET_HIT;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
  	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		if (GetGame().IsDedicatedServer())
		{
			m_Player.AddHealth("", "Blood", -350); //do blood dmg
			// try add bleed to specific bone for visual effects
			m_Player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection(IAT_GetDamageZones_Light().GetRandomElement());
		}
		m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_PAIN_HEAVY);
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}

	TStringArray IAT_GetDamageZones_Light()
	{
		return {
			"Head",
			"Neck",
			"Pelvis",
			"Spine",
			"Spine1",
			"Spine2",
			"Spine3",
			"LeftForeArmRoll",
			"RightForeArmRoll",
			"LeftFoot",
			"LeftToeBase",
			"RightFoot",
			"RightToeBase"
		};
	}
}

class IAT_EmoteBleedingSource extends EmoteBase
{
	void IAT_EmoteBleedingSource()
	{
		m_ID = EmoteConstants.IAT_EMOTE_BLEEDING_SOURCE;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
 	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		if (GetGame().IsDedicatedServer())
		{
			m_Player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection(IAT_GetDamageZones_Light().GetRandomElement());
		}
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}

	TStringArray IAT_GetDamageZones_Light()
	{
		return {
			"Head",
			"Neck",
			"Pelvis",
			"Spine",
			"Spine1",
			"Spine2",
			"Spine3",
			"LeftForeArmRoll",
			"RightForeArmRoll",
			"LeftFoot",
			"LeftToeBase",
			"RightFoot",
			"RightToeBase"
		};
	}
}

class IAT_EmoteBloodloss extends EmoteBase
{
	void IAT_EmoteBloodloss()
	{
		m_ID = EmoteConstants.IAT_EMOTE_BLOODLOSS;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		if (GetGame().IsDedicatedServer())
		{
			m_Player.AddHealth("", "Blood", -500); //do 250 blood dmg
		}
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}
}

class IAT_EmoteSneeze extends EmoteBase
{
	void IAT_EmoteSneeze()
	{
		m_ID = EmoteConstants.IAT_EMOTE_SNEEZE;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		m_Player.GetSymptomManager().QueueUpPrimarySymptom( SymptomIDs.SYMPTOM_SNEEZE );
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}
}

class IAT_EmoteFeverBlur extends EmoteBase
{
	void IAT_EmoteFeverBlur()
	{
		m_ID = EmoteConstants.IAT_EMOTE_FEVERBLUR;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
  	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		m_Player.GetSymptomManager().QueueUpSecondarySymptom( SymptomIDs.SYMPTOM_FEVERBLUR );
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}
}

class IAT_EmoteLaughter extends EmoteBase
{
	void IAT_EmoteLaughter()
	{
		m_ID = EmoteConstants.IAT_EMOTE_LAUGHTER;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
  	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		m_Player.GetSymptomManager().QueueUpPrimarySymptom( SymptomIDs.SYMPTOM_LAUGHTER );
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}
}

class IAT_EmoteUnconscious extends EmoteBase
{
	void IAT_EmoteUnconscious()
	{
		m_ID = EmoteConstants.IAT_EMOTE_UNCONSCIOUS;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
  	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		if (GetGame().IsDedicatedServer())
		{
			m_Player.SetHealth("", "Shock", 0);
			m_Player.GetModifiersManager().ActivateModifier(eModifiers.MDF_UNCONSCIOUSNESS);
		}
	}
}

class IAT_EmoteFreeze extends EmoteBase
{
	void IAT_EmoteFreeze()
	{
		m_ID = EmoteConstants.IAT_EMOTE_FREEZE;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
  	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		m_Player.GetSymptomManager().QueueUpPrimarySymptom( SymptomIDs.SYMPTOM_FREEZE );
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}
}

class IAT_EmoteFreezeChatter extends EmoteBase
{
	void IAT_EmoteFreezeChatter()
	{
		m_ID = EmoteConstants.IAT_EMOTE_FREEZE_CHATTER;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
  	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_FREEZE_RATTLE);
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}
}

class IAT_EmoteHot extends EmoteBase
{
	void IAT_EmoteHot()
	{
		m_ID = EmoteConstants.IAT_EMOTE_HOT;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
  	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		m_Player.GetSymptomManager().QueueUpPrimarySymptom( SymptomIDs.SYMPTOM_HOT );
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}
}

class IAT_EmoteLegBreak extends EmoteBase
{
	void IAT_EmoteLegBreak()
	{
		m_ID = EmoteConstants.IAT_EMOTE_LEGBREAK;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
  	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		if (GetGame().IsDedicatedServer())
		{
			m_Player.GetModifiersManager().ActivateModifier(eModifiers.MDF_BROKEN_LEGS);
		}
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}
}

class IAT_EmotePainLight extends EmoteBase
{
	void IAT_EmotePainLight()
	{
		m_ID = EmoteConstants.IAT_EMOTE_PAIN_LIGHT;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_PAIN_LIGHT);
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}
}

class IAT_EmotePainHeavy extends EmoteBase
{
	void IAT_EmotePainHeavy()
	{
		m_ID = EmoteConstants.IAT_EMOTE_PAIN_HEAVY;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_PAIN_HEAVY);
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}
}

// doesnt do anything
class IAT_EmoteShiver extends EmoteBase
{
	void IAT_EmoteShiver()
	{
		m_ID = EmoteConstants.IAT_EMOTE_SHIVER;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_HAND_SHIVER);
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}
}

// doesnt do anything
class IAT_EmoteHeavyMetalPoison extends EmoteBase
{
	void IAT_EmoteHeavyMetalPoison()
	{
		m_ID = EmoteConstants.IAT_EMOTE_HEAVYMETALPOISON;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		m_Player.GetSymptomManager().QueueUpSecondarySymptom(SymptomIDs.SYMPTOM_HMP_SEVERE);
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}
}

class IAT_EmoteHeavyGasp extends EmoteBase
{
	void IAT_EmoteHeavyGasp()
	{
		m_ID = EmoteConstants.IAT_EMOTE_GASP;
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = 0;
		m_FullbodyCallbackUID = 0;
		m_HideItemInHands = false;
	}

	override bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return true;
	}

  	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
		m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_GASP);
		m_Player.SetInventorySoftLock(false);
		m_Player.GetEmoteManager().SetEmoteLockState(false);
	}
}

// // custom code to make sleeping "cover the head" so vision is blocked
// modded class IAT_EmoteLyingDown
// {
// 	override void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
// 	{
//     m_Player.GetEmoteManager().m_IsLayDown = true;
// 	}
// }