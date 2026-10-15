modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(IAT_ActionToggleMuteTransmitter);
		// actions.Insert(IAT_ActionToggleMuteTransmitterTarget); // WIP
	}
};