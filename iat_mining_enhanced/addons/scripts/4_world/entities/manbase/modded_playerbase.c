modded class PlayerBase
{
	override void SetActions(out TInputActionMap InputActionMap)
	{
		super.SetActions(InputActionMap);
		AddAction(IAT_ActionDescendIntoMine, InputActionMap);
		AddAction(IAT_ActionAscendOutOfMine, InputActionMap);
	}

	// override void AddToEnvironmentTemperature(float pTemperature)
	// {
	// 	PrintFormat("current temperature: %1", pTemperature);
	// 	super.AddToEnvironmentTemperature(pTemperature);
	// }
};