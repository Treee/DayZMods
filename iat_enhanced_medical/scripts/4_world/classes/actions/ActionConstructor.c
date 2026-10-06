// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Register both self and target medical action pairs.
// Integration: config dependencies and vanilla behavior.
// Documentation: iat_enhanced_medical/README.md

modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		actions.Insert(IAT_ActionExtractBulletSelf);
		actions.Insert(IAT_ActionExtractBulletTarget);
		actions.Insert(IAT_ActionRemoveBandageSelf);
		actions.Insert(IAT_ActionRemoveBandageTarget);
	}
}
