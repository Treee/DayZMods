modded class GameConstants
{
	const int STAMINA_DRAIN_STANDING_SPRINT_PER_SEC = 3; //in units (how much sprint depletes stamina)
	const int STAMINA_DRAIN_CROUCHED_SPRINT_PER_SEC = 1; //in units (how much sprint in crouch depletes stamina)
	const int STAMINA_DRAIN_PRONE_SPRINT_PER_SEC = 3; //in units (how much sprint in prone depletes stamina)
	const int STAMINA_DRAIN_SWIM_FAST_PER_SEC = 4; //in units (how much fast swimming depletes stamina)
	const int STAMINA_DRAIN_LADDER_FAST_PER_SEC = 5; //in units (how much fast ladder climb depletes stamina)

	const float	STAMINA_DRAIN_HOLD_BREATH_START = 0.1; //in units (how much holding breath depletes stamina at the start)
	const float	STAMINA_DRAIN_HOLD_BREATH_END = 1.0; //in units (how much holding breath depletes stamina at the end)
	const float	STAMINA_DRAIN_JUMP = 5;		// in units (how much jumping depletes stamina)
	const float	STAMINA_DRAIN_VAULT = 10;		// in units (how much jumping depletes stamina)
	const float	STAMINA_DRAIN_CLIMB = 15;		// in units (how much jumping depletes stamina)
	const float	STAMINA_DRAIN_MELEE_LIGHT = 1; //in units (how much light melee punch depletes stamina)
	const float	STAMINA_DRAIN_MELEE_HEAVY = 17; //in units (how much heavy melee punch depletes stamina)
	const float	STAMINA_DRAIN_MELEE_EVADE = 4; // in units (how much evade depletes stamina)
	const float	STAMINA_DRAIN_ROLL = 3; // in units (how much roll depletes stamina)

	const float STAMINA_DRAIN_HOLD_BREATH_DURATION = 8.0; //in seconds, time it takes to increase stamina drain from STAMINA_DRAIN_HOLD_BREATH_START to STAMINA_DRAIN_HOLD_BREATH_END
	const float	STAMINA_DRAIN_HOLD_BREATH_EXPONENT = 3; //holding breath exponent

	const float STAMINA_KG_TO_STAMINAPERCENT_PENALTY = 1.5; //in units (by how many  units is max stamina bar reduced for each 1 kg of load weight)
	const float STAMINA_MIN_CAP = 5; //in units (overload won't reduce max stamina bar under this value)
	const float STAMINA_HOLD_BREATH_THRESHOLD_ACTIVATE = 10; // in units
	const float STAMINA_HOLD_BREATH_THRESHOLD_DRAIN = 0; // in units
	const float STAMINA_JUMP_THRESHOLD = 5; // in units
	const float STAMINA_VAULT_THRESHOLD = 10; // in units
	const float STAMINA_CLIMB_THRESHOLD = 15; // in units
	const float STAMINA_ROLL_THRESHOLD = 3; // in units

	const float STAMINA_MELEE_HEAVY_THRESHOLD = STAMINA_DRAIN_MELEE_HEAVY; // in units (how many units we need to make a heavy hit in melee)
	const float STAMINA_MELEE_EVADE_THRESHOLD = 5; // in units
	const float STAMINA_REGEN_COOLDOWN_DEPLETION = 1; // in secs (how much time we will spend in cooldown before the stamina will starts with regeneration)
	const float STAMINA_REGEN_COOLDOWN_EXHAUSTION = 3;
	const float STAMINA_WEIGHT_LIMIT_THRESHOLD = 12000; //! in grams (weight where the player is not penalized by stamina)
	const float STAMINA_KG_TO_GRAMS = 1000; //for kg to g conversion
	const float STAMINA_SYNC_RATE = 0.5; //in secs
	const float STAMINA_MAX = 150;

};