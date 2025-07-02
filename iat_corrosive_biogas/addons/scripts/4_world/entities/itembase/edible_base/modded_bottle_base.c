modded class Bottle_Base
{
	override void AfterStoreLoad()
	{
		super.AfterStoreLoad();
		// if is empty and has cholera, remove the agents
		if (GetGame().IsDedicatedServer())
		{
			if (GetQuantity() < 0.01)
			{
				RemoveAgent(eAgents.CHOLERA);
			}
		}
	}
};