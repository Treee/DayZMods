modded class GameConstants
{
	/*
	* The distances (m) that which we should notify the player of impending action.
	* The steps needed to trigger a message popup. Smaller numbers make more messages pop up
	*/
	const int IAT_MDT_WARNING_DISTANCE = 100;
	const int IAT_MDT_CRITICAL_DISTANCE = 85;
	const int IAT_MDT_STEP_MOD_COUNT = 20;
	/*
	* Given some maps have poor map frame properties, give some way to hard offset
	* the worlds height and width
	*/
	const int IAT_MDT_MAP_OFFSET_X = 0;
	const int IAT_MDT_MAP_OFFSET_Y = 0;
};