modded class PlayerBase
{
	override void SetActions(out TInputActionMap InputActionMap)
    {
        super.SetActions(InputActionMap);
        AddAction(IAT_ActionInteractWallConsoleSwitch, InputActionMap);
        AddAction(IAT_ActionInteractWallConsoleDial, InputActionMap);
	}
};