modded class ActionLightItemOnFire
{
	override void CreateConditionComponents()
	{
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.REPAIR );
		m_ConditionItem = new CCINonRuined;
	}
};