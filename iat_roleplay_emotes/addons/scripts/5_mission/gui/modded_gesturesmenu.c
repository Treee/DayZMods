enum IAT_GestureCategories : GestureCategories
{
	IAT_RP_CATEGORY = 50;
};

modded class GesturesMenu
{
	override protected void GetGestureItems( out array<ref GestureMenuItem> gesture_items, GestureCategories category )
	{
		super.GetGestureItems(gesture_items, category);

		if (category == GestureCategories.CATEGORIES)
		{
        	gesture_items.Insert( new GestureMenuItem( IAT_GestureCategories.IAT_RP_CATEGORY, "Status Effects", category ) );
		}
		//Category 5 - special
		else if ( category == IAT_GestureCategories.IAT_RP_CATEGORY )
		{
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_COUGH, "Cough",	category ) );
			// gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_BLINDNESS, "Blind",	category ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_BULLET_HIT, "Bullet Hit",	category ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_BLEEDING_SOURCE, "Bleed",	category ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_BLOODLOSS, "Blood Loss",	category ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_SNEEZE, "Sneeze",	category ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_FEVERBLUR, "Fever",	category ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_LAUGHTER, "Laugh",	category ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_UNCONSCIOUS, "Unconscious",	category ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_FREEZE, "Freeze",	category ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_FREEZE_CHATTER, "Freeze Chatter",	category ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_HOT, "Hot",	category ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_LEGBREAK, "Break Leg",	category ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_PAIN_LIGHT, "Light Pain",	category ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_PAIN_HEAVY, "Heavy Pain",	category ) );
			// gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_SHIVER, "Shiver",	category ) );
			// gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_HEAVYMETALPOISON, "Heavy Metal Poison",	category ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.IAT_EMOTE_GASP, "Gasp",	category ) );
		}
	}
};