// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Slow salmonella growth without changing immunity or medicine resistance.
// Integration: vanilla transmission-agent pool.
// Documentation: iat_enhanced_medical/README.md

modded class SalmonellaAgent
{
	override void Init()
	{
		super.Init();
		m_Invasibility = 0.225;
	}
}
