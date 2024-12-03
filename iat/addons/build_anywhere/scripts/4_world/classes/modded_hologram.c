modded class Hologram
{
  	override void EvaluateCollision(ItemBase action_item = null)
	{
		// do all the vanilla stuff
		super.EvaluateCollision(action_item);
		// turn off collision
		SetIsColliding(false);
	}
};