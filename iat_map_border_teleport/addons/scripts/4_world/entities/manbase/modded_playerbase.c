modded class PlayerBase
{
	protected PPERequester_IAT_MapBorderTeleport m_IAT_RequesterMapBorderTeleport;
	protected Particle m_IAT_MapBorderFog;

	protected ref HeadingRestrictData m_IAT_MBT_HeadingRestrictData;
	protected float m_IAT_MBT_LastHeadingDiff;

	// Store the last player position so we can revert back in the case of moving out of bounds.
	protected vector m_IAT_MBT_LastPlayerPosition = "0 0 0";

	// Server Side Only
	override void IAT_MBT_TryTeleportOutOfBoundsPlayer(int stepCounter)
	{
		IAT_PluginMapBoundary mapPlugin = IAT_PluginMapBoundary.Cast(GetPlugin(IAT_PluginMapBoundary));
		if (mapPlugin)
		{
			mapPlugin.CheckPlayer(this, stepCounter);
		}
	}

	// Client Side Only
	override void IAT_MBT_TryVisualEffects()
	{
		if (Class.CastTo(m_IAT_RequesterMapBorderTeleport, PPERequesterBank.GetRequester(PPERequester_IAT_MapBorderTeleport)))
		{
			float effectStrength = IAT_MBT_GetMapBorderIntensityEffect();
			if (effectStrength > 0.0)
			{
				IAT_MBT_TryUpdateVisualDesaturation(effectStrength);
				IAT_MBT_UpdateFogEffect(effectStrength);
			}
			else
			{
				// Stop the visuals
				IAT_MBT_StopVisualDesaturation();
				IAT_MBT_StopFogEffect();
			}
		}
	}

	override bool HeadingModel(float pDt, SDayZPlayerHeadingModel pModel)
	{
		float intensity = IAT_MBT_GetMapBorderIntensityEffect();
		// PrintFormat("======================================HEADING MODEL intensity: %1", intensity);
		// 60% progress towards the edge
		if (intensity > 0.1)
		{
			IAT_MBT_UpdateOrientation(pDt, pModel, intensity);
			IAT_MBT_UpdateHeadingRestriction(pModel, intensity);
			return DayZPlayerImplementHeading.RestrictHeading(pDt, pModel, m_IAT_MBT_LastHeadingDiff, m_IAT_MBT_HeadingRestrictData);
		}
		else
		{
			// Clear the restriction data once we no longer need it.
			if (m_IAT_MBT_HeadingRestrictData)
			{
				IAT_MBT_ClearHeadingRestriction();
			}
		}

		return super.HeadingModel(pDt, pModel);
	}
	void IAT_MBT_SaveLastSafePosition()
	{
		m_IAT_MBT_LastPlayerPosition = GetPosition();
	}
	vector IAT_MBT_GetLastSafePosition()
	{
		return m_IAT_MBT_LastPlayerPosition;
	}

	/*
	* HELPERS
	*/
	protected void IAT_MBT_UpdateOrientation(float pDt, SDayZPlayerHeadingModel pModel, float intensity)
	{
		float safeHeading = IAT_MBT_GetSafeHeading();

		float headingDiff = safeHeading - pModel.m_fOrientationAngle;

		// Normalize difference to -PI -> PI
		if (headingDiff < -Math.PI)
		{
			headingDiff += Math.PI2;
		}
		else if (headingDiff > Math.PI)
		{
			headingDiff -= Math.PI2;
		}

		// Dead zone to ensure we don't over trigger orientation updates
		if (Math.AbsFloat(headingDiff) < 0.01)
		{
			return;
		}

		// Increase turning strength near the edge
		float turnStrength = Math.Pow(intensity, 2);

		// Maximum radians per second
		float maxTurnSpeed = Math.Lerp(0, Math.PI * 1.5, turnStrength);
		float maxTurn = maxTurnSpeed * pDt;

		// Clamp the amount we rotate this frame
		float turnAmount = Math.Clamp(headingDiff, -maxTurn, maxTurn);

		// Rotate the player body
		pModel.m_fOrientationAngle += turnAmount;

		// Rotate the player's view with the body
		pModel.m_fHeadingAngle += turnAmount;

		// Keep our angles clean and between nominal values
		if (pModel.m_fOrientationAngle > Math.PI)
		{
			pModel.m_fOrientationAngle -= Math.PI2;
		}
		else if (pModel.m_fOrientationAngle < -Math.PI)
		{
			pModel.m_fOrientationAngle += Math.PI2;
		}
	}
	protected void IAT_MBT_UpdateHeadingRestriction(SDayZPlayerHeadingModel pModel, float intensity)
	{
		if (!m_IAT_MBT_HeadingRestrictData)
		{
			m_IAT_MBT_HeadingRestrictData = new HeadingRestrictData();
		}

		GetUApi().GetInputByID(UAMoveForward).ForceEnable(true);
		GetUApi().GetInputByID(UAMoveBack).ForceDisable(true);
		GetUApi().GetInputByID(UAMoveLeft).ForceDisable(true);
		GetUApi().GetInputByID(UAMoveRight).ForceDisable(true);

		// Make the restriction stronger near the edge
		float restrictionStrength = Math.Pow(intensity, 2);

		// How many degrees the player can still look away
		float allowedAngle = Math.Lerp(180, 5, restrictionStrength);

		float safeHeading = IAT_MBT_GetSafeHeading();

		m_IAT_MBT_HeadingRestrictData.InitData(safeHeading, Vector2(-allowedAngle, allowedAngle));
	}
	protected void IAT_MBT_ClearHeadingRestriction()
	{
		m_IAT_MBT_HeadingRestrictData = null;
		m_IAT_MBT_LastHeadingDiff = 0;
		GetUApi().GetInputByID(UAMoveForward).ForceEnable(false);
		GetUApi().GetInputByID(UAMoveBack).ForceDisable(false);
		GetUApi().GetInputByID(UAMoveLeft).ForceDisable(false);
		GetUApi().GetInputByID(UAMoveRight).ForceDisable(false);
	}
	protected void IAT_MBT_UpdateFogEffect(float intensity = 0.0)
	{
		if (!m_IAT_MapBorderFog)
		{
			m_IAT_MapBorderFog = ParticleManager.GetInstance().PlayOnObject(ParticleList.IAT_MBT_MAP_BORDER_FOG, this);
		}
	}
	protected void IAT_MBT_StopFogEffect()
	{
		if (m_IAT_MapBorderFog)
		{
			m_IAT_MapBorderFog.Stop();
			// Stop above removes it from the parent object but does not null it out for recreation
			m_IAT_MapBorderFog = null;
		}
	}
	protected void IAT_MBT_TryUpdateVisualDesaturation(float intensity = 0.0)
	{
		// Try to start the visual effects
		if (!m_IAT_RequesterMapBorderTeleport.IsRequesterRunning())
		{
			m_IAT_RequesterMapBorderTeleport.Start();
			// Print("start effects");
		}
		else
		{
			m_IAT_RequesterMapBorderTeleport.SetMapBorderEffects(intensity);
			// PrintFormat("update effects: %1", effectStrength);
		}
	}
	protected void IAT_MBT_StopVisualDesaturation()
	{
		if (m_IAT_RequesterMapBorderTeleport)
		{
			m_IAT_RequesterMapBorderTeleport.Stop();
		}
	}
	protected float IAT_MBT_GetMapBorderIntensityEffect()
	{
		IAT_PluginMapBoundary mapPlugin = IAT_PluginMapBoundary.Cast(GetPlugin(IAT_PluginMapBoundary));
		if (mapPlugin)
		{
			float intensity = mapPlugin.GetEdgeFactor(GetPosition(), GameConstants.IAT_MDT_WARNING_DISTANCE);
			return intensity;
		}
		return 0.0;
	}
	protected float IAT_MBT_GetSafeHeading()
	{
		IAT_PluginMapBoundary mapPlugin = IAT_PluginMapBoundary.Cast(GetPlugin(IAT_PluginMapBoundary));
		if (mapPlugin)
		{
			float heading = mapPlugin.GetSafeHeading(GetPosition());
			return heading;
		}
		return 0.0;
	}
};