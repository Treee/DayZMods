modded class ItemBase
{
	override void OnRightClick()
    {
        if (CanBeSplit() && !GetDayZGame().IsLeftCtrlDown() && GetDayZGame().IAT_SIS_IsLeftShiftDown() && !GetGame().GetPlayer().GetInventory().HasInventoryReservation(this,null))
        {
            SplitIntoSingleItemClient();
        }
        else
        {
            super.OnRightClick();
        }
    }
    void SplitIntoSingleItemClient()
    {
        if (GetGame().IsClient())
        {
			if (ScriptInputUserData.CanStoreInputUserData())
			{
				EntityAI root = GetHierarchyRoot();
				Man playerOwner = GetHierarchyRootPlayer();
				InventoryLocation dst = new InventoryLocation;

				// If we have no hierarchy root player and the root is the same as this item the source item is in the vicinity so we want to create the new split item there also
				if (!playerOwner && root && root == this)
				{
					SetInventoryLocationToVicinityOrCurrent(root, dst);
				}
				else
				{
					// Check if we can place the new split item in the same parent where the source item is placed in or otherwise drop it in vicinity
					GetInventory().GetCurrentInventoryLocation(dst);
					if (!dst.GetParent() || dst.GetParent() && !dst.GetParent().GetInventory().FindFreeLocationFor(this, FindInventoryLocationType.CARGO, dst))
					{
						PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
						if (!player.GetInventory().FindFreeLocationFor(this, FindInventoryLocationType.CARGO, dst) || !playerOwner)
						{
							SetInventoryLocationToVicinityOrCurrent(root, dst);
						}
						else
						{
							dst.SetCargo(dst.GetParent(), this, dst.GetIdx(), dst.GetRow(), dst.GetCol(), dst.GetFlip());
							/*	hacky solution to check reservation of "this" item instead of null since the gamecode is checking null against null and returning reservation=true incorrectly
								this shouldnt cause issues within this scope*/
							if (GetGame().GetPlayer().GetInventory().HasInventoryReservation(this, dst))
							{
								SetInventoryLocationToVicinityOrCurrent(root, dst);
							}
							else
							{
								GetGame().GetPlayer().GetInventory().AddInventoryReservationEx(null, dst, GameInventory.c_InventoryReservationTimeoutShortMS);
							}
						}
					}
				}

				ScriptInputUserData ctx = new ScriptInputUserData;
				ctx.Write(IAT_INPUT_UDT_ITEM_MANIPULATION_SINGLEITEM);
				ctx.Write(4);
				ItemBase thiz = this; // @NOTE: workaround for correct serialization
				ctx.Write(thiz);
				dst.WriteToContext(ctx);
				ctx.Write(true); // dummy
				ctx.Send();
			}
        }
        else if (!GetGame().IsMultiplayer())
        {
            SplitItemSingle(PlayerBase.Cast(GetGame().GetPlayer()));
        }
    }
    void SplitSingleItemToInventoryLocation(notnull InventoryLocation dst)
    {
		float quantity = GetQuantity();
		float split_quantity_new = 1;

		if (!ShouldSplitQuantity(split_quantity_new))
			return;

		ItemBase new_item = ItemBase.Cast(GameInventory.LocationCreateEntity(dst, GetType(), ECE_IN_INVENTORY, RF_DEFAULT));

        if (new_item)
		{
			if (new_item.GetQuantityMax() < split_quantity_new)
			{
				split_quantity_new = new_item.GetQuantityMax();
			}

			new_item.SetResultOfSplit(true);
			MiscGameplayFunctions.TransferItemProperties(this, new_item);

			if (dst.IsValid() && dst.GetType() == InventoryLocationType.ATTACHMENT && split_quantity_new > 1)
			{
				AddQuantity(-1, false, true);
				new_item.SetQuantity(1, false, true);
			}
			else
			{
				AddQuantity(-split_quantity_new, false, true);
				new_item.SetQuantity(split_quantity_new, false, true);
			}
		}
    }
    void SplitItemSingle(PlayerBase player)
    {
		float quantity = GetQuantity();
		float split_quantity_new = 1;

		if (!ShouldSplitQuantity(split_quantity_new))
			return;

		InventoryLocation invloc = new InventoryLocation;
		bool found = player.GetInventory().FindFirstFreeLocationForNewEntity(GetType(), FindInventoryLocationType.ATTACHMENT, invloc);

		ItemBase new_item;
		new_item = player.CreateCopyOfItemInInventoryOrGroundEx(this, true);

        if (new_item)
		{
			if (new_item.GetQuantityMax() < split_quantity_new)
			{
				split_quantity_new = new_item.GetQuantityMax();
			}
			if (found && invloc.IsValid() && invloc.GetType() == InventoryLocationType.ATTACHMENT && split_quantity_new > 1)
			{
				AddQuantity(-1, false, true);
				new_item.SetQuantity(1, false, true);
			}
			else if (split_quantity_new > 1)
			{
				AddQuantity(-split_quantity_new, false, true);
				new_item.SetQuantity(split_quantity_new, false, true);
			}
		}
    }
};