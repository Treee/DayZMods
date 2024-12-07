class IAT_OneOfEverythingConfig
{
    protected vector m_StartingPoint;
    protected int m_NumberObjectsPerRow;
    protected bool m_DebugMode;
    protected bool m_Enabled;

    void IAT_OneOfEverythingConfig(vector startingPoint, int numObjects, int debugMode, int enabled)
    {
        m_StartingPoint = startingPoint;
        m_NumberObjectsPerRow = numObjects;
        m_DebugMode = debugMode;
        m_Enabled = enabled;
    }
    vector GetStartingPosition()
    {
        return m_StartingPoint;
    }
    int GetNumberOfObjectsPerRow()
    {
        return m_NumberObjectsPerRow;
    }
    bool GetDebugMode()
    {
        return m_DebugMode;
    }
    bool GetIsEnabled()
    {
        return m_Enabled;
    }
};

class IAT_OneOfEverythingHelper
{
    protected ref IAT_OneOfEverythingConfig iat_OOEConfig;

    protected string m_DayZFolder = "$profile:";
    protected string m_RootModFolder = "ItsATreeMods";
    protected string m_JsonFile = "OneOfEverythingConfig.json";
    protected string m_P3dTextFile = "AllP3ds.txt";

	protected vector m_ObjectRowPadding = "0 0 0";
	protected vector m_LastRowStartingPosition = "0 0 0";

    protected bool m_IsDebugMode = false;
    protected bool m_IsEnabled = false;

    IAT_OneOfEverythingConfig GetOneOfEverythingConfig()
    {
        // if the config does not exist (we probably just loaded the server)
        if (!iat_OOEConfig)
        {
            string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootModFolder);
            // if the folder doesnt exist (we probably just loaded this for the first time)
            if (!FileExist(rootFilePath))
            {
                MakeDirectory(rootFilePath);
            }
            string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
            // if the actual config file doesnt exist
            if (!FileExist(jsonConfig))
            {
                iat_OOEConfig = new IAT_OneOfEverythingConfig("4000 500 4000", 100, false, false);
                JsonFileLoader<ref IAT_OneOfEverythingConfig>.JsonSaveFile(jsonConfig, iat_OOEConfig);
            }
            else
            {
                JsonFileLoader<ref IAT_OneOfEverythingConfig>.JsonLoadFile(jsonConfig, iat_OOEConfig);
            }

            string p3dText = string.Format("%1\\%2", rootFilePath, m_P3dTextFile);
            // if the actual config file doesnt exist
            if (!FileExist(p3dText))
            {
                FileHandle logFile = OpenFile(p3dText, FileMode.WRITE);
                FPrintln(logFile, "dz/plants_bliss/tree/t_populusnigra_3sb_summer.p3d");
                FPrintln(logFile, "rootFolder/path/to/someObject.p3d");
                CloseFile(logFile);
            }
            m_IsDebugMode = iat_OOEConfig.GetDebugMode();
            m_IsEnabled = iat_OOEConfig.GetIsEnabled();
        }
        return iat_OOEConfig;
    }

    bool LoadAllP3ds()
    {
        if (!m_IsEnabled)
            return true;

        string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootModFolder);
        string p3dText = string.Format("%1\\%2", rootFilePath, m_P3dTextFile);

		FileHandle m_FileHandle = OpenFile(p3dText, FileMode.READ);
		if (m_FileHandle == 0) return false;

		string line_content = "";
		int char_count = FGets( m_FileHandle,  line_content );
		int line_index = 1;

        vector p3dPosition = iat_OOEConfig.GetStartingPosition();
		m_LastRowStartingPosition = p3dPosition;
        int totalObjectsPerRowMax = iat_OOEConfig.GetNumberOfObjectsPerRow();
        int objectCounter = 1;
        int rowNumber = 0;
		while ( char_count != -1 )
		{
			// m_RawLines.Insert(new LineElement(line_content,line_index));
            if (objectCounter > totalObjectsPerRowMax)
            {
                rowNumber++;
                // move starting point back like a typewritter
                p3dPosition = m_LastRowStartingPosition;
				// add largest padding from the row of objects
                p3dPosition[0] = p3dPosition[0] + (m_ObjectRowPadding[0] * 2);
				// set last row to this rows starting point
				m_LastRowStartingPosition = p3dPosition;
                objectCounter = 0;
				m_ObjectRowPadding = "0 0 0";
            }
            p3dPosition = SpawnSingleObject(p3dPosition, line_content);
			char_count = FGets( m_FileHandle,  line_content );
			line_index++;
            objectCounter++;
		}

		CloseFile(m_FileHandle);
		return true;
    }

    vector SpawnSingleObject(vector position, string objectPath)
    {
        if (!GetGame())
        {
            Print("DayZ Game Not Initialized Yet");
            return "0 0 0";
        }
        Object singleObject = GetGame().CreateStaticObjectUsingP3D(objectPath, position, "0 0 0");

        if (!singleObject)
        {
            Print("Unable to create static object: " + objectPath);
            return "0 0 0";
        }

        vector minMax[2];
        vector min, max;
        if (singleObject.GetCollisionBox(minMax))
        {
            min = minMax[0];
            max = minMax[1];
        }
        else
        {
            // use default min/max values
            min = "0 0 0";
            max = "1 1 1";
        }
		float maxX = Math.Max(Math.AbsFloat(min[0]), Math.AbsFloat(max[0]));
		float maxY = Math.Max(Math.AbsFloat(min[1]), Math.AbsFloat(max[1]));
		float maxZ = Math.Max(Math.AbsFloat(min[2]), Math.AbsFloat(max[2])); // magic number to give some slack between objects
		string absoluteBuffer = string.Format("%1 %2 %3", maxX, maxY, maxZ);
		UpdateObjectRowPadding(absoluteBuffer.ToVector());

        if (m_IsDebugMode)
       	    PrintFormat("%1 has min: %2 max: %3 with absoluteBuffer of: %4", objectPath, min, max, absoluteBuffer);

        // send out the new position offset by this objects size + some spacer distance
        maxZ = Math.Max(6, maxZ * 2);
		string itembuffer = string.Format("%1 %2 %3", 0, 0, maxZ);
        position = position + itembuffer.ToVector();
        return position;
    }

	void UpdateObjectRowPadding(vector newBoundaries)
	{
		// check if x or z is bigger. ignore y because it is irrelevant for this
		if (m_ObjectRowPadding[0] < newBoundaries[0])
		{
			m_ObjectRowPadding[0] = newBoundaries[0];
		}
		if (m_ObjectRowPadding[2] < newBoundaries[2])
		{
			m_ObjectRowPadding[2] = newBoundaries[2];
		}
	}

};