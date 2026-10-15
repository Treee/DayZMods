modded class EmoteConstructor
{
	override void RegisterEmotes(TTypenameArray emotes)
	{
		super.RegisterEmotes(emotes);

		emotes.Insert(IAT_EmoteCoughing);
		emotes.Insert(IAT_EmoteBlind);
		emotes.Insert(IAT_EmoteBulletHit);
		emotes.Insert(IAT_EmoteBleedingSource);
		emotes.Insert(IAT_EmoteBloodloss);
		emotes.Insert(IAT_EmoteSneeze);
		emotes.Insert(IAT_EmoteFeverBlur);
		emotes.Insert(IAT_EmoteLaughter);
		emotes.Insert(IAT_EmoteUnconscious);
		emotes.Insert(IAT_EmoteFreeze);
		emotes.Insert(IAT_EmoteFreezeChatter);
		emotes.Insert(IAT_EmoteHot);
		emotes.Insert(IAT_EmoteLegBreak);
		emotes.Insert(IAT_EmotePainLight);
		emotes.Insert(IAT_EmotePainHeavy);
		emotes.Insert(IAT_EmoteShiver);
		emotes.Insert(IAT_EmoteHeavyMetalPoison);
		emotes.Insert(IAT_EmoteHeavyGasp);
	}
}