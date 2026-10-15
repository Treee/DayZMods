modded class MiscGameplayFunctions
{
	// hard override because it is being abused
	override static void TeleportCheck(notnull PlayerBase player, notnull array<ref array<float>> safe_positions){}
}