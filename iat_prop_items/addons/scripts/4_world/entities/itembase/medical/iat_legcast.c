class IAT_LegCast_Colorbase: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionLegCastTarget);
		AddAction(IAT_ActionLegCastSelf);
	}

	string GetAppliedCastClassName()
	{
		string castColor = ConfigGetString("color");
		if (!castColor || castColor == "")
			castColor = "Basic";

		return string.Format("IAT_LegCastApplied_%1", castColor);
	}

	void SetHealthAfterUse()
	{
		if (GetHealthLevel() < 4)
		{
			int newDmgLevel = GetHealthLevel() + 2;
			float max = GetMaxHealth("", "");

			switch (newDmgLevel)
			{
				case GameConstants.STATE_BADLY_DAMAGED:
					SetHealth("", "", max * GameConstants.DAMAGE_BADLY_DAMAGED_VALUE);
					break;

				case GameConstants.STATE_DAMAGED:
					SetHealth("", "", max * GameConstants.DAMAGE_DAMAGED_VALUE);
					break;

				case GameConstants.STATE_WORN:
					SetHealth("", "", max * GameConstants.DAMAGE_WORN_VALUE);
					break;

				case GameConstants.STATE_RUINED:
					SetHealth("", "", max * GameConstants.DAMAGE_RUINED_VALUE);
					break;

				default:
					break;
			}
		}
	}
};
class IAT_LegCast_Basic : IAT_LegCast_Colorbase{};
class IAT_LegCast_Permanent : IAT_LegCast_Colorbase{};
class IAT_LegCast_DotsNotsStripes : IAT_LegCast_Colorbase{};
class IAT_LegCast_FastHealing : IAT_LegCast_Colorbase{};
class IAT_LegCast_Infected : IAT_LegCast_Colorbase{};

class IAT_LegCastApplied_Colorbase: Clothing
{
	void ~IAT_LegCastApplied_Colorbase()
	{

	}
	string GetLegCastClassName()
	{
		string castColor = ConfigGetString("color");
		if (!castColor || castColor == "")
			castColor = "Basic";

		return string.Format("IAT_LegCast_%1", castColor);
	}
	bool IsPermanentFixture()
	{
		return false;
	}
};

class IAT_LegCastApplied_Basic : IAT_LegCastApplied_Colorbase{};
class IAT_LegCastApplied_Permanent : IAT_LegCastApplied_Colorbase
{
	override bool IsPermanentFixture()
	{
		return true;
	}
};
class IAT_LegCastApplied_DotsNotsStripes : IAT_LegCastApplied_Colorbase
{
	override bool IsPermanentFixture()
	{
		return true;
	}
};
class IAT_LegCastApplied_FastHealing : IAT_LegCastApplied_Colorbase{};
class IAT_LegCastApplied_Infected : IAT_LegCastApplied_Colorbase{};