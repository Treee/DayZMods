class IAT_GeneBase
{
	protected IAT_GeneTypes m_GeneType = -1;
	protected int m_GeneMin = -65536;
	protected int m_GeneMax = 65536;

	protected int m_CurrentValue = 0;
	protected int m_NumBytes = 2; // default 2 bytes is sweet spot
	protected string m_GeneBinary = "0000000000000000";
	// positive/negative simulates dominant/recessive traits
	protected bool m_IsNegative = false;

	void IAT_GeneBase(){}

	//---------------------------------------------------------------------------
	// Behavior
	//---------------------------------------------------------------------------

	IAT_GeneBase CrossOver(IAT_GeneBase other)
	{
		if (m_GeneType != other.GetGeneType())
		{
			PrintFormat("Gene Types Are Different. {this}: %1 {other}: %2", m_GeneType, other.GetGeneType());
			return null;
		}

		if (m_NumBytes != other.GetNumBytes())
		{
			PrintFormat("Gene Bytes Are Different. {this}: %1 {other}: %2", m_NumBytes, other.GetNumBytes());
			return null;
		}
		IAT_GeneBase crossOverGene = new IAT_GeneBase();

		crossOverGene.SetGeneType(GetGeneType());
		crossOverGene.SetGeneMin(GetGeneMin());
		crossOverGene.SetGeneMax(GetGeneMax());

		string geneBinary = GetValueAsBinary();
		string otherBinary = other.GetValueAsBinary();

		int geneBinaryLength = geneBinary.Length();
		int otherBinaryLength = otherBinary.Length();
		string extraZeros = "";
		if (geneBinaryLength > otherBinaryLength)
		{
			extraZeros = GetNZeros(geneBinaryLength - otherBinaryLength);
			otherBinary = string.Format("%1%2", extraZeros, otherBinary);
		}
		else if (otherBinaryLength > geneBinaryLength)
		{
			extraZeros = GetNZeros(otherBinaryLength - geneBinaryLength);
			geneBinary = string.Format("%1%2", extraZeros, geneBinary);
		}

		// get second half of this gene
		string thisHalf = geneBinary.Substring((geneBinary.Length() / 2), (geneBinary.Length() / 2));
		// get first half of other gene
		string otherHalf = otherBinary.Substring(0, (otherBinary.Length() / 2));

		// cross over theirs to ours
		string newGeneBinary = string.Format("%1%2", otherHalf, thisHalf);

		// punnet square is_negative trait
		// both parents are negative
		if (m_IsNegative && other.IsNegative())
			crossOverGene.SetIsNegative(true);
		// both parents are positive
		else if (!(m_IsNegative || other.IsNegative()))
			crossOverGene.SetIsNegative(false);
		// 50/50 random
		else
			crossOverGene.SetIsNegative(Math.RandomBool());

		// set the new gene
		int newGeneValue = ConvertToInteger(newGeneBinary);
		crossOverGene.SetGeneValue(newGeneValue);
		crossOverGene.InitializeGene();

		return crossOverGene;
	}

	void InitializeGene()
	{
		// take raw data and turn it into genes ie...
		// calculate max byte size from max value
		GetMaxBytesFromMaxValue();
		// convert current value to binary and set it.
		m_GeneBinary = GetValueAsBinary();
	}

	private void GetMaxBytesFromMaxValue()
	{
		int absMinValue = Math.AbsInt(m_GeneMin);
		int index = 0;
		foreach (int byteMaxValue : GameConstants.c_ByteMax)
		{
			if (m_GeneMax > byteMaxValue || absMinValue > byteMaxValue)
			{
				index++;
				continue;
			}
			m_NumBytes = index;
			return;
		}
	}

	private string GetValueAsBinary()
	{
		string binaryString = "";
		int rawInput = m_CurrentValue;

		if (rawInput < 0)
		{
			m_IsNegative = true;
			rawInput *= -1;
		}

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

		int byteLength = m_NumBytes * 8;
		int extraZeros = byteLength - binaryString.Length();

		if (extraZeros > 0)
			binaryString = string.Format("%1%2", GetNZeros(extraZeros), binaryString);

		return binaryString;
	}

	//---------------------------------------------------------------------------
	// Helpers
	//---------------------------------------------------------------------------
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

	//---------------------------------------------------------------------------
	// Setters & Getters
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
		if (m_IsNegative)
			return m_CurrentValue * -1;
		return m_CurrentValue;
	}

	void SetGeneBinaryString(string s)
	{
		m_GeneBinary = s;
	}
	string GetBinaryString()
	{
		return m_GeneBinary;
	}

	void SetNumBytes(int i)
	{
		m_NumBytes = i;
	}
	int GetNumBytes()
	{
		return m_NumBytes;
	}
	void SetIsNegative(bool isNegative)
	{
		m_IsNegative = isNegative;
	}
	bool IsNegative()
	{
		return m_IsNegative;
	}
};