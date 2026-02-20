modded class EmoteManager
{
	override bool CanPlayEmote(int id)
	{
		// vanilla says we can play so play!
		if (super.CanPlayEmote(id))
		{
			return true;
		}
		// in the case of a false, do some extra checks for our soft surrender
		if (id == EmoteConstants.ID_EMOTE_SURRENDER)
		{
			if (m_Player.IAT_IsSoftSurrendered())
			{
				return true;
			}
		}
		// pass through false vanilla stuff
		return false;
	}
	//Called from players commandhandler each frame, checks input
	override void Update(float deltaT)
	{
		// check if soft surrendered since it triggers is restrained
		// soft surrendered targets need a way to put down their hands
		// so this allows that but ensures restrained targets cannot do emotes
		if (!m_Player.IAT_IsSoftSurrendered())
		{
			super.Update(deltaT);
		}
		else // just duplicate vanilla code... sucks it has to be this way but no biggie
		{
			if (m_ItemToBeCreated)
			{
				if (GetGame().IsServer() && m_Callback && !m_Player.GetItemInHands())
				{
					m_Player.GetHumanInventory().CreateInHands("SurrenderDummyItem");
				}
				m_ItemToBeCreated = false;
			}

			int gestureSlot = 0;
			#ifndef SERVER
				gestureSlot = DetermineGestureIndex();
			#endif

			//nuclear solution to inventory question
			if (GetGame().IsClient() && GetGame().GetUIManager().FindMenu(MENU_INVENTORY) && IsEmotePlaying())
				m_Player.CloseInventoryMenu();

			//deferred emote cancel
			if (m_InstantCancelEmote) //'hard' cancel
			{
				if (m_Callback)
					m_Callback.Cancel();

				ClearEmoteLauncher();
				ClearDeferredExecution();
				m_InstantCancelEmote = false;
				SetPending(false);

				if (m_IsSurrendered)
					ClearSurrenderState();
				else
					SetEmoteLockState(false);
			}
			else if (m_CancelEmote) //'soft' cancel
			{
				SetPending(false);
				m_CancelEmote = false;

				if (m_IsSurrendered)
					ClearSurrenderState();
				else if (m_Callback)
					m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_INTERRUPT);
			}

			if (m_DeferredEmoteLauncherCleanup)
			{
				ClearEmoteLauncher(true);
				m_DeferredEmoteLauncherCleanup = false;
			}

			//if (m_DisconnectEmoteQueued && (!m_bEmoteIsPlaying && !m_bEmoteIsRequestPending))
			if (m_DisconnectEmoteQueued)
			{
				if (!m_MenuEmote || !m_MenuEmote.IsStartGuaranteed())
				{
					CreateEmoteCBFromMenu(EmoteConstants.ID_EMOTE_SITA);
					m_MenuEmote.SetForced(EmoteLauncher.FORCE_DIFFERENT);
					m_MenuEmote.SetStartGuaranteed(true);
				}
			}

			bool forcedEmoteQueuedClient = m_MenuEmote && !m_MenuEmote.WasSynced() && m_MenuEmote.GetForced() > EmoteLauncher.FORCE_NONE && !GetGame().IsDedicatedServer();
			if (forcedEmoteQueuedClient) //regular forced emote playing
			{
				SendEmoteRequestSyncEx(m_MenuEmote);
			}
			else if (m_Callback)
			{
				bool uiGesture = false;
				if (!GetGame().IsDedicatedServer())
				{
					uiGesture = GetGame().GetUIManager().IsMenuOpen(MENU_GESTURES);

					if (InterruptGestureCheck())
					{
						SendEmoteRequestSync(CALLBACK_CMD_END);
					}

					if (InterruptWaterCheck())
					{
						SendEmoteRequestSync(CALLBACK_CMD_INSTACANCEL);
					}
				}

				if (gestureSlot > 0 || m_GestureInterruptInput || (m_HIC.IsSingleUse() && !uiGesture) || (m_HIC.IsContinuousUseStart() && !uiGesture) || (m_Callback.m_IsFullbody && !uiGesture && m_HIC.IsWeaponRaised()))
				{
					if (m_CurrentGestureID == EmoteConstants.ID_EMOTE_SUICIDE && m_HIC.IsSingleUse())
					{
						if (m_Callback.GetState() == m_Callback.STATE_LOOP_LOOP)
						{
							CommitSuicide();
						}
						else
						{
							return;
						}
					}
					else if ((m_CurrentGestureID == EmoteConstants.ID_EMOTE_THUMB || m_CurrentGestureID == EmoteConstants.ID_EMOTE_THUMBDOWN) && m_HIC.IsSingleUse())
					{
						m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_ACTION);
					}
					else if (m_HIC.IsSingleUse() && (m_CurrentGestureID == EmoteConstants.ID_EMOTE_RPS || m_CurrentGestureID == EmoteConstants.ID_EMOTE_RPS_R || m_CurrentGestureID == EmoteConstants.ID_EMOTE_RPS_P || m_CurrentGestureID == EmoteConstants.ID_EMOTE_RPS_S))
					{
						if (m_RPSOutcome != -1)
						{
							if (m_RPSOutcome == 0)
							{
								m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_RPS_ROCK);
							}
							else if (m_RPSOutcome == 1)
							{
								m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_RPS_PAPER);
							}
							else if (m_RPSOutcome == 2)
							{
								m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_RPS_SCISSORS);
							}
							m_RPSOutcome = -1;
						}
						else
						{
							m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_END);
						}
					}
					else if (m_CurrentGestureID != EmoteConstants.ID_EMOTE_SUICIDE || (m_CurrentGestureID == EmoteConstants.ID_EMOTE_SUICIDE && m_Callback.GetState() < 3))
					{
						SendEmoteRequestSync(CALLBACK_CMD_END);
					}
					else if (m_CurrentGestureID == EmoteConstants.ID_EMOTE_SUICIDE)
					{
						SendEmoteRequestSync(CALLBACK_CMD_END);
					}
				}

				if (m_LastMask != -1 && m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
				{
					m_Callback.Cancel();
				}

				if (m_MenuEmote && !m_MenuEmote.IsStartGuaranteed() && m_bEmoteIsPlaying)
				{
					SendEmoteRequestSync(CALLBACK_CMD_END);
				}

				if (m_DeferredEmoteExecution == CALLBACK_CMD_END)
				{
					EndCallbackCommand();
				}

				if (m_DeferredEmoteExecution == CALLBACK_CMD_GESTURE_INTERRUPT)
				{
					InterruptCallbackCommand();
				}
			}
			//no m_Callback exists
			else
			{
				if (m_bEmoteIsRequestPending && (m_Player.IsUnconscious() || !m_Player.IsAlive()))
				{
					SetPending(false);
				}

				if (m_bEmoteIsPlaying)
				{
					OnEmoteEnd();
				}
				else if (!m_Player.GetItemInHands() && m_IsSurrendered && !m_ItemToBeCreated && (!m_MenuEmote || m_MenuEmote.GetForced() != EmoteLauncher.FORCE_NONE)) //play only when there is time to do so
				{
					PlaySurrenderInOut(false);
					return;
				}
				// getting out of surrender state
				else if (m_IsSurrendered && m_Player.GetItemInHands() && (m_HIC.IsSingleUse() || m_HIC.IsContinuousUseStart() || m_HIC.IsWeaponRaised()))
				{
					if (m_Player.GetItemInHands())
						m_Player.GetItemInHands().DeleteSafe();//Note, this keeps item 'alive' until it is released by all the systems (inventory swapping etc.)
					return;
				}
				// fallback in case lock does not end properly
				else if (m_IsSurrendered && (!m_Player.GetItemInHands() || (m_Player.GetItemInHands() && m_Player.GetItemInHands().GetType() != "SurrenderDummyItem" && m_EmoteLockState)))
				{
					ClearSurrenderState();
					return;
				}
				//actual emote launch
				else if (m_DeferredEmoteExecution > CALLBACK_CMD_INVALID)
				{
					PlayEmote(m_DeferredEmoteExecution);
					//m_DeferredGuaranteedEmoteId = CALLBACK_CMD_INVALID;
				}
				else if (m_DeferredGuaranteedEmoteId > CALLBACK_CMD_INVALID)
				{
					PlayEmote(m_DeferredGuaranteedEmoteId);
					m_DeferredGuaranteedEmoteId = CALLBACK_CMD_INVALID;
				}
				//client-side emote launcher
				else if (!m_bEmoteIsPlaying && m_MenuEmote && !m_MenuEmote.WasSynced() && !GetGame().IsDedicatedServer())
				{
					SendEmoteRequestSyncEx(m_MenuEmote);
				}
				else if (!m_MenuEmote && gestureSlot > 0)
				{
					CreateEmoteCBFromMenu(gestureSlot,true); //translation no longer needed
				}
			}
		}
	}

};