class IAT_DisplayCase_ColorBase extends Container_Base
{
	// bool to control if this display case is locked or unlocked
	protected bool m_IAT_IsDisplayLocked = true;
	// bool to toggle a hidden display case base
	protected bool m_IAT_HideDisplayBaseWhenFull = false;
	// is the object displayed animated?
	protected bool m_IAT_IsAnimated = false;
	// if so, how?
	protected float m_IAT_BobAmplitude = 0.0;
	protected float m_IAT_BobFrequency = 0.0;
	protected float m_IAT_RotationSpeedDegrees = 0.0;
	// it isnt a lie here, in fact we have double!
	protected const float TWO_PI = 6.283185;
	// keep track of how much we have animated (dt)
	protected float m_IAT_AnimTime = 0.0;
	// weak reference to the displayed object. everything is client side so no strong ref needed (handled via the cargo)
	protected EntityAI m_IAT_DisplayedItem;

	void IAT_DisplayCase_ColorBase()
	{
		IAT_SetConfigValues();
		RegisterNetSyncVariableBool("m_IAT_IsDisplayLocked");
		IAT_LockDisplayCase();
	}
	//=============================================================== VANILLA OVERRIDES
  	override void EOnSimulate(IEntity other, float dt)
	{
        //client only
		if (g_Game.IsDedicatedServer())
		{
            return;
		}
        IAT_AnimateDisplayObject(dt, m_IAT_BobAmplitude, m_IAT_BobFrequency, m_IAT_RotationSpeedDegrees);
	}
	override void SetActions()
	{
		super.SetActions();
		// base object should not be takeable in any case (dismantle)
		RemoveAction(ActionTakeItem);
		RemoveAction(ActionSwapItemToHands);
		RemoveAction(ActionTakeItemToHands);
	}
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		IAT_UpdateDisplayCase();
	}
	override string GetDisplayName()
	{
		string itemName = super.GetDisplayName();
		if (IAT_IsDisplayCaseLocked())
		{
			itemName = itemName + " - Locked";
		}
		return itemName;
	}
	override bool IsHealthVisible()
	{
		return false;
	}
	override bool DisableVicinityIcon()
	{
		return true;
	}
	override bool IsTakeable()
	{
		return false;
	}
	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
	override bool CanPutIntoHands (EntityAI parent)
	{
		return false;
	}
	override bool CanReceiveItemIntoCargo (EntityAI item)
	{
		// only allow 1 item in the cargo
		return GetInventory().GetCargo().GetItemCount() < 1;
	}
	override bool CanLoadItemIntoCargo( EntityAI item )
	{
		// only allow 1 item in the cargo
		return GetInventory().GetCargo().GetItemCount() < 1;
	}
	override bool CanReleaseCargo( EntityAI cargo )
	{
		// only allow taking cargo if the case is unlocked
		return !IAT_IsDisplayCaseLocked();
	}
	override void EECargoIn(EntityAI item)
	{
		super.EECargoIn(item);
		// when the item comes into the cargo, create it locally (delay for startup reasons)
		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(IAT_CreateDisplayObject, 300, false, item);
		IAT_UpdateBaseVisuals(true);
	}
	override void EECargoOut(EntityAI item)
	{
		super.EECargoOut(item);
		// when the item comes out of the cargo, delete the local copy
		IAT_DeleteDisplayObject();
		IAT_UpdateBaseVisuals(false);
	}
	//=============================================================== CUSTOM CODE
	void IAT_SetConfigValues()
	{
		if (ConfigGetBool("m_IAT_HideDisplayBaseWhenFull"))
		{
			m_IAT_HideDisplayBaseWhenFull = ConfigGetBool("m_IAT_HideDisplayBaseWhenFull");
		}
		if (ConfigGetBool("m_IAT_IsAnimated"))
		{
			m_IAT_IsAnimated = ConfigGetBool("m_IAT_IsAnimated");
		}
		if (ConfigGetFloat("m_IAT_BobAmplitude"))
		{
			m_IAT_BobAmplitude = ConfigGetFloat("m_IAT_BobAmplitude");
		}
		if (ConfigGetFloat("m_IAT_BobFrequency"))
		{
			m_IAT_BobFrequency = ConfigGetFloat("m_IAT_BobFrequency");
		}
		if (ConfigGetFloat("m_IAT_RotationSpeedDegrees"))
		{
			m_IAT_RotationSpeedDegrees = ConfigGetFloat("m_IAT_RotationSpeedDegrees");
		}
	}
	void IAT_UpdateDisplayCase()
	{
		if (IAT_IsDisplayCaseLocked())
		{
			IAT_LockDisplayCase();
		}
		else
		{
			IAT_UnLockDisplayCase();
		}
	}
	// call only on server side
	void IAT_SetLocked(bool securityState)
	{
		m_IAT_IsDisplayLocked = securityState;
	}
	bool IAT_IsDisplayCaseLocked()
	{
		return m_IAT_IsDisplayLocked;
	}
	vector IAT_GetDisplayObjectSpawnPosition(string memoryPoint="spawn_pos")
	{
		// default spawn position is 1m above origin (x, y, z)
		vector spawnPosition = "0 1 0";
		// if the memory point exists
		if (MemoryPointExists(memoryPoint))
		{
			// get the vector that is in local space
			spawnPosition = GetMemoryPointPos(memoryPoint);
		}
		return spawnPosition;
	}
	// convenience function if some objects need special rotating for some reason
	vector IAT_GetDisplayObjectSpawnOrientation(EntityAI displayedObject)
	{
		return "0 0 0";
	}
	void IAT_LockDisplayCase()
	{
		if (g_Game.IsDedicatedServer())
		{
			if (GetInventory())
			{
				// lock any slot on this object
				int slot_id;
				ItemBase item;
				EntityAI childItem;
				for ( int i = 0; i < GetInventory().GetAttachmentSlotsCount(); i++ )
				{
					slot_id = GetInventory().GetAttachmentSlotId(i);
					GetInventory().SetSlotLock(slot_id, true);
					// Print("IAT_LockDisplayCase Slot ID: " + slot_id);
					if (Class.CastTo(item, GetInventory().FindAttachment(slot_id)))
					{
						// Print("IAT_LockDisplayCase Slot Item: " + item + " Sloot count: "  + item.GetInventory().GetAttachmentSlotsCount());
						for ( int k = 0; k < item.GetInventory().GetAttachmentSlotsCount(); k++ )
						{
							slot_id = item.GetInventory().GetAttachmentSlotId(k);
							// Print("Item Slot ID: " + slot_id);
							item.GetInventory().SetSlotLock(slot_id, true);
						}
					}
				}
			}
			// set the container to locked
			IAT_SetLocked(true);
			// synced to client
			SetSynchDirty();
		}
	}
	void IAT_UnLockDisplayCase()
	{
		if (g_Game.IsDedicatedServer())
		{
			if (GetInventory())
			{
				// unlock the attachment slots
				int slot_id;
				ItemBase item;
				EntityAI childItem;
				for ( int i = 0; i < GetInventory().GetAttachmentSlotsCount(); i++ )
				{
					slot_id = GetInventory().GetAttachmentSlotId(i);
					GetInventory().SetSlotLock(slot_id, false);
					// Print("IAT_UnLockDisplayCase Slot ID: " + slot_id);
					if (Class.CastTo(item, GetInventory().FindAttachment(slot_id)))
					{
						// Print("IAT_UnLockDisplayCase Slot Item: " + item + " Sloot count: "  + item.GetInventory().GetAttachmentSlotsCount());
						for ( int k = 0; k < item.GetInventory().GetAttachmentSlotsCount(); k++ )
						{
							slot_id = item.GetInventory().GetAttachmentSlotId(k);
							// Print("Item Slot ID: " + slot_id);
							item.GetInventory().SetSlotLock(slot_id, false);
						}
					}
				}
			}
			// set container to unlocked
			IAT_SetLocked(false);
			// sync to client
			SetSynchDirty();
		}
	}
	void IAT_CreateDisplayObject(EntityAI item)
	{
		// if the object already exists, dont make a new one
		if (m_IAT_DisplayedItem)
			return;

		int flags = ECE_IN_INVENTORY|ECE_LOCAL|ECE_KEEPHEIGHT|ECE_NOLIFETIME|ECE_NOPERSISTENCY_WORLD|ECE_NOPERSISTENCY_CHAR;
		// create an object at 0 0 0 to be moved where needed
		if (Class.CastTo(m_IAT_DisplayedItem, g_Game.CreateObjectEx(item.GetType(), "0 0 0", flags)))
		{
			// remove the ability for this local object to be taken
			m_IAT_DisplayedItem.SetTakeable(false);

			m_IAT_DisplayedItem.SetOrientation(IAT_GetDisplayObjectSpawnPosition());
			m_IAT_DisplayedItem.SetPosition(IAT_GetDisplayObjectSpawnPosition());

			if (item.GetInventory())
			{
				EntityAI attachment;
				int totalSlots = item.GetInventory().AttachmentCount();
				// for each slot on the item
				for (int i = 0; i < totalSlots; i++)
				{
					// cast that attachment to an entity
					if (Class.CastTo(attachment, item.GetInventory().GetAttachmentFromIndex(i)))
					{
						if (!g_Game.IsDedicatedServer())
						{
							// create it locally
							m_IAT_DisplayedItem.GetInventory().CreateAttachment(attachment.GetType());
						}
					}
				}
			}
			// attach this object to the display case
			this.AddChild(m_IAT_DisplayedItem, -1);
			this.Update();

			if (m_IAT_IsAnimated)
			{
				SetEventMask(EntityEvent.SIMULATE);
			}
		}
	}
	void IAT_DeleteDisplayObject()
	{
		// delete the object if it exists
		if (m_IAT_DisplayedItem)
		{
			array<typename> types = {m_IAT_DisplayedItem.Type()};
			MiscGameplayFunctions.DeleteAttachedChildrenByTypename(this, types);
			this.Update();

			if (m_IAT_IsAnimated)
			{
				ClearEventMask(EntityEvent.SIMULATE);
			}
		}
	}
	void IAT_UpdateBaseVisuals(bool isHidden)
	{
		// if we do not need to hide the base
		if (!m_IAT_HideDisplayBaseWhenFull)
		{
			return;
		}
		// client side visuals only
		if (!g_Game.IsDedicatedServer())
		{
			if (isHidden)
			{
				SetObjectTexture(GetHiddenSelectionIndex("zbytek"), "");
			}
			else
			{
				TStringArray selections = GetHiddenSelectionsTextures();
				// sanity check
				if (selections.IsValidIndex(0))
				{
					SetObjectTexture(GetHiddenSelectionIndex("zbytek"), GetHiddenSelectionsTextures().Get(0));
				}
			}
		}
	}
	void IAT_AnimateDisplayObject(float deltaTime, float bobAmplitude=2.0, float bobFrequency=0.15, float rotationSpeedDeg=10.0)
	{
		if (!m_IAT_IsAnimated)
		{
			return;
		}
		if (!m_IAT_DisplayedItem)
		{
			return;
		}
		// advance local animation time
		m_IAT_AnimTime += deltaTime;

		// compute bobbing offset using a sine wave
		float bobOffset = bobAmplitude * Math.Sin(m_IAT_AnimTime * TWO_PI * bobFrequency);

		// base spawn position in world space from memory point, then apply bobbing on Y
		vector baseWorldPos = IAT_GetDisplayObjectSpawnPosition();
		baseWorldPos[1] = baseWorldPos[1] + (bobOffset * deltaTime);
		m_IAT_DisplayedItem.SetPosition(baseWorldPos);

		// rotate slowly around local Y (yaw) in degrees per update
		vector newOri = m_IAT_DisplayedItem.GetOrientation() + Vector(m_IAT_AnimTime * rotationSpeedDeg, 0, 0);
		// wrap around 360 degrees
		if (newOri[0] > 360.0)
		{
			newOri[0] = newOri[0] - 360.0;
		}
		m_IAT_DisplayedItem.SetOrientation(newOri);
	}
};

class IAT_DisplayCase_Coaster extends IAT_DisplayCase_ColorBase{};
class IAT_DisplayCase_Glass extends IAT_DisplayCase_ColorBase{};
class IAT_DisplayCase_GlassAnimated extends IAT_DisplayCase_ColorBase{};