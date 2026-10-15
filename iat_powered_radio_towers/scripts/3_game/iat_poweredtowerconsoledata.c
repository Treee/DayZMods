class IAT_PoweredTowerConsoleData
{
	protected int m_ConsoleId; // only used on server; this is the unique id of the console for json list for quick searching
	protected bool m_IsPoweredOn; // is the radio tower powered on
	protected bool m_IsCPUOn; // is the cpu on (encryption/cihpered hacking)
	protected bool m_IsServerConnected; // is the server connected (read messages for pda)
	protected bool m_IsRelayConnected; // is the relay connected (connected to ic radio)
	protected int m_DialSetting; // is the timer wound up (number of restarts left to be on automatically)
	protected vector m_ConsolePosition; // only used on server; sets the location for spawning
	protected vector m_ConsoleOrientation; // only used on server; sets the orientation for spawning
	protected int m_NumRestartsLeft; // only used on server to auto shut off radio

	void IAT_PoweredTowerConsoleData(int id, bool isOn, bool cpuOn, bool serverOn, bool relayOn, int dialState, int numRestarts, vector position, vector orientation)
	{
		m_ConsoleId = id;
		m_IsPoweredOn = isOn;
		m_IsCPUOn = cpuOn;
		m_IsServerConnected = serverOn;
		m_IsRelayConnected = relayOn;
		m_DialSetting = dialState;
		m_ConsolePosition = position;
		m_ConsoleOrientation = orientation;
		m_NumRestartsLeft = numRestarts;
	}
	// ========================================================== CUSTOM
	bool IsCorrectTower(int id)
	{
		return GetConsoleId() == id;
	}
	bool HasRestartToken()
	{
		return m_NumRestartsLeft > 0;
	}
	void ConsumeRestartToken()
	{
		if (m_NumRestartsLeft > 0)
			m_NumRestartsLeft--;
	}

	// ========================================================== HELPERS
	bool IsPoweredOn()
	{
		return m_IsPoweredOn;
	}
	void SetIsPoweredOn(bool newPowerState)
	{
		m_IsPoweredOn = newPowerState;
	}
	bool IsCPUOn()
	{
		return m_IsCPUOn;
	}
	void SetIsCPUOn(bool newCPUState)
	{
		m_IsCPUOn = newCPUState;
	}
	bool IsServerConnected()
	{
		return m_IsServerConnected;
	}
	void SetIsServerConnected(bool newServerState)
	{
		m_IsServerConnected = newServerState;
	}
	bool IsRelayConnected()
	{
		return m_IsRelayConnected;
	}
	void SetIsRelayConnected(bool newRelayState)
	{
		m_IsRelayConnected = newRelayState;
	}
	int GetDialSetting()
	{
		return m_DialSetting;
	}
	void SetDialSetting(int newDialSetting)
	{
		m_DialSetting = newDialSetting;
	}
	int GetConsoleId()
	{
		return m_ConsoleId;
	}
	void SetConsoleId(int newId)
	{
		m_ConsoleId = newId;
	}
	int GetNumRestarts()
	{
		return m_NumRestartsLeft;
	}
	void SetNumRestartsLeft(int numRestarts)
	{
		m_NumRestartsLeft = numRestarts;
	}

	// no setters because we dont want to expose that behavior
	vector GetConsolePosition()
	{
		return m_ConsolePosition;
	}
	vector GetConsoleOrientation()
	{
		return m_ConsoleOrientation;
	}
};