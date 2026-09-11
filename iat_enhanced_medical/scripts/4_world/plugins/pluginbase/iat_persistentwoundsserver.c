class IAT_PersistentWoundsServer extends PluginBase
{
	// Keep track of where the player has applied bandages (dmg zones)
	protected int m_Bandages = 0;
	/*
	* Keep track of the bullets lodged in the player (bones)
	* This lets us have multiple bullets per dmg zone
	*/
	protected int m_Bullets = 0;

	// Initialize variables
	override void OnInit()
	{
		super.OnInit();
	}

	/*
	* dmgZone - The Damage Zone where to apply this bandage
	* This function is where we will try to add a bandage if one does not already exist.
	* This is where we will remove the bleed when properly bandaged
	*/
	void TryAddBandageToDamageZone(PlayerBase player, string dmgZone)
	{

	}

	/*
	* dmgZone - The Damage Zone where to remove the bandage
	* This function is where we will try to remove a bandage.
	* Reapply bleed if zone hp is less than 50%
	* Wound Infection Chance depending on the state of the bandage
	*/
	void RemoveBandageFromDamageZone(string dmgZone)
	{

	}
};