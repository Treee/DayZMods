class IAT_BookVariantActionReciveData extends ActionReciveData
{
  	int m_IATBookVariant;
}

class IAT_BookVariantActionData extends ActionData
{
  	int m_IATBookVariant;
};


class IAT_ActionCraftBookOptionsCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(2); //default value can be set in recipes
	}
};

class IAT_ActionCraftBookOptions: ActionContinuousBase
{
	void IAT_ActionCraftBookOptions()
	{
		m_Sound = "craft_universal_0";
		m_CallbackClass = IAT_ActionCraftBookOptionsCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#craft";

		if (!GetGame().IsDedicatedServer())
        {
            GetVariantManager().GetOnUpdateInvoker().Insert(OnUpdateActions);
        }
	}

	void OnUpdateActions( Object item, Object target, int component_index )
	{
		TStringArray m_bookOptions = GetBookOptions();
		if (m_bookOptions.Count() > 0)
			GetVariantManager().SetActionVariantCount(m_bookOptions.Count());
		else
			GetVariantManager().Clear();
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
	}

	override bool HasTarget()
	{
		return true;
	}

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		m_Text = "Craft Book - No Option";
		IAT_LiteraryDevices_Notebook_ColorBase notebook;
		if (target && Class.CastTo(notebook, target.GetObject()))
		{
			if (notebook.IsFullNotebook())
			{
				// if the main item has enough quantity to craft
				if (item && item.GetQuantity() > 24)
				{
					TStringArray m_bookOptions = GetBookOptions();
					if (m_bookOptions.IsValidIndex(m_VariantID))
					{
						string bookName = m_bookOptions.Get(m_VariantID);
						bookName.Replace("IAT_LiteraryDevices_Book_", "");

						m_Text = string.Format("Craft Book - %1", bookName);
					}
				}
			}
		}
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// if the target is rags and the stack is full
		IAT_LiteraryDevices_Notebook_ColorBase notebook;
		if (target && Class.CastTo(notebook, target.GetObject()))
		{
			// if the main item has enough quantity to craft
			if (item && item.GetQuantity() > 24)
			{
				if (notebook.IsFullNotebook())
				{
					return true;
				}
			}
			return false;
		}
		return false;
	}

	TStringArray GetBookOptions()
	{
		return {
			"IAT_LiteraryDevices_Book_CodeBreakers",
			"IAT_LiteraryDevices_Book_RadioEtiquette",
			"IAT_LiteraryDevices_Book_BanditryGuide",
			"IAT_LiteraryDevices_Book_NavigationProtocols",
			"IAT_LiteraryDevices_Book_ZombieSurvivalGuide",
			"IAT_LiteraryDevices_Book_Bible",
			"IAT_LiteraryDevices_Book_TheWarOfTheWorlds",
			"IAT_LiteraryDevices_Book_AroundTheWorldIn80Days",
			"IAT_LiteraryDevices_Book_CrimeAndPunishment",
			"IAT_LiteraryDevices_Book_TheMetamorphosis",
			"IAT_LiteraryDevices_Book_TheRaven",
			"IAT_LiteraryDevices_Book_TheArtOfWar",
			"IAT_LiteraryDevices_Book_RobinsonCrusoe",
			"IAT_LiteraryDevices_Book_Russian",
			"IAT_LiteraryDevices_Book_RussianCheatSheet",
			"IAT_LiteraryDevices_Book_ThePictureOfDorianGray",
			"IAT_LiteraryDevices_Book_ThePitAndThePendulum",
			"IAT_LiteraryDevices_Book_TheTimeMachine",
			"IAT_LiteraryDevices_Book_TheCountryOfTheBlind",
			"IAT_LiteraryDevices_Book_BilaNemoc",
			"IAT_LiteraryDevices_Book_Youth",
			"IAT_LiteraryDevices_Book_Verwandlung",
			"IAT_LiteraryDevices_Book_TheJungleBook",
			"IAT_LiteraryDevices_Book_TheBrothersKaramazov",
			"IAT_LiteraryDevices_Book_TheCallOfCthulhu",
			"IAT_LiteraryDevices_Book_TheShunnedHouse",
			"IAT_LiteraryDevices_Book_TheHoundOfTheBaskervilles",
			"IAT_LiteraryDevices_Book_TonyAndTheBeetles",
			"IAT_LiteraryDevices_Book_TheCosmicComputer",
			"IAT_LiteraryDevices_Book_ATravelerInTime",
			"IAT_LiteraryDevices_Book_TheVariableMan",
			"IAT_LiteraryDevices_Book_TheOutlet",
			"IAT_LiteraryDevices_Book_TheBarrier",
			"IAT_LiteraryDevices_Book_TheDesertOfWheat",
			"IAT_LiteraryDevices_Book_FlyingURanch",
			"IAT_LiteraryDevices_Book_CassidysRustlerRoundUp",
			"IAT_LiteraryDevices_Book_LonesomeLand",
			"IAT_LiteraryDevices_Book_Trailin",
			"IAT_LiteraryDevices_Book_RonickyDoone",
			"IAT_LiteraryDevices_Book_BettyZane",
			"IAT_LiteraryDevices_Book_ATexasMatchmaker",
			"IAT_LiteraryDevices_Book_TheThunderBird",
			"IAT_LiteraryDevices_Book_BlackJack",
			"IAT_LiteraryDevices_Book_TheLastTrail",
			"IAT_LiteraryDevices_Book_SelectedStories",
			"IAT_LiteraryDevices_Book_TheHeritageOfTheSioux",
			"IAT_LiteraryDevices_Book_DesertGold",
			"IAT_LiteraryDevices_Book_TheHiddenChildren",
			"IAT_LiteraryDevices_Book_TheLastOfThePlainsmen",
			"IAT_LiteraryDevices_Book_GunmansReckoning",
			"IAT_LiteraryDevices_Book_Skyrider",
			"IAT_LiteraryDevices_Book_SpinifexAndSand",
			"IAT_LiteraryDevices_Book_SunsetPass",
			"IAT_LiteraryDevices_Book_TheCaveOfGold",
			"IAT_LiteraryDevices_Book_TheDayOfTheBeast",
			"IAT_LiteraryDevices_Book_TheQuirt",
			"IAT_LiteraryDevices_Book_AVoyageToArcturus",
			"IAT_LiteraryDevices_Book_WealthOfNations",
			"IAT_LiteraryDevices_Book_AndersensFairyTales",
			"IAT_LiteraryDevices_Book_BlackBeauty",
			"IAT_LiteraryDevices_Book_Buddenbrooks",
			"IAT_LiteraryDevices_Book_DeadSouls",
			"IAT_LiteraryDevices_Book_Erewhon",
			"IAT_LiteraryDevices_Book_FatherGoriot",
			"IAT_LiteraryDevices_Book_GreatExpectations",
			"IAT_LiteraryDevices_Book_GulliversTravels",
			"IAT_LiteraryDevices_Book_HeartOfDarkness",
			"IAT_LiteraryDevices_Book_Herland",
			"IAT_LiteraryDevices_Book_Ivanhoe",
			"IAT_LiteraryDevices_Book_Kidnapped",
			"IAT_LiteraryDevices_Book_LaChartreuseDeParme",
			"IAT_LiteraryDevices_Book_LordJim",
			"IAT_LiteraryDevices_Book_MadameBovary",
			"IAT_LiteraryDevices_Book_Nostromo",
			"IAT_LiteraryDevices_Book_NaturalSelection",
			"IAT_LiteraryDevices_Book_TheMetamorphosesOfOvid",
			"IAT_LiteraryDevices_Book_MobyDick",
			"IAT_LiteraryDevices_Book_KingLear",
			"IAT_LiteraryDevices_Book_LaDbcle",
			"IAT_LiteraryDevices_Book_TheCanterburyTales",
			"IAT_LiteraryDevices_Book_TheRightsOfWoman",
			"IAT_LiteraryDevices_Book_ToTheInteriorOfTheEarth",
			"IAT_LiteraryDevices_Book_NjalsSaga",
			"IAT_LiteraryDevices_Book_TheTrial",
			"IAT_LiteraryDevices_Book_DonQuixote",
			"IAT_LiteraryDevices_Book_PhilosophiaeNaturalis",
			"IAT_LiteraryDevices_Book_PrideAndPrejudice",
			"IAT_LiteraryDevices_Book_Rasselas",
			"IAT_LiteraryDevices_Book_Scaramouche",
			"IAT_LiteraryDevices_Book_SonsAndLovers",
			"IAT_LiteraryDevices_Book_TheCallOfTheWild",
			"IAT_LiteraryDevices_Book_TheComingRace",
			"IAT_LiteraryDevices_Book_TheIslandOfDoctorMoreau",
			"IAT_LiteraryDevices_Book_TheMahabharataOfKrishna",
			"IAT_LiteraryDevices_Book_TheManWhoWasThursday",
			"IAT_LiteraryDevices_Book_ThePossessed",
			"IAT_LiteraryDevices_Book_ThePrisonerOfZenda",
			"IAT_LiteraryDevices_Book_APrincessOfMars",
			"IAT_LiteraryDevices_Book_KingSolomonsMines",
			"IAT_LiteraryDevices_Book_Middlemarch",
			"IAT_LiteraryDevices_Book_TheHouseOfTheSevenGables",
			"IAT_LiteraryDevices_Book_TheMonkARomance",
			"IAT_LiteraryDevices_Book_TheJustifiedSinner",
			"IAT_LiteraryDevices_Book_TheRedBadgeOfCourage",
			"IAT_LiteraryDevices_Book_ADollsHouse",
			"IAT_LiteraryDevices_Book_GilgameshEpic",
			"IAT_LiteraryDevices_Book_AnnaKarenina",
			"IAT_LiteraryDevices_Book_Candide",
			"IAT_LiteraryDevices_Book_Faust",
			"IAT_LiteraryDevices_Book_HinduLiterature",
			"IAT_LiteraryDevices_Book_Hunger",
			"IAT_LiteraryDevices_Book_JapaneseLiterature",
			"IAT_LiteraryDevices_Book_LeRougeEtLeNoir",
			"IAT_LiteraryDevices_Book_TheDecameron",
			"IAT_LiteraryDevices_Book_TheGiacomoLeopardi",
			"IAT_LiteraryDevices_Book_AliceInWonderland",
			"IAT_LiteraryDevices_Book_TheScarletPimpernel",
			"IAT_LiteraryDevices_Book_TheThreeMusketeers",
			"IAT_LiteraryDevices_Book_TheTurnOfTheScrew",
			"IAT_LiteraryDevices_Book_TranslationsOfShakuntala",
			"IAT_LiteraryDevices_Book_TreasureIsland",
			"IAT_LiteraryDevices_Book_Ulysses",
			"IAT_LiteraryDevices_Book_UncleSilas",
			"IAT_LiteraryDevices_Book_TheAeneid",
			"IAT_LiteraryDevices_Book_WarAndPeace",
			"IAT_LiteraryDevices_Book_WielandOrTheTransformation",
			"IAT_LiteraryDevices_Book_WutheringHeights",
			"IAT_LiteraryDevices_Book_CinqSemainesEnBallon",
			"IAT_LiteraryDevices_Book_Dracula",
			"IAT_LiteraryDevices_Book_DasNibelungenlied",
			"IAT_LiteraryDevices_Book_TheLastMan",
			"IAT_LiteraryDevices_Book_RomeoUndJulia",
			"IAT_LiteraryDevices_Book_Frankenstein",
			"IAT_LiteraryDevices_Book_DeLaTerreLaLune",
			"IAT_LiteraryDevices_Book_LleMystrieuse",
			"IAT_LiteraryDevices_Book_LaComdieHumaine",
			"IAT_LiteraryDevices_Book_LesCorneilles",
			"IAT_LiteraryDevices_Book_20000LieuesSousLesMers",
			"IAT_LiteraryDevices_Book_ThreeMenInABoat",
		};
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		super.OnFinishProgressServer(action_data);

		if (action_data.m_Player)
		{
			int newItemIndex = IAT_BookVariantActionData.Cast(action_data).m_IATBookVariant;
			TStringArray m_bookOptions = GetBookOptions();
			if (m_bookOptions.IsValidIndex(newItemIndex))
			{
				string newItem = string.Format("%1",  m_bookOptions.Get(newItemIndex));
				GetGame().CreateObjectEx(newItem, action_data.m_Player.GetPosition(), ECE_SETUP|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY);
				IAT_LiteraryDevices_Notebook_ColorBase notebook;
				if (Class.CastTo(notebook, action_data.m_Target.GetObject()))
				{
					notebook.DeleteSafe();
				}
				EpoxyPutty epoxy;
				if (Class.CastTo(epoxy, action_data.m_MainItem))
				{
					epoxy.AddQuantity(-25);
				}
			}
		}
	}

	override ActionData CreateActionData()
	{
		IAT_BookVariantActionData action_data = new IAT_BookVariantActionData;
		return action_data;
	}

	override bool SetupAction( PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL )
	{
		if ( super.SetupAction( player, target, item, action_data, extra_data ) )
		{
			if ( !GetGame().IsDedicatedServer() )
			{
				IAT_BookVariantActionData.Cast(action_data).m_IATBookVariant = m_VariantID;
			}
			return true;
		}
		return false;
	}

	override void WriteToContext(ParamsWriteContext ctx, ActionData action_data)
	{
		super.WriteToContext(ctx, action_data);
		ctx.Write(IAT_BookVariantActionData.Cast(action_data).m_IATBookVariant);
	}

	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data )
	{
		action_recive_data = new IAT_BookVariantActionReciveData;
		// if we read data successfully
		super.ReadFromContext(ctx, action_recive_data);
		// read the data
		int variantId;
		if ( ctx.Read(variantId) )
		{
			IAT_BookVariantActionReciveData.Cast( action_recive_data ).m_IATBookVariant = variantId;
			return true;
		}
		else
		{
			return false;
		}
	}

	override void HandleReciveData(ActionReciveData action_recive_data, ActionData action_data)
	{
		super.HandleReciveData(action_recive_data, action_data);
		IAT_BookVariantActionData.Cast(action_data).m_IATBookVariant = IAT_BookVariantActionReciveData.Cast( action_recive_data ).m_IATBookVariant;
	}

};