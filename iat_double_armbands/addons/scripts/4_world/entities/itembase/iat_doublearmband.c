class IAT_DoubleArmband_ColorBase extends Armband_ColorBase
{
	bool IAT_IsEventArmband()
	{
		return false;
	}
};

class IAT_DoubleArmband_Event extends IAT_DoubleArmband_ColorBase
{
	// cant remove the armband manually
	override bool CanDetachAttachment (EntityAI parent)
	{
		#ifdef Gearstand
		if (parent.IsInherited(GS_Gearstand))
		{
			return true;
		}
		#endif
		return false;
	}
	// if cut up, or somehow detached, delete this item
	override void OnWasDetached( EntityAI parent, int slot_id )
    {
		super.OnWasDetached(parent, slot_id);
		// server side call
		if (GetGame().IsDedicatedServer())
		{
			// only delete from the player
			PlayerBase player;
			if (Class.CastTo(player, parent.GetHierarchyRootPlayer()))
			{
        		DeleteSafe();
			}
		}
    }
	// epi effect
	override void OnWasAttached( EntityAI parent, int slot_id )
	{
		super.OnWasAttached( parent, slot_id );
		if (GetGame().IsDedicatedServer())
		{
			PlayerBase player;
			if (Class.CastTo(player, parent.GetHierarchyRootPlayer()))
			{
				if( player.GetModifiersManager().IsModifierActive(eModifiers.MDF_EPINEPHRINE))//effectively resets the timer
				{
					player.GetModifiersManager().DeactivateModifier(eModifiers.MDF_EPINEPHRINE);
				}
				player.GetModifiersManager().ActivateModifier(eModifiers.MDF_EPINEPHRINE);
				player.GetStatWater().Set(player.GetStatWater().GetMax());
				player.GetStatEnergy().Set(player.GetStatEnergy().GetMax());
			}
		}
	}
	// signal to the playerbase that this armband is and event one so ruin gear on death
	override bool IAT_IsEventArmband()
	{
		return true;
	}
};

class IAT_DoubleArmband_White extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Yellow extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Orange extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Red extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Green extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Pink extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Blue extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Black extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Chernarus extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Chedaki extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_NAPA extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_CDF extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Livonia extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Altis extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_SSahrani extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_NSahrani extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_DayZ extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_LivoniaArmy extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Bohemia extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_APA extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_UEC extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Pirates extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Cannibals extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Bear extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Wolf extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_BabyDeer extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Rooster extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_LivoniaPolice extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_CMC extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_TEC extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_CHEL extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Zenit extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_HunterZ extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_BrainZ extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Refuge extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_RSTA extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Snake extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Crook extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Rex extends IAT_DoubleArmband_ColorBase{};
class IAT_DoubleArmband_Zagorky extends IAT_DoubleArmband_ColorBase{};