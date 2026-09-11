modded class PlayerConstants
{
	static const ref TStringArray IAT_DAMAGE_ZONES = {"Head", "Torso", "LeftArm", "RightArm", "RightHand", "LeftHand", "LeftLeg", "RightLeg", "LeftFoot", "RightFoot"};

	static const float BLEEDING_SOURCE_BLOODLOSS_PER_SEC = -7; 		// amount of blood loss per second from one bleeding source
	static const int BLEEDING_SOURCE_DURATION_NORMAL = 45; // in seconds, how long will bleeding source exist until disapearing
	static const float BLEEDING_SOURCE_CLOSE_INFECTION_CHANCE = 0.01;	// a chance for wound infection when the wound is self-closing
	static const float BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM = 0.47; 		// modifier of the bloodloss given by BLEEDING_SOURCE_BLOODLOSS_PER_SEC, multiplying these two will give the resulting bloodloss

};