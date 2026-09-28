class IAT_CustomMap_ColorBase extends ChernarusMap
{
	/*
	* Normal vanilla maps read their information directly from the CfgWorlds config.cpp
	* Our custom maps just read from our config.cpp to pull the values cleanly
	*/
	override void InitMapState()
	{
		string path = string.Format("%1 %2", CFG_VEHICLESPATH, GetType());

		// m_DisplayName and description are properties on ItemMap, just stuff new values into them
		GetGame().ConfigGetText(string.Format("%1 %2", path, "displayName"), m_DisplayName);
		GetGame().ConfigGetText(string.Format("%1 %2", path, "descriptionShort"), m_Description);
	}

	// our custom maps do not have markers (perhaps they do?) so I just hard override this function to not sync markers
	override void SyncMapMarkers() {}
}


class IAT_CustomMap_Example1 extends IAT_CustomMap_ColorBase{};
class IAT_CustomMap_Example2 extends IAT_CustomMap_ColorBase{};
