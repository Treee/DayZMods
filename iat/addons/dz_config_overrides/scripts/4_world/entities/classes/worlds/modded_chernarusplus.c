modded class ChernarusPlusData
{
	override bool WeatherOnBeforeChange( EWeatherPhenomenon type, float actual, float change, float time )
	{
		// we need to capture the return value becasue setting storm values needs to happen after this call
		// but this function needs to return something so order matters.
		bool superBool = super.WeatherOnBeforeChange(type, actual, change, time);

		// reduce storms by 60%
		m_Weather.SetStorm( 0.4, m_WeatherDefaultSettings.m_StormThreshold, 45 );

		// return vanilla bool
		return superBool;
	}
};