// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Default item capabilities for medical actions.
// Integration: config dependencies and vanilla behavior.
// Documentation: iat_enhanced_medical/README.md

modded class ItemBase
{
	bool IAT_CanRemoveBandage()
	{
		return false;
	}

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
