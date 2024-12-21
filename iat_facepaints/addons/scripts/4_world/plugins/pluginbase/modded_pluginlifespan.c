modded class PluginLifespan
{
  	protected int m_TotalCountFacePaints;
	override void LoadFromCfg()
	{
		super.LoadFromCfg();
		m_TotalCountFacePaints = GetFacePaintCamoOptions().Count() + GetFacePaintFlagOptions().Count() + GetFacePaintMaskOptions().Count() + GetFacePaintScarOptions().Count();
	}

	override protected void SetPlayerLifespanLevel( PlayerBase player, LifespanLevel level )
	{
		if (player.GetFacePaintIndex() < 0)
			super.SetPlayerLifespanLevel( player, level );
		else
			SetPaintedFaceMaterial(player, level);
  	}
	string GetFemaleBaseMaterial(string playerType)
	{
		if ( m_BloodyHands.Contains(playerType))
			return m_BloodyHands.Get(playerType).GetMaterial(BloodyHands.MATERIAL_TYPE_NORMAL);
		return "";
	}
	int GetFacePaintCount()
	{
		return m_TotalCountFacePaints;
	}
	TStringArray GetFacePaintCamoOptions()
	{
		return {
			"Bosnia",
			"Bulgaria1",
			"Bulgaria2",
			"Croatia",
			"Czech1",
			"Czech2",
			"Desert",
			"Digital",
			"DigitalBlue",
			"DragonScale",
			"DragonScaleRed",
			"France",
			"Germany",
			"Hungary1",
			"Hungary2",
			"Macedonia",
			"Olive",
			"Poland1",
			"Poland2",
			"Romania1",
			"Romania2",
			"Slovenia",
			"UK",
			"USA",
			"Winter",
			"Woodland",
			"WoodlandGreen",
			"WoodlandRed",
			"Yugoslavia",
		};
	}
	TStringArray GetFacePaintFlagOptions()
	{
		return {
			"Brazil",
			"Germany",
			"Italy",
			"Argentina",
			"France",
			"England",
			"Spain",
			"Netherlands",
			"Uruguay",
			"Sweden",
			"Belgium",
			"Ukraine",
			"Russia",
			"Serbia",
			"Mexico",
			"Poland",
			"Hungary",
			"Portugal",
			"Switzerland",
			"Czechia",
			"Austria",
			"Chile",
			"Croatia",
			"Denmark",
			"Paraguay",
			"Colombia",
			"USA",
			"Romania",
			"SouthKorea",
			"Nigeria",
			"Japan",
			"Scottland",
		};
	}
	TStringArray GetFacePaintMaskOptions()
	{
		return {
			"TearDrop",
			"SkullFace",
			"Clown1",
			"Geisha1",
			"KissCatman",
			"KissDemon",
			"KissSpaceman",
			"KissStarchild",
			"Zedmag"
		};
	}
	TStringArray GetFacePaintScarOptions()
	{
		return {
			"LeftCheekBruise",
			"LeftCheekScar",
			"LeftEyeBearClaw",
			"LeftEyeBearClawFaded",
			"LeftEyeBruise",
			"RightCheekScar",
			"RightKeloid",
			"RightLongScar",
		};
	}
	string GetPaintByIndex(int index)
	{
		int array1Count = GetFacePaintCamoOptions().Count();
		int array2Count = GetFacePaintFlagOptions().Count() + array1Count;
		int array3Count = GetFacePaintMaskOptions().Count() + array2Count;
		int array4Count = GetFacePaintScarOptions().Count() + array3Count;
		// Print(string.Format("arr1: %1 arr2: %2 arr3: %3 arry: %4 index: %5", array1Count, array2Count, array3Count, array4Count, index));
		int newIndex = index;
		if (index < array1Count)
		{
			// use camo paints, index is smallest index possible
			return string.Format("fp_%1", GetFacePaintCamoOptions().Get(newIndex));
		}
		else if (index >= array1Count && index < array2Count)
		{
			// use flag paints
			newIndex -= array1Count;
			return string.Format("fpf_%1", GetFacePaintFlagOptions().Get(newIndex));
		}
		else if (index >= array2Count && index < array3Count)
		{
			// use mask paints
			newIndex -= array2Count;
			return string.Format("fpm_%1", GetFacePaintMaskOptions().Get(newIndex));
		}
		else if (index >= array3Count && index < array4Count)
		{
			// use scar paints
			newIndex -= array3Count;
			return string.Format("fps_%1", GetFacePaintScarOptions().Get(newIndex));
		}
		return "error";
	}
	protected string GetPaintPathMale(int facepaintIndex, string materialName)
	{
		string facepaintCategory = GetPaintByIndex(facepaintIndex);
		TStringArray parts = new TStringArray;
		materialName.Split("\\", parts);
		string mat1 = materialName;
		if (parts.Count() == 6)
		{
			string filename = parts.Get(5);
			filename.Replace("_beard.", "_bearded.");
			mat1 = string.Format("iat_facepaints\\heads\\%1\\%2", facepaintCategory, filename);
			// Print("mat: " + mat1);
		}
		return mat1;
	}
	string GetPaintPathFemale(int facepaintIndex, string materialName)
	{
		string facepaintCategory = GetPaintByIndex(facepaintIndex);
		TStringArray parts = new TStringArray;
		materialName.Split("_", parts);
		string mat1 = materialName;
		if (parts.Count() == 2)
		{
			string filename = parts.Get(1);
			mat1 = string.Format("iat_facepaints\\heads\\%1\\hhl_f_%2_body.rvmat", facepaintCategory, filename);
			// Print("mat: " + mat1);
		}
		return mat1;
	}
	protected void SetPaintedFaceMaterial( PlayerBase player, LifespanLevel level )
	{
		if (player.m_CorpseState != 0)
			return;
		int slot_id = InventorySlots.GetSlotIdFromString("Head");
		EntityAI players_head = player.GetInventory().FindPlaceholderForSlot( slot_id );

		string mat1 = GetPaintPathMale(player.GetFacePaintIndex(), level.GetMaterialName());

		if( players_head && mat1 != "error" )
		{
			switch(level.GetLevel())
			{
				case LifeSpanState.BEARD_NONE:
				{
					players_head.SetObjectTexture( 0, "");
					players_head.SetObjectMaterial( 0, "");
					player.SetFaceTexture( level.GetTextureName() );
					player.SetFaceMaterial( mat1 );
					player.SetLifeSpanStateVisible(LifeSpanState.BEARD_NONE);
					break;
				}
				case LifeSpanState.BEARD_MEDIUM:
				{
					players_head.SetObjectTexture( 0, "");
					players_head.SetObjectMaterial( 0, "");
					player.SetFaceTexture( level.GetTextureName() );
					player.SetFaceMaterial( mat1 );
					player.SetLifeSpanStateVisible(LifeSpanState.BEARD_MEDIUM);
					break;
				}
				case LifeSpanState.BEARD_LARGE:
				{
					players_head.SetObjectTexture( 0, "");
					players_head.SetObjectMaterial( 0, "");
					player.SetFaceTexture( level.GetTextureName() );
					player.SetFaceMaterial( mat1 );
					player.SetLifeSpanStateVisible(LifeSpanState.BEARD_LARGE);
					break;
				}
				case LifeSpanState.BEARD_EXTRA:
				{
					players_head.SetObjectTexture( 0, level.GetTextureName() );
					players_head.SetObjectMaterial( 0, level.GetMaterialName() );

					array< ref LifespanLevel> lifespan_levels = m_LifespanLevels.Get( player.GetPlayerClass() );
					LifespanLevel prev_level = lifespan_levels.Get(LifeSpanState.BEARD_LARGE);

					player.SetFaceTexture( prev_level.GetTextureName() );
					mat1 = GetPaintPathMale(player.GetFacePaintIndex(), prev_level.GetMaterialName());
					player.SetFaceMaterial( mat1 );
					player.SetLifeSpanStateVisible(LifeSpanState.BEARD_EXTRA);
					break;
				}
				default:
				{
					Print("Lifespan state missing");
					break;
				}
			}
		}
	}
};