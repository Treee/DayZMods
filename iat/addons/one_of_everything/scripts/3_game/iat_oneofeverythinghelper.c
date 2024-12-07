class IAT_OneOfEverythingConfig
{
    protected vector m_StartingPoint;
    protected vector m_SpacingBetweenObjects;
    protected int m_NumberObjectsPerRow;
    protected bool m_DebugMode;

    void IAT_OneOfEverythingConfig(vector startingPoint, vector spacing, int numObjects, int debug)
    {
        m_StartingPoint = startingPoint;
        m_SpacingBetweenObjects = spacing;
        m_NumberObjectsPerRow = numObjects;
        m_DebugMode = debug;
    }
    vector GetStartingPosition()
    {
        return m_StartingPoint;
    }
    vector GetSpacingBetweenObjects()
    {
        return m_SpacingBetweenObjects;
    }
    int GetNumberOfObjectsPerRow()
    {
        return m_NumberObjectsPerRow;
    }
};

class IAT_OneOfEverythingHelper
{
    protected ref IAT_OneOfEverythingConfig iat_OOEConfig;

    protected string m_DayZFolder = "$profile:";
    protected string m_RootModFolder = "ItsATreeMods";
    protected string m_JsonFile = "OneOfEverythingConfig.json";
    protected string m_P3dTextFile = "AllP3ds.txt";

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
                iat_OOEConfig = new IAT_OneOfEverythingConfig("0 0 0", "1.5 0 0", 100, false);
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

        }
        return iat_OOEConfig;
    }

    bool LoadAllP3ds()
    {
        string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootModFolder);
        string p3dText = string.Format("%1\\%2", rootFilePath, m_P3dTextFile);

		FileHandle m_FileHandle = OpenFile(p3dText, FileMode.READ);
		if (m_FileHandle == 0) return false;

		string line_content = "";
		int char_count = FGets( m_FileHandle,  line_content );
		int line_index = 1;

        vector p3dPosition = iat_OOEConfig.GetStartingPosition();
        vector startingPointOffset = iat_OOEConfig.GetSpacingBetweenObjects();
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
                p3dPosition = iat_OOEConfig.GetStartingPosition();
                p3dPosition[2] = p3dPosition[2] + (rowNumber * 2);
                objectCounter = 0;
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
        PrintFormat("%1 has min: %2 max: %3", objectPath, min, max);
        // send out the new position offset by this objects size + some spacer distance

        position = position + "1.5 0 0";
        return position;
    }

};