modded class PluginAdminLog
{
	void HorseKilled( Horse_Base horse, Object source )  // PlayerBase.c
	{
		if (!horse || !source)
		{
	        LogPrint("DEBUG: HorseKilled() horse/source does not exist");
	        return;
    	}

		if (horse == source)	// deaths not caused by another object (starvation, dehydration)
		{
			PlayerBase horseRider;
			PlayerBase horseOwner;
			if (Class.CastTo(horseRider, IAT_GetPlayerByEntityID(horse.GetRiderId())))
			{
				string horseRiderPrefix = GetPlayerPrefix( horseRider, horseRider.GetIdentity() );
				LogPrint(string.Format("%1 died. Ridden by %2", horse.GetType(), horseRiderPrefix));
			}
			else if (Class.CastTo(horseOwner, IAT_GetPlayerByEntityID(horse.GetOwnerId())))
			{
				string horseOwnerPrefix = GetPlayerPrefix( horseOwner, horseOwner.GetIdentity() );
				LogPrint(string.Format("%1 died. Not ridden but owned by %2", horse.GetType(), horseOwnerPrefix));
			}
			else
			{
				LogPrint(string.Format("Unowned %1 died. Killed by %2", horse.GetType(), source.GetType()));
			}
		}
		else
		{
			LogPrint(string.Format("%1 died. Killed by %2", horse.GetType(), source.GetType()));
		}
	}


	void HorseHitBy(TotalDamageResult damageResult, int damageType, Horse_Base horse, EntityAI source, int component, string dmgZone, string ammo)
	{
		if ( horse && source )
		{
			string horsePrefix = string.Format("%1 [HP: %2]", horse.GetType(), horse.GetHealth());
			string damageSourcePrefix;
			m_HitMessage = GetHitMessage( damageResult, component, dmgZone, ammo );
			PlayerBase playerSource;

			if ( source.IsPlayer() )// Fists
				playerSource = PlayerBase.Cast( source );
			else
				playerSource = PlayerBase.Cast( source.GetHierarchyParent() );

			if (playerSource)
				damageSourcePrefix = GetPlayerPrefix( playerSource ,  playerSource.GetIdentity() );

			switch ( damageType )
			{
				case DamageType.CLOSE_COMBAT:	// Player melee, animals, infected
					if (source.IsZombie() || source.IsAnimal())  // Infected & Animals
					{
						if (m_HitFilter == 1)
							break;

						LogPrint(string.Format("%1 hit by %2%3", horsePrefix, source.GetDisplayName(), m_HitMessage));
					}
					else if (source.IsPlayer())// Fists
					{
						LogPrint(string.Format("%1 hit by %2%3", horsePrefix, damageSourcePrefix, m_HitMessage));
					}
					else if ( playerSource && (source.IsMeleeWeapon() || source.IsWeapon())) // Melee weapons
					{
						LogPrint(string.Format("%1 hit by %2%3 with %4", horsePrefix, damageSourcePrefix, m_HitMessage, source.GetDisplayName()));
					}
					else
					{
						LogPrint(string.Format("%1 hit by %2%3", horsePrefix, source.GetType(), m_HitMessage));
					}
					break;

				case DamageType.FIRE_ARM:	// Player ranged
					if ( source.IsWeapon() && playerSource )
					{
						m_Distance = vector.Distance( horse.GetPosition(), playerSource.GetPosition() );
						LogPrint(string.Format("%1 hit by %2%3 with %4 from %5 meters", horsePrefix, damageSourcePrefix, m_HitMessage, source.GetDisplayName(), m_Distance));
					}
					else
					{
						LogPrint(string.Format("%1 hit by %2%3", horsePrefix, source.GetType(), m_HitMessage));
					}
					break;

				case DamageType.EXPLOSION:	// Explosion
					LogPrint(string.Format("%1 hit by explosion (%2)", horsePrefix, ammo));
					break;

				case DamageType.STUN: 		// unused atm
					LogPrint(string.Format("%1 stunned by %2", horsePrefix, ammo));
					break;

				case DamageType.CUSTOM:		// Others (Vehicle hit, fall, fireplace, barbed wire ...)
					float globalHealthDamage = damageResult.GetDamage("", "Health");
					if (ammo == DayZPlayerImplementFallDamage.FALL_DAMAGE_AMMO_HEALTH || ammo == DayZPlayerImplementFallDamage.FALL_DAMAGE_AMMO_SHOCK || ammo == DayZPlayerImplementFallDamage.FALL_DAMAGE_AMMO_HEALTH_OTHER_ATTACHMENTS)
					{
						if (globalHealthDamage > 0.0)
							LogPrint(string.Format("%1 hit by %2", horsePrefix, ammo));
					}
					else if ( source.GetType() == "AreaDamageManager" )
					{
						EntityAI parent = EntityAI.Cast( source );
						if ( parent )
						{
							LogPrint(string.Format("%1 hit by %2 with %3", horsePrefix, parent.GetType(), ammo));
						}
					}
					else
					{
						LogPrint(string.Format("%1 hit by %2 with %3", horsePrefix, source.GetType(), ammo));
					}
					break;

				default:
					LogPrint(string.Format("DEBUG: HorseHitBy() unknown damageType: %1", ammo));
					break;
			}
		}
		else
		{
			LogPrint("DEBUG: horse/source does not exist");
		}
	}


	protected PlayerBase IAT_GetPlayerByEntityID(int entityID) //bylo protected static
	{
		array<Man> players = new array<Man>;
		GetGame().GetPlayers(players);
		for(int i = 0; i < players.Count(); i++)
		{
			if(players.Get(i).GetID() == entityID)
			{
				return PlayerBase.Cast(players.Get(i));
			}
		}
		return null;
	}
};