modded class PlayerBase
{
	override void SetActions(out TInputActionMap InputActionMap)
	{
		super.SetActions(InputActionMap);
		AddAction(IAT_InfinityGauntlet_SnapAction, InputActionMap);
	}
};