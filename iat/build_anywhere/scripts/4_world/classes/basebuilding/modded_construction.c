modded class Construction
{
	// remove the colliding check for constructed parts.
	// this allows building components that might be clipping into other things.
	override bool IsColliding( string part_name )
	{
		return false;
	}

	override bool IsCollidingEx( CollisionCheckData check_data )
	{
		return false;
	}
};