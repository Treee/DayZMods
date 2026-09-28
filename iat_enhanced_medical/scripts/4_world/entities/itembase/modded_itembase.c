modded class ItemBase
{
	// Override to opt into bullet extraction actions
	bool IAT_CanExtractBullet()
	{
		return false;
	}

	// Global patient Health lost per successful extraction, not tool wear.
	float IAT_BulletExtractionHpDmg()
	{
		return 0;
	}

};

modded class Pliers
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(IAT_ActionExtractBulletSelf);
		AddAction(IAT_ActionExtractBulletTarget);
	}
	override bool IAT_CanExtractBullet()
	{
		return true;
	}
};