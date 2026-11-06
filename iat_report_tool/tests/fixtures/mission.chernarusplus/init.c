// Report Tool component tests exercise data, RPC decoding and webhook queues.
// They need MissionGameplay's frame updates, but no player or action system.
void main()
{
}

Mission CreateCustomMission(string path)
{
	return new MissionGameplay();
}
