modded class FireplaceBase
{
		// 	//STATIC: define kindling types
		// if (!m_FireConsumableTypes)
		// {
		// 	m_FireConsumableTypes = new ref map<typename, ref FireConsumableType>();
		// 	m_FireConsumableTypes.Insert(ATTACHMENT_RAGS, 				new FireConsumableType(ATTACHMENT_RAGS, 				8, 	true,	"Rags"));
		// 	m_FireConsumableTypes.Insert(ATTACHMENT_BANDAGE, 			new FireConsumableType(ATTACHMENT_BANDAGE, 				8, 	true,	"MedicalBandage"));
		// 	m_FireConsumableTypes.Insert(ATTACHMENT_BOOK, 				new FireConsumableType(ATTACHMENT_BOOK, 				20, 	true,	"Book"));
		// 	m_FireConsumableTypes.Insert(ATTACHMENT_BARK_OAK, 			new FireConsumableType(ATTACHMENT_BARK_OAK, 			10, 	true,	"OakBark"));
		// 	m_FireConsumableTypes.Insert(ATTACHMENT_BARK_BIRCH, 		new FireConsumableType(ATTACHMENT_BARK_BIRCH, 			8, 	true,	"BirchBark"));
		// 	m_FireConsumableTypes.Insert(ATTACHMENT_PAPER, 				new FireConsumableType(ATTACHMENT_PAPER, 				5, 	true,	"Paper"));
		// 	m_FireConsumableTypes.Insert(ATTACHMENT_GIFTWRAP, 			new FireConsumableType(ATTACHMENT_GIFTWRAP, 			5, 	true,	"GiftWrapPaper"));
		// 	m_FireConsumableTypes.Insert(ATTACHMENT_PUNCHEDCARD,		new FireConsumableType(ATTACHMENT_PUNCHEDCARD, 			5, 	true,	"PunchedCard"));
		// 	m_FireConsumableTypes.Insert(ATTACHMENT_EYEMASK_COLORBASE,	new FireConsumableType(ATTACHMENT_EYEMASK_COLORBASE, 	5, 	true,	"EyeMask_ColorBase"));

		// 	//define fuel types
		// 	m_FireConsumableTypes.Insert(ATTACHMENT_STICKS, 		new FireConsumableType(ATTACHMENT_STICKS, 		30, 	false,	"WoodenStick"));
		// 	m_FireConsumableTypes.Insert(ATTACHMENT_FIREWOOD, 		new FireConsumableType(ATTACHMENT_FIREWOOD, 	100, 	false,	"Firewood"));
		// }
	override protected void CalcAndSetTotalEnergy()
	{
		if (GetGame() && GetGame().IsDedicatedServer())
		{
			foreach (FireConsumableType fireConsumableType : m_FireConsumableTypes)
			{
				fireConsumableType.m_Energy = fireConsumableType.GetEnergy() * 20;
			}

			super.CalcAndSetTotalEnergy();
		}
	}
};