class IAT_LegCast_Colorbase: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionLegCastTarget);
		AddAction(IAT_ActionLegCastSelf);
	}
};
class IAT_LegCast_Basic : IAT_LegCast_Colorbase{};
class IAT_LegCast_DotsNotsStripes : IAT_LegCast_Colorbase{};
class IAT_LegCast_FastHealing : IAT_LegCast_Colorbase{};
class IAT_LegCast_Infected : IAT_LegCast_Colorbase{};

class IAT_LegCastApplied_Colorbase: Clothing
{
	void ~IAT_LegCastApplied_Colorbase()
	{

	}
	bool IsPermanentFixture()
	{
		return false;
	}
};

class IAT_LegCastApplied_Basic : IAT_LegCastApplied_Colorbase{};
class IAT_LegCastApplied_DotsNotsStripes : IAT_LegCastApplied_Colorbase
{
	bool IsPermanentFixture()
	{
		return true;
	}
};
class IAT_LegCastApplied_FastHealing : IAT_LegCastApplied_Colorbase{};
class IAT_LegCastApplied_Infected : IAT_LegCastApplied_Colorbase{};