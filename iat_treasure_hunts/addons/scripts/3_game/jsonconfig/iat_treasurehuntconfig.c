class IAT_TreasureHuntConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "TreasureHuntConfig.json";

	protected bool m_IsEnabled;
	protected ref array<ref IAT_TreasureHuntTier> m_TreasureTiers;
	protected ref array<ref IAT_TreasureHuntLocation> m_TreasureLocations; // the raid tools that can be used on codelocks

	IAT_TreasureHuntConfig TryGetTreasureHuntConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			MakeDirectory(rootFilePath);
		}

		string errorMessage;
		IAT_TreasureHuntConfig iat_THConfig;
		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			// new config object
			iat_THConfig = new IAT_TreasureHuntConfig();
			// set some default values
			iat_THConfig.m_IsEnabled = true;
			iat_THConfig.m_TreasureTiers = new array<ref IAT_TreasureHuntTier>();
			IAT_TreasureHuntTier treasureTier0 = new IAT_TreasureHuntTier(0, 1, 3, 0.0, "TreasureHunt_Tier0");
			treasureTier0.IAT_InsertNewContainerOption("LeatherSack_Natural");
			treasureTier0.IAT_InsertNewContainerOption("LeatherSack_Black");
			treasureTier0.IAT_InsertNewContainerOption("LeatherSack_Beige");
			treasureTier0.IAT_InsertNewContainerOption("LeatherSack_Brown");
			treasureTier0.IAT_InsertNewContainerOption("DrysackBag_Green");
			treasureTier0.IAT_InsertNewContainerOption("DrysackBag_Orange");
			treasureTier0.IAT_InsertNewContainerOption("DrysackBag_Yellow");
			iat_THConfig.m_TreasureTiers.Insert(treasureTier0);

			IAT_TreasureHuntTier treasureTier1 = new IAT_TreasureHuntTier(1, 2, 4, 0.1, "TreasureHunt_Tier1");
			treasureTier1.IAT_InsertNewContainerOption("WoodenCrate");
			treasureTier1.IAT_InsertNewContainerOption("SmallProtectorCase");
			iat_THConfig.m_TreasureTiers.Insert(treasureTier1);

			IAT_TreasureHuntTier treasureTier2 = new IAT_TreasureHuntTier(2, 3, 5, 0.25, "TreasureHunt_Tier2");
			treasureTier2.IAT_InsertNewContainerOption("SeaChest");
			treasureTier2.IAT_InsertNewContainerOption("AmmoBox");
			iat_THConfig.m_TreasureTiers.Insert(treasureTier2);

			iat_THConfig.m_TreasureLocations = new array<ref IAT_TreasureHuntLocation>();
			// iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Beginner Area", "B5 Location", true, 0, "", "", ""));
			// Beginner
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Jasper", "Jasper1 Location", true, 0, "6520.50 1 343.50", "6502.50 1 81.00", "5443.50 1 345.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Jasper", "Jasper2 Location", true, 0, "6400.50 1 61.50", "5262.00 1 340.50", "5263.50 1 36.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Jasper", "Jasper3 Location", true, 0, "5320.50 1 652.50", "6193.50 1 603.00", "5665.50 1 1234.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Jasper", "Jasper4 Location", true, 0, "6288.00 1 685.50", "5997.00 1 1212.00", "6612.00 1 1215.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Milton", "Milton1 Location", true, 0, "5178.00 1 60.00", "5184.00 1 339.00", "3361.50 1 558.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Milton", "Milton2 Location", true, 0, "4858.50 1 100.50", "2968.50 1 550.50", "2968.50 1 85.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Milton", "Milton3 Location", true, 0, "2749.50 1 985.50", "3303.00 1 868.50", "3480.00 1 1467.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Milton", "Milton4 Location", true, 0, "3492.00 1 868.50", "4056.00 1 1300.50", "4110.00 1 666.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Milton", "Milton5 Location", true, 0, "4357.50 1 711.00", "4375.50 1 1242.00", "5112.00 1 552.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Fishville", "Fishville1 Location", true, 0, "2809.50 1 523.50", "2904.00 1 97.50", "1809.00 1 114.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Fishville", "Fishville2 Location", true, 0, "1335.00 1 381.00", "1794.00 1 184.50", "2650.50 1 568.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Fishville", "Fishville3 Location", true, 0, "1123.50 1 441.00", "1734.00 1 130.50", "1024.50 1 169.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Fishville", "Fishville4 Location", true, 0, "541.50 1 456.00", "1000.50 1 502.50", "909.00 1 130.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Fishville", "Fishville5 Location", true, 0, "2064.00 1 1431.00", "2574.00 1 2077.50", "3034.50 1 1636.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Fishville", "Fishville6 Location", true, 0, "2255.25 1 1378.50", "2626.50 1 1044.00", "3270.00 1 1546.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Broken Arrow", "BA1 Location", true, 0, "411.00 1 1029.00", "232.50 1 1435.50", "715.50 1 1168.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Broken Arrow", "BA2 Location", true, 0, "328.50 1 1479.00", "583.50 1 1335.00", "1017.00 1 1624.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Broken Arrow", "BA3 Location", true, 0, "411.00 1 1564.50", "969.00 1 1674.00", "919.50 1 2155.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Broken Arrow", "BA4 Location", true, 0, "286.50 1 1500.00", "120.00 1 2172.00", "999.00 1 2310.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Broken Arrow", "BA5 Location", true, 0, "1584.00 1 2166.00", "2070.00 1 1729.50", "2461.50 1 2151.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Broken Arrow", "BA6 Location", true, 0, "2412.00 1 2314.50", "1578.00 1 2284.50", "2349.00 1 2808.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Glasgow AFB", "Glasgow1 Location", true, 0, "1602.00 1 3480.00", "948.00 1 3525.00", "1254.00 1 2073.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Glasgow AFB", "Glasgow2 Location", true, 0, "922.50 1 2610.00", "285.00 1 2812.50", "757.50 1 3496.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Glasgow AFB", "Glasgow3 Location", true, 0, "681.00 1 3543.00", "196.50 1 2860.50", "306.00 1 4924.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Glasgow AFB", "Glasgow4 Location", true, 0, "1641.00 1 3499.50", "804.00 1 4464.00", "2238.00 1 4348.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Glasgow AFB", "Glasgow5 Location", true, 0, "1605.00 1 2559.00", "2253.00 1 2886.00", "1854.00 1 3324.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Baylor", "Baylor1 Location", true, 0, "2430.00 1 2896.50", "2002.50 1 3462.00", "2476.50 1 3673.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Baylor", "Baylor2 Location", true, 0, "1927.50 1 3639.00", "2776.50 1 4185.00", "2415.00 1 4410.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Baylor", "Baylor3 Location", true, 0, "2650.50 1 3910.50", "2845.50 1 3400.50", "3345.00 1 4164.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Baylor", "Baylor4 Location", true, 0, "2494.50 1 4485.00", "2812.50 1 4273.50", "2874.00 1 4912.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Baylor", "Baylor5 Location", true, 0, "2932.50 1 4936.50", "3373.50 1 5016.00", "2905.50 1 4399.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Baylor", "Baylor6 Location", true, 0, "2949.00 1 4372.50", "3457.50 1 4329.00", "3502.50 1 5053.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Niceville", "Niceville1 Location", true, 0, "3195.00 1 3321.00", "3513.00 1 4152.00", "3897.00 1 3433.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Niceville", "Niceville2 Location", true, 0, "3564.00 1 4371.00", "4189.50 1 4288.50", "3682.50 1 5031.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Niceville", "Niceville3 Location", true, 0, "3714.00 1 5154.00", "4434.00 1 5056.50", "4281.00 1 4282.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Wood Pines", "WP Location", true, 0, "4113.00 1 4023.00", "3831.00 1 3753.00", "4507.50 1 3552.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Camp Telluride", "CT Location", true, 0, "3675.00 1 2623.50", "4207.50 1 2679.00", "3751.50 1 2119.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Camp Telluride", "CT1 Location", true, 0, "3223.50 1 2047.50", "2535.00 1 2320.50", "3010.50 1 2707.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Camp Telluride", "CT2 Location", true, 0, "4588.50 1 2683.50", "5217.00 1 2422.50", "4384.50 1 1909.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Camp Telluride", "CT3 Location", true, 0, "4762.50 1 3330.00", "4519.50 1 2860.50", "5302.50 1 2536.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Colter City", "CC1 Location", true, 0, "4503.00 1 4954.50", "5085.00 1 4408.50", "4359.00 1 4084.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Colter City", "CC2 Location", true, 0, "5074.50 1 4084.50", "5911.50 1 3274.50", "4677.00 1 3481.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Colter City", "CC3 Location", true, 0, "5821.50 1 4186.50", "5377.50 1 4068.00", "5881.50 1 3517.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Red Lodge", "RL1 Location", true, 0, "5940.00 1 3492.00", "6487.50 1 3640.50", "6589.50 1 3286.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Red Lodge", "RL2 Location", true, 0, "6523.50 1 3612.00", "7195.50 1 3469.50", "7032.00 1 2775.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Red Lodge", "RL3 Location", true, 0, "6675.00 1 3253.50", "6385.50 1 2964.00", "6976.50 1 2755.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Red Lodge", "RL4 Location", true, 0, "5083.50 1 3145.50", "5950.50 1 3177.00", "5427.00 1 2601.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Red Lodge", "RL5 Location", true, 0, "5571.00 1 2610.00", "6075.00 1 3066.00", "6444.00 1 2556.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Junction", "Junction1 Location", true, 0, "6715.50 1 2815.50", "7579.50 1 2259.00", "6885.00 1 2065.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Junction", "Junction2 Location", true, 0, "6388.50 1 2437.50", "5568.00 1 2440.50", "5796.00 1 1998.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Junction", "Junction3 Location", true, 0, "6025.50 1 1963.50", "6526.50 1 2304.00", "6634.50 1 1824.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Junction", "Junction4 Location", true, 0, "6580.50 1 1303.50", "5646.00 1 1321.50", "5940.00 1 1888.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Junction", "Junction5 Location", true, 0, "6910.50 1 1108.50", "6475.50 1 1803.00", "6943.50 1 1641.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Junction", "Junction6 Location", true, 0, "7900.50 1 1656.00", "7092.00 1 1150.50", "7222.50 1 2026.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Junction", "Junction7 Location", true, 0, "7239.00 1 2074.50", "7989.00 1 1666.50", "8118.00 1 2170.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Ouray", "Ouray1 Location", true, 0, "6598.50 1 313.50", "7182.00 1 118.50", "7177.50 1 493.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Ouray", "Ouray2 Location", true, 0, "7095.00 1 1078.50", "7083.00 1 724.50", "7447.50 1 1273.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Ouray", "Ouray3 Location", true, 0, "7381.50 1 546.00", "7509.00 1 1125.00", "8136.00 1 1099.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Ouray", "Ouray4 Location", true, 0, "7408.50 1 114.00", "8034.00 1 526.50", "8451.00 1 135.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Ouray", "Ouray5 Location", true, 0, "8490.00 1 238.50", "8097.00 1 612.00", "8488.50 1 1080.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("International Airport", "IA1 Location", true, 0, "7759.50 1 1378.50", "8445.00 1 1911.00", "8761.50 1 1546.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("International Airport", "IA2 Location", true, 0, "8563.50 1 981.00", "8640.00 1 237.00", "9228.00 1 1180.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Coleman", "Coleman1 Location", true, 0, "9342.00 1 2052.00", "8988.00 1 1905.00", "9771.00 1 1422.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Coleman", "Coleman2 Location", true, 0, "8892.00 1 276.00", "9304.50 1 1068.00", "9843.00 1 267.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Coleman", "Coleman3 Location", true, 0, "9792.00 1 955.50", "9862.50 1 309.00", "10336.50 1 321.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Tyler", "Tyler1 Location", true, 0, "10624.50 1 291.00", "10215.00 1 720.00", "11104.50 1 895.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Tyler", "Tyler2 Location", true, 0, "10884.00 1 328.50", "11680.50 1 645.00", "11157.00 1 856.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Tyler", "Tyler3 Location", true, 0, "12042.00 1 1531.50", "11410.50 1 1105.50", "11812.50 1 720.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Tyler", "Tyler4 Location", true, 0, "11730.00 1 1647.00", "11070.00 1 1452.00", "10897.50 1 1926.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Tyler", "Tyler5 Location", true, 0, "10486.50 1 1468.50", "10275.00 1 1647.00", "10572.00 1 2083.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Tyler", "Tyler6 Location", true, 0, "10053.00 1 1645.50", "9985.50 1 1327.50", "10398.00 1 1348.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Troy", "Troy1 Location", true, 0, "10947.00 1 2097.00", "10576.50 1 1843.50", "10243.50 1 2295.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Troy", "Troy2 Location", true, 0, "11634.00 1 1788.00", "10851.00 1 2284.50", "11689.50 1 2565.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Blairsville", "Blairsville1 Location", true, 0, "9955.50 1 1923.00", "9669.75 1 2151.75", "10212.00 1 2328.75"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Blairsville", "Blairsville2 Location", true, 0, "9627.75 1 2250.75", "9180.75 1 2626.50", "9186.75 1 3167.25"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Sefner", "B5 Location", true, 0, "10084.50 1 2868.00", "10585.50 1 2498.25", "9824.25 1 2275.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Camp WannaStay", "CWS Location", true, 0, "11825.25 1 2765.25", "11079.00 1 2499.75", "11103.00 1 3108.75"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Eagle Mountain", "EM1 Location", true, 0, "11892.00 1 3046.50", "11038.50 1 3220.50", "11898.00 1 3747.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Eagle Mountain", "EM2 Location", true, 0, "11223.00 1 4102.50", "10467.00 1 3966.00", "11082.00 1 3346.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Eagle Mountain", "EM3 Location", true, 0, "11883.00 1 4441.50", "11440.50 1 4072.50", "12063.00 1 3790.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Darby", "Darby Location", true, 0, "9454.50 1 2968.50", "8977.50 1 3774.00", "9951.00 1 3886.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Juno", "Juno1 Location", true, 0, "8347.50 1 2619.75", "9039.75 1 2744.25", "9260.25 1 2200.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Juno", "Juno2 Location", true, 0, "7614.00 1 3105.00", "7353.00 1 2607.00", "8070.00 1 2623.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Juno", "Juno3 Location", true, 0, "8262.00 1 3463.50", "7695.00 1 3381.00", "8202.00 1 2865.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Juno", "Juno4 Location", true, 0, "8842.50 1 3123.00", "8416.50 1 3360.00", "8496.00 1 4122.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Beckham Heights", "BH1 Location", true, 0, "10678.50 1 5544.00", "11131.50 1 4252.50", "9177.00 1 4501.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Beckham Heights", "BH2 Location", true, 0, "11350.50 1 5446.50", "12208.50 1 5403.00", "11572.50 1 4279.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Rolling Hills", "RH1 Location", true, 0, "8538.00 1 4936.50", "9093.00 1 4551.00", "9285.00 1 5287.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Rolling Hills", "RH2 Location", true, 0, "9409.50 1 5443.50", "8919.00 1 5715.00", "8488.50 1 5004.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Rolling Hills", "RH3 Location", true, 0, "9499.50 1 6795.00", "8722.50 1 6166.50", "9153.00 1 5694.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Rolling Hills", "RH4 Location", true, 0, "10501.50 1 6523.50", "9585.00 1 6459.00", "10065.00 1 6022.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Long John Campgrounds", "LJC1 Location", true, 0, "10777.50 1 6411.00", "10746.00 1 5710.50", "9859.50 1 5592.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Long John Campgrounds", "LJC2 Location", true, 0, "11857.50 1 6508.50", "12112.50 1 5617.50", "11230.50 1 5619.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Long John Campgrounds", "LJC3 Location", true, 0, "11013.00 1 6696.00", "11901.00 1 6664.50", "11077.50 1 6060.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Riggins", "Riggins1 Location", true, 0, "10216.50 1 7396.50", "10570.50 1 6561.00", "9612.00 1 6570.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Riggins", "Riggins2 Location", true, 0, "11371.50 1 7497.00", "11887.50 1 6981.00", "10783.50 1 7201.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Fairfax", "Fairfax1 Location", true, 0, "7534.50 1 3411.00", "7633.50 1 3937.50", "8247.00 1 3685.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Fairfax", "Fairfax2 Location", true, 0, "8343.00 1 4660.50", "8464.50 1 4186.50", "7978.50 1 4543.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Industrial Park", "IP1 Location", true, 0, "6196.50 1 4251.00", "6420.00 1 4342.50", "6505.50 1 3961.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Industrial Park", "IP2 Location", true, 0, "6958.50 1 3928.50", "6625.50 1 4197.00", "7513.50 1 4474.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Industrial Park", "IP3 Location", true, 0, "6811.50 1 4317.00", "7453.50 1 4515.00", "6954.00 1 4963.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Industrial Park", "IP4 Location", true, 0, "6825.00 1 5043.00", "6231.00 1 4806.00", "6471.00 1 4465.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Lakeland", "Lakeland1 Location", true, 0, "7474.50 1 5437.50", "8010.00 1 5140.50", "7753.50 1 4650.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Lakeland", "Lakeland2 Location", true, 0, "7480.50 1 4582.50", "6954.00 1 5046.00", "7432.50 1 5445.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Lakeland", "Lakeland3 Location", true, 0, "7350.00 1 5883.00", "8338.50 1 6252.00", "8292.00 1 5817.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Lakeland", "Lakeland4 Location", true, 0, "8076.00 1 6432.00", "8919.00 1 6990.00", "7701.00 1 7329.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bennett", "Bennett1 Location", true, 0, "6748.50 1 5921.25", "7266.00 1 5524.50", "6693.75 1 5122.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bennett", "Bennett2 Location", true, 0, "6655.50 1 5911.50", "6133.50 1 5938.50", "6193.50 1 5263.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Silver Springs", "SP1 Location", true, 0, "6046.50 1 5962.50", "5712.00 1 5551.50", "6135.00 1 5218.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Silver Springs", "SP2 Location", true, 0, "5472.00 1 4864.50", "5874.00 1 4641.00", "5293.50 1 4455.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Aurora", "Aurora1 Location", true, 0, "5238.00 1 5089.50", "5316.00 1 4587.00", "5007.00 1 4813.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Aurora", "Aurora2 Location", true, 0, "4480.50 1 5148.00", "4926.00 1 4843.50", "4810.50 1 5295.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Ruby Ridge", "RR1 Location", true, 0, "1279.50 1 4467.00", "780.00 1 4686.00", "1311.00 1 5037.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Ruby Ridge", "RR2 Location", true, 0, "1600.50 1 5035.50", "1363.50 1 5091.00", "1329.00 1 4467.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Ruby Ridge", "RR3 Location", true, 0, "565.50 1 5884.50", "372.00 1 5455.50", "891.00 1 5496.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Ruby Ridge", "RR4 Location", true, 0, "1654.50 1 5397.00", "1204.50 1 5304.00", "1299.00 1 5994.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Ruby Ridge", "RR5 Location", true, 0, "1968.00 1 6237.00", "1672.50 1 5839.50", "2482.50 1 5826.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Ruby Ridge", "RR6 Location", true, 0, "976.50 1 5988.00", "739.50 1 6597.00", "174.00 1 6324.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Ruby Ridge", "RR7 Location", true, 0, "1591.50 1 6298.50", "1074.00 1 5977.50", "1057.50 1 6615.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Faiths Gate Compound", "FGC1 Location", true, 0, "2445.00 1 5605.50", "2974.50 1 5202.00", "2086.50 1 4444.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Faiths Gate Compound", "FGC2 Location", true, 0, "2904.00 1 5476.50", "3169.50 1 5241.00", "3415.50 1 5610.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Faiths Gate Compound", "FGC3 Location", true, 0, "3265.50 1 5233.50", "3816.00 1 5404.50", "3664.50 1 5808.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Faiths Gate Compound", "FGC4 Location", true, 0, "3390.00 1 6823.50", "4276.50 1 6030.00", "3760.50 1 5755.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Faiths Gate Compound", "FGC5 Location", true, 0, "3463.50 1 5920.50", "2469.00 1 6222.00", "3292.50 1 6744.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Checkpoint West", "CW1 Location", true, 0, "945.00 1 7401.00", "426.00 1 7233.00", "909.00 1 6874.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Checkpoint West", "CW2 Location", true, 0, "973.50 1 7474.50", "1492.50 1 7564.50", "1609.50 1 6925.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Checkpoint West", "CW3 Location", true, 0, "231.00 1 7756.50", "1125.00 1 7800.00", "313.50 1 9033.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Checkpoint West", "CW4 Location", true, 0, "1251.00 1 8779.50", "739.50 1 8523.00", "1338.00 1 7714.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Jackson Falls", "JF1 Location", true, 0, "2097.00 1 8263.50", "3192.00 1 8490.00", "2865.00 1 7974.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Jackson Falls", "JF2 Location", true, 0, "1990.50 1 8152.50", "1648.50 1 7807.50", "2281.50 1 7552.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Jackson Falls", "JF3 Location", true, 0, "1908.00 1 6672.00", "2781.00 1 6745.50", "1843.50 1 7099.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Jackson Falls", "JF4 Location", true, 0, "3628.50 1 8535.00", "3540.00 1 8203.50", "3862.50 1 7900.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Jackson Falls", "JF5 Location", true, 0, "3733.50 1 8497.50", "4188.00 1 8361.00", "3888.00 1 7930.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bitterroot Country Club", "BCC1 Location", true, 0, "7057.50 1 6066.00", "7977.00 1 6304.50", "6345.00 1 7117.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bitterroot Country Club", "BCC2 Location", true, 0, "5567.25 1 6105.00", "5796.75 1 5813.25", "6137.25 1 6481.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bitterroot Country Club", "BCC3 Location", true, 0, "5375.25 1 7083.75", "5883.75 1 6795.75", "5554.50 1 6243.75"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Centerville", "Centerville1 Location", true, 0, "4377.00 1 6918.00", "3576.00 1 6817.50", "4587.00 1 6015.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Centerville", "Centerville2 Location", true, 0, "5103.00 1 6501.00", "5052.00 1 6798.00", "4413.00 1 6790.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Kraft Lake", "Kraft Lake1 Location", true, 0, "5701.50 1 7281.00", "5161.50 1 7216.50", "5992.50 1 6769.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Kraft Lake", "Kraft Lake2 Location", true, 0, "7588.50 1 7321.50", "7918.50 1 6457.50", "6471.00 1 7255.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Kraft Lake", "Kraft Lake3 Location", true, 0, "7114.50 1 7321.50", "5566.50 1 7728.00", "5790.00 1 8292.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Fort Hale", "FH1 Location", true, 0, "4593.00 1 7149.00", "4938.00 1 7168.50", "4776.00 1 6852.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Fort Hale", "FH2 Location", true, 0, "4360.50 1 7464.00", "4321.50 1 7017.00", "4594.50 1 7041.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Fort Hale", "FH3 Location", true, 0, "4072.50 1 7678.50", "4405.50 1 7684.50", "4228.50 1 7327.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Fort Hale", "FH4 Location", true, 0, "5394.00 1 8025.00", "5170.50 1 7371.00", "5706.00 1 7371.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Fort Hale", "FH5 Location", true, 0, "4075.50 1 8083.50", "4432.50 1 8308.50", "4558.50 1 7899.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Fort Hale", "FH6 Location", true, 0, "5253.00 1 8124.00", "5821.50 1 8473.50", "4893.00 1 9324.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Becker", "Becker1 Location", true, 0, "1953.00 1 8194.50", "1644.00 1 8089.50", "1468.50 1 8620.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Becker", "Becker2 Location", true, 0, "2065.50 1 8577.00", "2278.50 1 8917.50", "1746.00 1 9175.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Becker", "Becker3 Location", true, 0, "2094.00 1 8583.00", "2550.00 1 8632.50", "2494.50 1 9208.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Moreno Valley", "MV1 Location", true, 0, "408.00 1 9892.50", "985.50 1 8997.00", "340.50 1 9130.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Moreno Valley", "MV2 Location", true, 0, "96.00 1 10428.00", "877.50 1 10365.00", "859.50 1 9309.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Moreno Valley", "MV3 Location", true, 0, "1125.00 1 9783.00", "1500.00 1 9913.50", "1239.00 1 9210.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bagdad", "Bagdad1 Location", true, 0, "1561.50 1 9913.50", "2281.50 1 9421.50", "1594.50 1 9369.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bagdad", "Bagdad2 Location", true, 0, "1816.50 1 10224.00", "2167.50 1 10528.50", "2170.50 1 9685.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bagdad", "Bagdad3 Location", true, 0, "2299.50 1 9573.00", "2376.00 1 10533.00", "3199.50 1 9010.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Falcon Rock", "FR1 Location", true, 0, "1128.00 1 10480.50", "1104.00 1 9928.50", "1641.00 1 10152.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Falcon Rock", "FR2 Location", true, 0, "1588.50 1 10993.50", "2161.50 1 10647.00", "1698.00 1 10240.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Falcon Rock", "FR3 Location", true, 0, "679.50 1 10546.50", "417.00 1 11170.50", "42.00 1 11077.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Falcon Rock", "FR4 Location", true, 0, "823.50 1 10651.50", "586.50 1 11016.00", "1059.00 1 10974.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Falcon Rock", "FR5 Location", true, 0, "1146.00 1 11286.00", "1473.00 1 10924.50", "1156.50 1 10843.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Falcon Rock", "FR6 Location", true, 0, "618.00 1 11304.00", "903.00 1 11070.00", "1086.00 1 11371.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Falcon Rock", "FR7 Location", true, 0, "1510.50 1 11094.00", "1147.50 1 11479.50", "1572.00 1 11518.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Dixie Town", "DT1 Location", true, 0, "1659.00 1 11866.50", "2161.50 1 11698.50", "2328.00 1 10885.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Dixie Town", "DT2 Location", true, 0, "2652.00 1 11377.50", "2274.00 1 11797.50", "2311.50 1 12216.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Dixie Town", "DT3 Location", true, 0, "2469.00 1 12147.00", "3241.50 1 12097.50", "2712.00 1 11473.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Denton Ranch", "Denton1 Location", true, 0, "2416.50 1 11263.50", "2394.00 1 10563.00", "3097.50 1 10612.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Denton Ranch", "Denton2 Location", true, 0, "2980.50 1 11059.50", "3144.00 1 11640.00", "3312.00 1 10578.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Buford", "Buford1 Location", true, 0, "2986.50 1 9714.00", "3457.50 1 8953.50", "3882.00 1 9556.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Buford", "Buford2 Location", true, 0, "3784.50 1 9706.50", "3076.50 1 9832.50", "3123.00 1 10519.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Buford", "Buford3 Location", true, 0, "3888.00 1 10720.50", "3417.00 1 10540.50", "3865.50 1 10087.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Johns Pass Campgrounds", "JPC1 Location", true, 0, "4347.00 1 8823.00", "4141.50 1 8434.50", "3529.50 1 8829.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Johns Pass Campgrounds", "JPC2 Location", true, 0, "3885.00 1 8838.00", "4351.50 1 8914.50", "4075.50 1 9508.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Johns Pass Campgrounds", "JPC3 Location", true, 0, "5577.00 1 8829.00", "4693.50 1 9583.50", "4846.50 1 10353.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bitterroot Ski Resort", "BSR1 Location", true, 0, "3220.50 1 11695.50", "3346.50 1 10608.00", "4012.50 1 10797.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bitterroot Ski Resort", "BSR2 Location", true, 0, "4153.50 1 11385.00", "4863.00 1 11586.00", "4933.50 1 10890.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Hamilton", "Hamilton Location", true, 0, "3826.50 1 12094.50", "3252.00 1 11752.50", "3925.50 1 11044.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Black Rock Barracks", "BRB1 Location", true, 0, "5503.50 1 11109.00", "4941.00 1 10939.50", "4954.50 1 11371.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Black Rock Barracks", "BRB2 Location", true, 0, "4965.00 1 11491.50", "5452.50 1 11793.00", "5602.50 1 11124.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Black Rock Barracks", "BRB3 Location", true, 0, "5626.50 1 11565.00", "5742.00 1 11136.00", "6649.50 1 11725.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Colins", "Colins Location", true, 0, "6457.50 1 11238.00", "6756.00 1 11863.50", "6136.50 1 12219.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("McClain Ranch", "MCR1 Location", true, 0, "7014.00 1 11385.00", "7156.50 1 12198.00", "7875.00 1 11535.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("McClain Ranch", "MCR2 Location", true, 0, "8268.00 1 11817.00", "9172.50 1 11902.50", "9399.00 1 11061.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("March Air Force Base", "MAFB1 Location", true, 0, "9376.50 1 11793.00", "10114.50 1 11716.50", "9486.00 1 10881.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("March Air Force Base", "MAFB2 Location", true, 0, "10239.00 1 11664.00", "9534.00 1 10531.50", "10681.50 1 11040.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("March Air Force Base", "MAFB3 Location", true, 0, "10441.50 1 11818.50", "10534.50 1 11476.50", "11223.00 1 11812.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("March Air Force Base", "MAFB4 Location", true, 0, "12075.00 1 11896.50", "11532.00 1 11326.50", "12115.50 1 10759.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Hawkins", "Hawkins1 Location", true, 0, "9621.00 1 10425.00", "10144.50 1 10396.50", "10114.50 1 9772.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Hawkins", "Hawkins2 Location", true, 0, "9823.50 1 10054.50", "9804.00 1 9528.00", "10144.50 1 9450.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bear Town", "Bear Town1 Location", true, 0, "10287.00 1 10036.50", "10260.00 1 10731.00", "11134.50 1 10402.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bear Town", "Bear Town2 Location", true, 0, "11734.50 1 10219.50", "12156.00 1 9502.50", "11667.00 1 9151.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bear Town", "Bear Town3 Location", true, 0, "11578.50 1 10074.00", "11589.00 1 9184.50", "10831.50 1 9832.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Hawkins Nuclear Facility", "HNF1 Location", true, 0, "11455.50 1 9091.50", "10086.00 1 9120.00", "10609.50 1 9882.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Hawkins Nuclear Facility", "HNF2 Location", true, 0, "10269.00 1 8934.00", "11073.00 1 8952.00", "10371.00 1 8107.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Hawkins Nuclear Facility", "HNF3 Location", true, 0, "9996.00 1 8722.50", "9547.50 1 8523.00", "10126.50 1 7761.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Hawkins Nuclear Facility", "HNF4 Location", true, 0, "9193.50 1 9460.50", "8529.00 1 9523.50", "8871.00 1 8566.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Fort Simmons", "FT Location", true, 0, "11539.50 1 8965.50", "12054.00 1 8485.50", "11898.00 1 8100.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Three Frogs Campgrounds", "TFG1 Location", true, 0, "10291.50 1 8025.00", "10950.00 1 7990.50", "10918.50 1 7455.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Three Frogs Campgrounds", "TFG2 Location", true, 0, "11365.50 1 8029.50", "12070.50 1 7993.50", "11716.50 1 7498.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Three Frogs Campgrounds", "TFG3 Location", true, 0, "11295.00 1 8902.50", "11697.00 1 8149.50", "10600.50 1 8112.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bitterroot Speedway", "BS1 Location", true, 0, "8245.50 1 7401.00", "8929.50 1 7798.50", "9094.50 1 7084.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bitterroot Speedway", "BS2 Location", true, 0, "9288.00 1 8469.00", "8839.50 1 7953.00", "9484.50 1 7555.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Wounded Heel Campgrounds", "WHG Location", true, 0, "6447.00 1 10846.50", "6447.00 1 10846.50", "7537.50 1 11014.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Wounded Heel Campgrounds", "WHG Location", true, 0, "8143.50 1 11268.00", "8949.00 1 10710.00", "7837.50 1 10557.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Wounded Heel Campgrounds", "WHG Location", true, 0, "9069.00 1 10533.00", "7690.50 1 10390.50", "9109.50 1 9657.00"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Camp Horizons", "CH Location", true, 0, "5070.00 1 10468.50", "6294.00 1 10848.00", "5815.50 1 8950.50"));

			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bishop Air Station", "BAS1 Location", true, 0, "6354.00 1 9909.00", "6931.50 1 10131.00", "6901.50 1 9265.50"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bishop Air Station", "BAS2 Location", true, 0, "7194.00 1 7873.50", "8251.50 1 7666.50", "7357.50 1 8676.00"));
			iat_THConfig.m_TreasureLocations.Insert(new IAT_TreasureHuntLocation("Bishop Air Station", "BAS3 Location", true, 0, "8587.50 1 9076.50", "7803.00 1 8649.00", "8694.00 1 7990.50"));

			iat_THConfig.ReWeightLocationTiers();

			// write the file to "create it"
			if (!JsonFileLoader<ref IAT_TreasureHuntConfig>.SaveFile(jsonConfig, iat_THConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		else
		{
			// file exists, just load it from disk
			if (!JsonFileLoader<ref IAT_TreasureHuntConfig>.LoadFile(jsonConfig, iat_THConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		// return what we found
        return iat_THConfig;
	}

	// ==================================================================================
	// Getters & Setters
	// ==================================================================================
	bool IsEnabled()
	{
		return m_IsEnabled;
	}
	array<ref IAT_TreasureHuntLocation> GetTreasureLocations()
	{
		if (!m_TreasureLocations)
		{
			m_TreasureLocations = new array<ref IAT_TreasureHuntLocation>();
		}
		return m_TreasureLocations;
	}
	IAT_TreasureHuntTier GetTreasureTierFromLocation(int index)
	{
		if (m_TreasureTiers.IsValidIndex(index))
		{
			return m_TreasureTiers.Get(index);
		}
		return null;
	}

	IAT_TreasureHuntLocation GetRandomTreasureLocation()
	{
		return m_TreasureLocations.GetRandomElement();
	}
	void ReWeightLocationTiers()
	{
		float minArea = 9999999;
		float maxArea = -1;
		float locationArea = -1;
		// for each location
		foreach(IAT_TreasureHuntLocation location : m_TreasureLocations)
		{
			// calculate the area
			locationArea = location.CalculateArea();
			// if the area is smaller than our most smallest
			if (locationArea < minArea)
			{
				minArea = locationArea;
			}
			// if the area is bigger than our most biggest
			if (locationArea > maxArea)
			{
				maxArea = locationArea;
			}
		}

		// normalize the areas of the triangles
		float areaRange = maxArea - minArea;
		// get the total number of tiers
		int numTiers = m_TreasureTiers.Count();
		// if we split up the range by tiers the step is 1 unit
		float stepRange = areaRange / numTiers;

		TFloatArray tierAreaSizeLimits = {};
		for (int i = 0; i < numTiers; i++)
		{
			tierAreaSizeLimits.Insert((stepRange * i));
		}

		int applicableTier = 0;
		// min max range of areas now forms the range for min/max tier
		foreach(IAT_TreasureHuntLocation location1 : m_TreasureLocations)
		{
			// calculate the area
			locationArea = location1.CalculateArea();
			for(int j = 0; j < tierAreaSizeLimits.Count(); j++)
			{
				// is our area bigger than the current tier size?
				if (locationArea > tierAreaSizeLimits[j])
				{
					applicableTier = j;
				}
				else // else use previous tier
				{
					// set the tier based on its relative area
					location1.SetTier(applicableTier);
					break;
				}
			}
		}
	}

	// ================================================================================== HELPERS
	void PrettyPrint()
	{
		Print("--[IAT_TreasureHuntConfig BEGIN]");
		PrintFormat("----m_IsEnabled: %1", m_IsEnabled);
		Print("--[IAT_TreasureHuntLocation BEGIN]");
		foreach (IAT_TreasureHuntLocation location : m_TreasureLocations)
		{
			location.PrettyPrint();
		}
		Print("--[IAT_TreasureHuntLocation END]");
		Print("--[IAT_TreasureHuntTier BEGIN]");
		foreach (IAT_TreasureHuntTier tier : m_TreasureTiers)
		{
			tier.PrettyPrint();
		}
		Print("--[IAT_TreasureHuntTier END]");
		Print("--[IAT_TreasureHuntConfig BEGIN]");
	}
};