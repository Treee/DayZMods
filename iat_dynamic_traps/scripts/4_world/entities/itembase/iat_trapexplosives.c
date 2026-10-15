class IAT_LightTrapExplosion: Grenade_Base
{
	void IAT_LightTrapExplosion()
	{
		m_Pinned = false;
		SetAmmoType("IAT_LightTrapExplosion_Ammo");
		SetFuseDelay(0);
	}
};
class IAT_HeavyTrapExplosion: Grenade_Base
{
	void IAT_HeavyTrapExplosion()
	{
		m_Pinned = false;
		SetAmmoType("IAT_HeavyTrapExplosion_Ammo");
		SetFuseDelay(0);
	}
};