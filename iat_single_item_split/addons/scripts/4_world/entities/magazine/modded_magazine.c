modded class Ammunition_Base
{
	override void SplitItemToInventoryLocation( notnull InventoryLocation dst )
	{
		if (CanBeSplit() && !GetDayZGame().IsLeftCtrlDown() && GetDayZGame().IAT_SIS_IsLeftShiftDown() && !GetGame().GetPlayer().GetInventory().HasInventoryReservation(this,null))
		{
			SplitSingleItemToInventoryLocation(dst);
		}
		else
		{
			super.SplitItemToInventoryLocation(dst);
		}
	}

	override void SplitItem(PlayerBase player)
	{
		if (CanBeSplit() && !GetDayZGame().IsLeftCtrlDown() && GetDayZGame().IAT_SIS_IsLeftShiftDown() && !GetGame().GetPlayer().GetInventory().HasInventoryReservation(this,null))
		{
			SplitSingleItem(player);
		}
		else
		{
			super.SplitItem(player);
		}
	}

	override void SplitSingleItemToInventoryLocation( notnull InventoryLocation dst )
	{
		if ( !CanBeSplit() )
			return;

		Magazine new_pile = Magazine.Cast( GameInventory.LocationCreateEntity( dst, GetType(), ECE_IN_INVENTORY, RF_DEFAULT ) );
		if( new_pile )
		{
			MiscGameplayFunctions.TransferItemProperties(dst.GetItem(), new_pile);

			new_pile.ServerSetAmmoCount(0);

			// just grab the first one
			float damage;
			string cartrige_name;
			ServerAcquireCartridge(damage, cartrige_name);
			new_pile.ServerStoreCartridge(damage, cartrige_name);

			new_pile.SetSynchDirty();
			SetSynchDirty();
		}
	}

	void SplitSingleItem(PlayerBase player)
	{
		if ( !CanBeSplit() )
			return;

		Magazine new_pile = Magazine.Cast( player.CreateCopyOfItemInInventoryOrGround( this ) );
		if( new_pile )
		{
			new_pile.ServerSetAmmoCount(0);

			// just grab the first one
			float damage;
			string cartrige_name;
			ServerAcquireCartridge(damage, cartrige_name);
			new_pile.ServerStoreCartridge(damage, cartrige_name);

			new_pile.SetSynchDirty();
			SetSynchDirty();
		}
	}
};