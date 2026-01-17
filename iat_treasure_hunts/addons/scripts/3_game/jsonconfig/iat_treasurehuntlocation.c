class IAT_TreasureHuntLocation
{
	protected string m_IAT_LocationHint;
	protected string m_IAT_Name;
	protected bool m_IAT_IsEnabled;
	protected int m_IAT_MaxTreasureTier;
	protected vector m_IAT_Edge1;
	protected vector m_IAT_Edge2;
	protected vector m_IAT_Edge3;

	void IAT_TreasureHuntLocation(string hint, string name, bool isEnabled, int tier, vector edge1, vector edge2, vector edge3)
	{
		m_IAT_LocationHint = hint;
		m_IAT_Name = name;
		m_IAT_IsEnabled = isEnabled;
		m_IAT_MaxTreasureTier = tier;
		m_IAT_Edge1 = edge1;
		m_IAT_Edge2 = edge2;
		m_IAT_Edge3 = edge3;
	}
	float CalculateArea()
	{
		vector AB = m_IAT_Edge2 - m_IAT_Edge1;
		vector AC = m_IAT_Edge3 - m_IAT_Edge1;

		vector cross = AB * AC;
		float area = 0.5 * cross.Length();

		return area;
	}
	string GetLocationHint()
	{
		return m_IAT_LocationHint;
	}
	string GetName()
	{
		return m_IAT_Name;
	}
	string GetTreasureLocationText()
	{
    	return string.Format("I have hidden treasure near\n%1\n\nTriangulation Coordinates:\n\n%2\n\nBurn After Reading", m_IAT_LocationHint, FormatVectorToMapCoords());
	}
	bool IsEnabled()
	{
		return m_IAT_IsEnabled;
	}
	int GetTier()
	{
		return m_IAT_MaxTreasureTier;
	}
	void SetTier(int newTier)
	{
		m_IAT_MaxTreasureTier = newTier;
	}
	vector GetRandomUniformPointInArea()
	{
		// translate points to origin via 2 vectors A and B
		vector a = m_IAT_Edge2 - m_IAT_Edge1;
		vector b = m_IAT_Edge3 - m_IAT_Edge1;
		// Print(string.Format("a: %1 b: %2", a.ToString(), b.ToString()));
		// get 2 floats that when combined are not greater than 1
		float r1 = Math.RandomFloat(0,1);
		float r2 = Math.RandomFloat(0,1);
		float total = r1+r2;
		if (total > 1)
		{
			r1 = 1 - r1;
			r2 = 1 - r2;
		}
		// Print(string.Format("r1: %1 r2: %2", r1, r2));
		// calculate random point
		vector w = (r1 * a) + (r2 * b);
		// Print(string.Format("w: %1 wPrim: %2", w.ToString(), ((m_IAT_Edge1 + w).ToString())));
		// translate point back to world space
		return (m_IAT_Edge1 + w);
	}

	string FormatVectorToMapCoords()
	{
		int maxSize = GetGame().GetWorld().GetWorldSize();

		string a = GetVectorPrettyString(ConvertToMapCoordinate(m_IAT_Edge1, maxSize));
		string b = GetVectorPrettyString(ConvertToMapCoordinate(m_IAT_Edge2, maxSize));
		string c = GetVectorPrettyString(ConvertToMapCoordinate(m_IAT_Edge3, maxSize));

		return string.Format("Grid 1: %1\nGrid 2: %2\nGrid 3: %3", a, b, c);
	}
	string GetVectorPrettyString(vector v)
	{
		return string.Format("(%1, %2)", v[0], v[2]);
	}
	vector ConvertToMapCoordinate(vector v, int maxSize)
	{
		int x = v[0]/100;
		int z = (maxSize-v[2])/100;

		return Vector(x, 1, z);
	}

	void PrettyPrint()
	{
		PrintFormat("----Location Hint: %1 Name: %2 IsEnabled: %3 Max Tier: %4 Edge1: %5 Edge2: %6 Edge3: %7", m_IAT_LocationHint, m_IAT_Name, m_IAT_IsEnabled, m_IAT_MaxTreasureTier, m_IAT_Edge1, m_IAT_Edge2, m_IAT_Edge3);
	}
};