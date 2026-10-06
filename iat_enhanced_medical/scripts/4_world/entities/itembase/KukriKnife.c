// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Knife bandage-removal capability and explicit actions.
// Integration: config dependencies and vanilla behavior.
// Documentation: iat_enhanced_medical/README.md

modded class KukriKnife
{
	override bool IAT_CanRemoveBandage()
	{
		return true;
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(IAT_ActionRemoveBandageSelf);
		AddAction(IAT_ActionRemoveBandageTarget);
	}
	override bool IAT_CanExtractBullet()
	{
		return true;
	}
	override float IAT_BulletExtractionHpDmg()
	{
		return 15;
	}
};
