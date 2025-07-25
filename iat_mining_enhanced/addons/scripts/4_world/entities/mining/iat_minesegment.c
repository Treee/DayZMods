// these are land_ based objects meant for map baking
class IAT_MiningSegment_Colorbase extends House
{
	protected vector m_TeleportDestination;

	override bool IsInventoryVisible()
	{
		return false;
	}
	override bool IsHealthVisible()
	{
		return false;
	}
	override bool CanPutIntoHands( EntityAI parent )
	{
		return false;
	}
	override bool CanPutInCargo (EntityAI parent)
	{
		return false;
	}
	override bool IsTakeable()
	{
		return false;
	}

	//=============================================== GETTERS & SETTERS
	void SetTeleportDestination(vector position)
	{
		m_TeleportDestination = position;
	}
	vector GetTeleportDestination()
	{
		return m_TeleportDestination;
	}
};

class land_iat_miningsegment_entrance extends IAT_MiningSegment_Colorbase
{
	void CreateMiningExit(vector returnPosition, vector surfacePosition)
	{
		vector underground = surfacePosition + "0 100 0";

		land_iat_miningsegment_junction m_LinkedExit;
		// create a junction at the location underneath the action target
		if (Class.CastTo(m_LinkedExit, GetGame().CreateObjectEx("land_iat_miningsegment_junction", underground, ECE_SETUP|ECE_CREATEPHYSICS|ECE_KEEPHEIGHT)))
		{
			//setup new mining config entry for this


			// get the position we should spawn the player.
			// if the memory point in the p3d doesnt exist, use a default
			vector pos;
			if (MemoryPointExists(GetPlayerSpawnMemoryPoint()))
			{
				pos = GetMemoryPointPos(GetPlayerSpawnMemoryPoint());
				pos = ModelToWorld(pos);
			}
			else
			{
				pos = underground;
			}
			// set the underground destination for the entrance
			SetTeleportDestination(pos);
			// set the surface destination for the exit underground
			m_LinkedExit.SetTeleportDestination(returnPosition);
		}
	}

	string GetPlayerSpawnMemoryPoint()
	{
		return "player_spawn";
	}

	bool CanEnterMine()
	{
		return true;
	}
};

class land_iat_miningsegment_junction extends IAT_MiningSegment_Colorbase{};