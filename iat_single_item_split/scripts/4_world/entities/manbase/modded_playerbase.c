modded class PlayerBase
{
	override bool HandleRemoteItemManipulation(int userDataType, ParamsReadContext ctx)
    {
		// our own item maniupulation type
        if( userDataType == IAT_INPUT_UDT_ITEM_MANIPULATION_SINGLEITEM )
        {
			int type = -1;
			ItemBase item1 = null;
			// read the type
			if (!ctx.Read(type))
				return false;
			// read a dummy value
			if (type == 4)
			{
				// read the item
				if (!ctx.Read(item1))
				{
					return false;
				}

				// read the iventory location
				InventoryLocation dst = new InventoryLocation;
				if (item1 && dst.ReadFromContext(ctx))
				{
					// read a dummy value
					//Print(InventoryLocation.DumpToStringNullSafe(dst));
					bool dummy;
					if (ctx.Read(dummy))
					{
						// split single item
                		item1.SplitSingleItemToInventoryLocation(dst);
						return true;
					}
				}
			}
			return false;
		}
		// preserve call chain
		return super.HandleRemoteItemManipulation(userDataType, ctx);
    }
};