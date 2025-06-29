// copy/paste from plate carrier
class IAT_ImprovisedArmor_Colorbase: Vest_Base
{
	override void OnWasAttached( EntityAI parent, int slot_id )
	{
		super.OnWasAttached( parent, slot_id );

		if ( GetGame().IsServer() && parent.IsInherited( DayZInfected ) )
		{
			float coef = Math.RandomFloatInclusive( 0.2, 0.4 );
			SetHealth01( "", "", coef);
		}
	}
};
class IAT_ImprovisedArmor_Basic extends IAT_ImprovisedArmor_Colorbase{};
class IAT_ImprovisedArmor_GuyBiggsly extends IAT_ImprovisedArmor_Colorbase{};
