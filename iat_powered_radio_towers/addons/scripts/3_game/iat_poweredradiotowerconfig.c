class IAT_PoweredRadioTowerConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "PoweredRadioTowerConfig.json";

	protected ref array<ref IAT_PoweredTowerConsoleData> m_TowerConsoleData;

	IAT_PoweredRadioTowerConfig TryGetPoweredRadioTowerConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			MakeDirectory(rootFilePath);
		}

		string errorMessage;
		// new object so the non serialzied values are created
		IAT_PoweredRadioTowerConfig iat_PRTConfig = new IAT_PoweredRadioTowerConfig();
		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			// new config object
			// iat_PRTConfig = new IAT_PoweredRadioTowerConfig();

			// set some default values
			iat_PRTConfig.m_TowerConsoleData = new array<ref IAT_PoweredTowerConsoleData>;

			// <group name="Land_Tower_TC2_Top" pos="6405.446777 1291.985107 8920.974609" rpy="-0.000000 0.000000 -61.363876" a="151.364"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(0, false, false, false, false, 0, 4, "6407.319824 1192.000000 8926.440430", "-155.999893 0 0"));
			// <group name="Land_Tower_TC3_Grey" pos="11271.684570 449.513306 5890.544922" rpy="-0.000000 0.000000 11.602386" a="78.3976"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(1, false, false, false, false, 0, 2, "11272.099609 488.100006 5892.560059", "10.999234 0 0"));
			// <group name="Land_Tower_TC3_Red" pos="426.468842 404.959412 11660.050781" rpy="-0.000000 0.000000 0.125122" a="89.8749"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(2, false, false, false, false, 0, 9, "425.549988 443.600006 11658.05", "180 0 0"));
			// <group name="Land_Tower_TC3_Red" pos="560.563782 774.395508 601.031372" rpy="-0.000000 0.000000 0.000000" a="90"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(3, false, false, false, false, 0, 1, "552.632019 776.015015 622.414978", "-90 0 0"));
			// <group name="Land_Tower_TC3_Red" pos="1235.441650 490.399445 11815.665039" rpy="-0.000000 0.000000 0.125122" a="89.8749"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(4, false, false, false, false, 0, 3, "1234.390015 529 11817.700195", "0 0 0"));
			// <group name="Land_Tower_TC3_Red" pos="1917.546265 202.355194 9203.582031" rpy="-0.000000 0.000000 0.126669" a="89.8733"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(5, false, false, false, false, 0, 5, "1917.550049 241 9201.549805", "180 0 0"));
			// <group name="Land_Tower_TC3_Red" pos="1453.878418 215.979416 9579.574219" rpy="-0.000000 0.000000 178.030182" a="-88.0302"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(6, false, false, false, false, 0, 6, "1453.849976 254.600006 9581.599609", "-2.998346 0 0"));
			// <group name="Land_Tower_TC3_Red" pos="2835.284424 369.939575 9850.475586" rpy="-0.000000 0.000000 90.238609" a="-0.238609"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(7, false, false, false, false, 0, 3, "2835.250000 408.500000 9852.549805", "0 0 0"));
			// <group name="Land_Tower_TC3_Red" pos="3023.887939 369.949402 10344.426758" rpy="-0.000000 0.000000 0.703323" a="89.2967"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(8, false, false, false, false, 0, 1, "3023.860107 408.500000 10342.400391", "180 0 0"));
			// <group name="Land_Tower_TC4_Top" pos="6892.339355 1221.804077 8751.302734" rpy="-0.000000 0.000000 16.887920" a="73.1121"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(9, false, false, false, false, 0, 5, "6892.810059 1219 8753.019531", "-164.000137 0 0"));
			// <group name="Land_Tower_TC4_Top" pos="2938.620605 1398.418823 2484.343750" rpy="-0.000000 0.000000 0.000000" a="90"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(10, false, false, false, false, 0, 2, "2938.600098 1395.699951 2482.570068", "0 0 0"));
			// <group name="Land_Tower_TC4_Top" pos="564.042664 535.561096 6843.620117" rpy="-0.000000 0.000000 0.000000" a="90"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(11, false, false, false, false, 0, 4, "564 532.700012 6845.390137", "180 0 0"));
			// <group name="Land_Tower_TC4_Top" pos="753.799988 636.359375 8695.880859" rpy="-0.000000 0.000000 0.000000" a="90"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(12, false, false, false, false, 0, 5, "750.099976 633.500000 8695.940430", "-90 0 0"));
			// <group name="Land_Tower_TC4_Top" pos="978.074219 409.112732 10479.344727" rpy="-0.000000 0.000000 0.000000" a="90"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(13, false, false, false, false, 0, 6, "978.049988 406.299988 10481.099609", "180 0 0"));
			// <group name="Land_Tower_TC5" pos="7487.177734 233.291046 4711.526855" rpy="-0.000000 0.000000 -7.451208" a="97.4512"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(14, false, false, false, false, 0, 2, "7486.799805 237 4714.410156", "-7.999250 0 0"));
			// <group name="Land_Tower_TC5" pos="10336.049805 308.025360 3210.564453" rpy="-0.000000 0.000000 0.000000" a="90"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(15, false, false, false, false, 0, 5, "10336.099609 311.799988 3213.459961", "0 0 0"));
			// <group name="Land_Tower_TC5" pos="11247.409180 494.151489 8061.978027" rpy="-0.000000 0.000000 128.296692" a="-38.2967"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(16, false, false, false, false, 0, 4, "11250.299805 498 8061", "128 0 0"));
			// <group name="Land_Tower_TC6" pos="6824.490234 1139.825684 8756.519531" rpy="-0.000000 0.000000 -69.794823" a="159.795"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(17, false, false, false, false, 0, 2, "6824.500000 1142 8756.679688", "-161 0 0"));
			// <group name="Land_Tower_TC6" pos="1001.607178 326.739014 10536.270508" rpy="-0.000000 0.000000 0.000000" a="90"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(18, false, false, false, false, 0, 7, "1001.770020 329 10536.299805", "-90 0 0"));
			// <group name="Land_Tower_TC6" pos="6835.483398 1139.816406 8785.262695" rpy="-0.000000 0.000000 13.046253" a="76.9538"/>
			iat_PRTConfig.m_TowerConsoleData.Insert(new IAT_PoweredTowerConsoleData(19, false, false, false, false, 0, 5, "6835.649902 1142 8785.259766", "-78 0 0"));

			// write the file to "create it"
			if (!JsonFileLoader<ref IAT_PoweredRadioTowerConfig>.SaveFile(jsonConfig, iat_PRTConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		else
		{
			// file exists, just load it from disk
			if (!JsonFileLoader<ref IAT_PoweredRadioTowerConfig>.LoadFile(jsonConfig, iat_PRTConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		// return what we found
        return iat_PRTConfig;
	}

	void SaveConfig()
	{
		string errorMessage;
		// non serialized values are empty here because a loaded config isnt a 'new config'
		string rootFilePath = string.Format("%1\\%2\\%3", m_DayZFolder, m_RootConfigFolder, m_JsonFile);
		if (!JsonFileLoader<IAT_PoweredRadioTowerConfig>.SaveFile(rootFilePath, this, errorMessage))
			ErrorEx(errorMessage);
		PrintFormat("[IAT_PoweredRadioTowerConfig] Config Saved: %1", rootFilePath);
	}

	void UpdateConsole(int id, bool newPower, bool newRelay, bool newServer, bool newCpu, int newDial)
	{
		foreach(IAT_PoweredTowerConsoleData data : m_TowerConsoleData)
		{
			if (data.GetConsoleId() == id)
			{
				data.SetIsPoweredOn(newPower);
				data.SetIsRelayConnected(newRelay);
				data.SetIsServerConnected(newServer);
				data.SetIsCPUOn(newCpu);
				data.SetDialSetting(newDial);
				data.SetNumRestartsLeft(newDial);
				PrintFormat("Saving ID: %1 Power: %2 CPU: %3 Server: %4 Relay: %5 Dial: %6", data.GetConsoleId(), data.IsPoweredOn(), data.IsCPUOn(), data.IsServerConnected(), data.IsRelayConnected(), data.GetDialSetting());
				SaveConfig();
				// short circuit when value is found
				return;
			}
		}
	}

	// this is set up to require more terminals for more towers to be on.
	float GetRequiredTowerPower()
	{
		float normalized = GetNumRadioTowersPowerOn() / m_TowerConsoleData.Count();
		float k = 2.0; //curve steepness scale
		return Math.Pow(normalized, k);
	}
	// is the radio tower powered on
	int GetNumRadioTowersPowerOn()
	{
		int numActiveTowers = 0;
		foreach(IAT_PoweredTowerConsoleData data : m_TowerConsoleData)
		{
			if (data.IsPoweredOn())
			{
				numActiveTowers++;
			}
		}
		return numActiveTowers;
	}
	// is the relay connected (connected to ic radio)
	int GetNumRadioTowersRelayOn()
	{
		int numActiveTowers = 0;
		foreach(IAT_PoweredTowerConsoleData data : m_TowerConsoleData)
		{
			if (data.IsRelayConnected())
			{
				numActiveTowers++;
			}
		}
		return numActiveTowers;
	}
	// is the server connected (read messages for pda)
	int GetNumRadioTowersServerOn()
	{
		int numActiveTowers = 0;
		foreach(IAT_PoweredTowerConsoleData data : m_TowerConsoleData)
		{
			if (data.IsServerConnected())
			{
				numActiveTowers++;
			}
		}
		return numActiveTowers;
	}
	// is the cpu on (encryption/ciphered hacking)
	int GetNumRadioTowersCPUOn()
	{
		int numActiveTowers = 0;
		foreach(IAT_PoweredTowerConsoleData data : m_TowerConsoleData)
		{
			if (data.IsCPUOn())
			{
				numActiveTowers++;
			}
		}
		return numActiveTowers;
	}
	// ==================================================================================
	// GETTERS & SETTERS
	// ==================================================================================
	array<ref IAT_PoweredTowerConsoleData> GetTowerConsoleData()
	{
		return m_TowerConsoleData;
	}
	// ==================================================================================
	// Helpers
	// ==================================================================================
	void PrettyPrint()
	{
		Print("--[POWERED RADIO TOWER CONFIG BEGIN]");
		// PrintFormat("--m_RangeDefault: %1", GetDefaultRange());
		Print("--[END]");
	}
};