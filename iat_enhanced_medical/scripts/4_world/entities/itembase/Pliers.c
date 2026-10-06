// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Bullet extraction capability, actions, and patient Health cost.
// Integration: config dependencies and vanilla behavior.
// Documentation: iat_enhanced_medical/README.md

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
	override float IAT_BulletExtractionHpDmg()
	{
		return 10;
	}
};
