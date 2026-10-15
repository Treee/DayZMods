modded class Lockpick
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionLockDisplayCase);
		AddAction(IAT_ActionUnLockDisplayCase);
	}
};