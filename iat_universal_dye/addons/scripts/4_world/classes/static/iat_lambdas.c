class IAT_ReplaceItemWithNewLambda_Dye extends ReplaceItemWithNewLambdaBase
{
	override void CopyOldPropertiesToNew(notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);

		new_item.SetHealth(old_item.GetHealth());
	}
};