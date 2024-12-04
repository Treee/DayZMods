modded class GameConstants
{
	const int 	STAMINA_DRAIN_STANDING_SPRINT_PER_SEC = 2.8; //in units (how much sprint depletes stamina)
	const float STAMINA_REGEN_COOLDOWN_DEPLETION = 3; // in secs (how much time we will spend in cooldown before the stamina will starts with regeneration)
	const float STAMINA_REGEN_COOLDOWN_EXHAUSTION = 20;
	const float STAMINA_WEIGHT_LIMIT_THRESHOLD = 12000; //default 6000 ! in grams (weight where the player is not penalized by stamina)

	const float STAMINA_MAX = 120;

};