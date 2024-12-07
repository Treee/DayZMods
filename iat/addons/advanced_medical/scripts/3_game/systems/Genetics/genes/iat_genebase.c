enum IAT_GeneTypes
{
	Gene1 = 0,
	Gene2
}

class IAT_GeneBase
{
	IAT_GeneTypes m_GeneType = -1;
	int m_GeneMin = -999999;
	int m_GeneMax = 999999;
	int m_CurrentValue = 0;

	void IAT_GeneBase(){}

	//---------------------------------------------------------------------------
	// Behavior
	//---------------------------------------------------------------------------

	IAT_GeneBase CrossOver(IAT_GeneBase other)
	{
		IAT_GeneBase crossOverGene = new IAT_GeneBase();

		crossOverGene.SetGeneType(GetGeneType());
		crossOverGene.SetGeneMin(GetGeneType());
		crossOverGene.SetGeneMax(GetGeneType());

		string geneBinary = GetValueAsBinary();
		string otherBinary = other.GetValueAsBinary();
		
		// get second half of this gene
		string thisHalf = geneBinary.Substring((geneBinary.Length() / 2), (geneBinary.Length() / 2));
		// get first half of other gene
		string otherHalf = otherBinary.Substring(0, (otherBinary.Length() / 2));

		// cross over theirs to ours
		string newGeneBinary = string.Format("%1%2", otherHalf, thisHalf);

		// set the new gene
		int newGeneValue = ConvertToInteger(newGeneBinary);
		crossOverGene.SetGeneValue(newGeneValue);
		
		return crossOverGene;
	}

	//---------------------------------------------------------------------------
	// Helpers
	//---------------------------------------------------------------------------
	void SetGeneMin(int newMin)
	{
		m_GeneMin = newMin;
	}
	int GetGeneMin()
	{
		return m_GeneMin;
	}

	void SetGeneMax(int newMax)
	{
		m_GeneMax = newMax;
	}
	int GetGeneMax()
	{
		return m_GeneMax;
	}

	void SetGeneType(IAT_GeneTypes geneType)
	{
		m_GeneType = geneType;
	}
	IAT_GeneTypes GetGeneType()
	{
		return m_GeneType;
	}

	void SetGeneValue(int newValue)
	{
		m_CurrentValue = newValue;
	}
	int GetValue()
	{
		return m_CurrentValue;
	}
	string GetValueAsBinary()
	{
		string binaryString = "";
		int rawInput = m_CurrentValue;
		while (rawInput > 0)
		{
			if ( (rawInput & 1) == 1)
			{
				binaryString = string.Format("%1%2", "1", binaryString);
			}
			else
			{
				binaryString = string.Format("%1%2", "0", binaryString);
			}
			rawInput >>= 1;
		}

		int stringLength = binaryString.Length();
		// divide string by 8 bits per byte to find how many leading zeros we lack
		int byteLength = stringLength % 8;
		int extraZeros = 0;
		// if we need to fill out a nibble into a byte
		if (byteLength > 0)
		{
			// PrintFormat("Un-Even division for %1 remainder: %3", binaryString, byteLength);
			extraZeros = 8 - byteLength;
			binaryString = string.Format("%1%2", GetNZeros(extraZeros), binaryString);
		}
		return binaryString;
	}

	string GetNZeros(int n)
	{
		if (GameConstants.c_Zeros.IsValidIndex(n))
		{
			return GameConstants.c_Zeros.Get(n);
		}
		return "";
	}
	int ConvertToInteger(string binaryString)
	{
		int sum = 0;
		int exponent = 0;
		string valueAtIndex = "0";
		for(int i = binaryString.Length() - 1; i > -1; i--)
		{
			valueAtIndex = binaryString.Get(i);
			if (valueAtIndex == "1")
			{
				sum += Math.Pow(2, exponent);
			}
			exponent += 1;
		}
		return sum;
	}
	
	string ToPrettyString()
	{
		return string.Format("Type: %1, Min: %2, Value: %3, Max: %4", GetGeneType(), GetGeneMin(), GetValue(), GetGeneMax());
	}
};