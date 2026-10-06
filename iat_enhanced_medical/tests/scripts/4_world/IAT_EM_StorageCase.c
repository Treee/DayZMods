// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_StorageCase : IAT_EM_PlayerCase
{
	int m_Mode;
	string m_Path;
	ref FileSerializer m_File;
	void IAT_EM_StorageCase(string caseName, int mode)
	{
		m_Suite = "Storage"; m_Name = caseName; m_Mode = mode;
		m_Path = "$profile:em_" + caseName + ".bin";
	}
	override bool Execute()
	{
		if (!m_Ready) return true;
		m_File = new FileSerializer;
		bool opened = m_File.Open(m_Path, FileMode.WRITE);
		Check(opened, "Open isolated serialization fixture", "true", opened.ToString());
		if (!opened) return true;
		IAT_MedicalState original = new IAT_MedicalState;
		if (m_Mode == 0 || m_Mode == 6 || m_Mode == 7)
		{
			if (m_Mode == 0) { original.m_Bullets = 257; original.m_DressedWounds = 65540; }
			if (m_Mode == 6) { original.m_Bullets = -1; original.m_DressedWounds = -2147483648; }
			original.m_LoadResult = "must_not_be_saved";
			original.Save(m_File);
			m_File.Write(9876);
		}
		else if (m_Mode == 2) m_File.Write(99);
		else if (m_Mode == 5) { m_File.Write(1); m_File.Write(-2147483648); m_File.Write(-1); }
		// Complete records only; native EOF behavior is documented in COVERAGE.md.
		m_File.Close();
		opened = m_File.Open(m_Path, FileMode.READ);
		Check(opened, "Reopen serialization fixture", "true", opened.ToString());
		if (!opened) return true;
		IAT_MedicalState restored = new IAT_MedicalState;
		bool actual = restored.Load(m_File);
		bool expected = m_Mode != 2;
		Check(actual == expected, "Medical record load result", expected.ToString(), actual.ToString());
		if (m_Mode == 0)
		{
			EqualInt(restored.m_Bullets, 257, "Roundtrip preserves bullet locations");
			EqualInt(restored.m_DressedWounds, 65540, "Roundtrip preserves independent dressed locations");
		}
		if (m_Mode == 2) Check(restored.m_LoadResult == "unsupported_version=99", "Unsupported record diagnostic", "unsupported_version=99", restored.m_LoadResult);
		if (m_Mode == 5 || m_Mode == 6)
		{
			int expectedBullets = 0;
			int expectedDressed = 536870911;
			if (m_Mode == 6) { expectedBullets = 536870911; expectedDressed = 0; }
			EqualInt(restored.m_Bullets, expectedBullets, "Bullet mask independently rejects unsupported sign bit");
			EqualInt(restored.m_DressedWounds, expectedDressed, "Dressed mask independently rejects unsupported sign bit");
		}
		if (m_Mode == 7)
		{
			EqualInt(restored.m_Bullets, 0, "Empty bullet mask roundtrip");
			EqualInt(restored.m_DressedWounds, 0, "Empty dressed mask roundtrip");
		}
		if (m_Mode == 0 || m_Mode == 6 || m_Mode == 7)
		{
			int sentinel;
			bool read = m_File.Read(sentinel);
			Check(read && sentinel == 9876, "Save contains exactly version and two masks; diagnostics excluded", "9876", sentinel.ToString());
			Check(restored.m_LoadResult == "loaded_version=1", "Supported record diagnostic", "loaded_version=1", restored.m_LoadResult);
			// Read the raw record independently: roundtrip alone could miss matched bugs.
			m_File.Close(); m_File.Open(m_Path, FileMode.READ);
			int version, bullets, dressed;
			m_File.Read(version); m_File.Read(bullets); m_File.Read(dressed);
			EqualInt(version, 1, "Wire version");
			EqualInt(bullets, original.m_Bullets, "Wire bullet field order");
			EqualInt(dressed, original.m_DressedWounds, "Wire dressed field order");
		}
		m_File.Close();
		return true;
	}
	override bool Cleanup()
	{
		if (m_File && m_File.IsOpen()) m_File.Close();
		m_File = null;
		if (FileExist(m_Path)) DeleteFile(m_Path);
		Check(!FileExist(m_Path), "Cleanup deletes profile fixture", "false", FileExist(m_Path).ToString());
		return super.Cleanup();
	}
}
#endif
#endif
