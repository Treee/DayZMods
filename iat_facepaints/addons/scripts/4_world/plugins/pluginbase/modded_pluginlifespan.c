// debug
// modded class LifespanLevel
// {
// 	override int GetLevel()
// 	{
// 		PrintFormat("[LifespanLevel] [GetLevel]: %1", m_Level);
// 		return m_Level;
// 	}

// 	override float GetThreshold()
// 	{
// 		PrintFormat("[LifespanLevel] [GetThreshold]: %1", m_Threshold);
// 		return m_Threshold;
// 	}

// 	override string GetTextureName()
// 	{
// 		PrintFormat("[LifespanLevel] [GetTextureName]: %1", m_TextureName);
// 		return m_TextureName;
// 	}

// 	override string GetMaterialName()
// 	{
// 		PrintFormat("[LifespanLevel] [GetMaterialName]: %1", m_MaterialName);
// 		return m_MaterialName;
// 	}
// };

modded class PluginLifespan
{
	// protected static const int LIFESPAN_MAX = 5; //debug

  	protected int m_TotalCountFacePaints;
  	protected int m_TotalCountFacePaintCategories;
	override void LoadFromCfg()
	{
		super.LoadFromCfg();
		CalculateFacePaintTotals();
	}

	protected void CalculateFacePaintTotals()
	{
		m_TotalCountFacePaints = 0;
		IAT_FacePaintsConfig iat_fp_config;
		if (GetDayZGame())
		{
			if (Class.CastTo(iat_fp_config, GetDayZGame().GetIATFacePaintConfig()))
			{
				IAT_FacePaintOptions fp_options = iat_fp_config.GetFacePaintOptions();
				TStringArray categories = fp_options.GetCategories();
				m_TotalCountFacePaintCategories = categories.Count();
				foreach (string category : categories)
				{
					TStringArray paintArray = fp_options.GetCategoryItems(category);
					m_TotalCountFacePaints += paintArray.Count();
				}
			}
		}
	}

	int GetFacePaintCount()
	{
		return m_TotalCountFacePaints;
	}
	int GetFacePaintCategoryCount()
	{
		return m_TotalCountFacePaintCategories;
	}

	override protected void SetPlayerLifespanLevel( PlayerBase player, LifespanLevel level )
	{
		if (player.GetFacePaintCategoryIndex() == -1)
		{
			// Print("set player lifespan level");
			super.SetPlayerLifespanLevel( player, level );
		}
		else
		{
			// Print("set player painted face");
			SetPaintedFaceMaterial(player, level);
		}
  	}
	string GetFemaleBaseMaterial(string playerType)
	{
		if ( m_BloodyHands.Contains(playerType))
			return m_BloodyHands.Get(playerType).GetMaterial(BloodyHands.MATERIAL_TYPE_NORMAL);
		return "";
	}

	string GetPaintByIndex(int categoryIndex, int paintIndex)
	{
		if (GetDayZGame())
		{
			IAT_FacePaintsConfig iat_fp_config;
			if (Class.CastTo(iat_fp_config, GetDayZGame().GetIATFacePaintConfig()))
			{
				IAT_FacePaintOptions fp_options = iat_fp_config.GetFacePaintOptions();
				string category = fp_options.GetCategories().Get(categoryIndex);
				string paint = fp_options.GetCategoryItems(category).Get(paintIndex);
				// PrintFormat("GetPaintByINdex: category: %1 paint: %2", category, paint);
				return string.Format("%1\\%2", category, paint);
			}
		}
		return "error";
	}
	protected string GetPaintPathMale(int facepaintCategoryIndex, int facepaintIndex, string materialName)
	{
		string facepaintCategory = GetPaintByIndex(facepaintCategoryIndex, facepaintIndex);

		TStringArray parts = new TStringArray;
		materialName.Split("\\", parts);
		string mat1 = materialName;
		if (parts.Count() == 6)
		{
			string filename = parts.Get(5);
			filename.Replace("_beard.", "_bearded.");
			mat1 = string.Format("iat_facepaints\\paints\\%1\\%2", facepaintCategory, filename);
			if (!FileExist(mat1))
			{
				filename.Replace("_bearded.", "_unshaved.");
				mat1 = string.Format("iat_facepaints\\paints\\%1\\%2", facepaintCategory, filename);
			}
			// Print("mat: " + mat1);
		}
		return mat1;
	}
	string GetPaintPathFemale(int facepaintCategoryIndex, int facepaintIndex, string materialName)
	{
		string facepaintCategory = GetPaintByIndex(facepaintCategoryIndex, facepaintIndex);
		TStringArray parts = new TStringArray;
		materialName.Split("_", parts);
		string mat1 = materialName;
		if (parts.Count() == 2)
		{
			string filename = parts.Get(1);
			mat1 = string.Format("iat_facepaints\\paints\\%1\\hhl_f_%2_body.rvmat", facepaintCategory, filename);
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

		string mat1 = GetPaintPathMale(player.GetFacePaintCategoryIndex(), player.GetFacePaintIndex(), level.GetMaterialName());
		// Print("material file: " + mat1);
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
					players_head.SetObjectMaterial( 0, "" );

					array< ref LifespanLevel> lifespan_levels = m_LifespanLevels.Get( player.GetPlayerClass() );
					LifespanLevel prev_level = lifespan_levels.Get(LifeSpanState.BEARD_LARGE);
					mat1 = GetPaintPathMale(player.GetFacePaintCategoryIndex(), player.GetFacePaintIndex(), prev_level.GetMaterialName());

					player.SetFaceTexture( prev_level.GetTextureName() );
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