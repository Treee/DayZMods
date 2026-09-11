modded class MiscGameplayFunctions
{
	// get hit in the torso 5 times
	// bleeds stop on their own if above 50%
	// below 50% bleeds do not stop uinless there is a bandage

	// i have a laceration due to getting hit on my torso too many times (>50% bleed dmg)
	// these bleeds are not self closing so i need to apply a bandage to close the wound
	// applying a bandage will remove the bleed immediately, and apply a visibl bandage to the player
	// this visible bandage will need to be tracked for each zone and synced to the client side

	static string IAT_MapBoneNameToDamageZone(string boneName)
	{
		boneName.ToLower();
		switch(boneName)
		{
			case "head":
				return "Head";
			break;

			case "brain":
				return "Brain";
			break;

			case "neck":
			case "pelvis":
			case "spine":
			case "spine1":
			case "spine2":
			case "spine3":
				return "Torso";
			break;

			case "leftshoulder":
			case "leftarm":
			case "leftarmroll":
			case "leftforearm":
				return "LeftArm";
			break;

			case "rightshoulder":
			case "rightarm":
			case "rightarmroll":
			case "rightforearm":
				return "RightArm";
			break;

			case "leftforearmroll":
				return "LeftHand";
			break;

			case "rightforearmroll":
				return "RightHand";
			break;

			case "leftleg":
			case "leftlegroll":
			case "leftupleg":
			case "leftuplegroll":
				return "LeftLeg";
			break;

			case "rightleg":
			case "rightlegroll":
			case "rightupleg":
			case "rightuplegroll":
				return "RightLeg";
			break;

			case "leftfoot":
			case "lefttoebase":
				return "LeftFoot";
			break;

			case "rightfoot":
			case "righttoebase":
				return "RightFoot";
			break;
		}

		PrintFormat("====================================[IAT_ENHANCED_MEDICAL] Bone: %1 needs a mapping.", boneName);
		// Global Zone by default
		return "";
	}
};