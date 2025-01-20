modded class PlayerBase
{
	TStringArray GetFacialHairOptions()
	{
		PluginLifespan moduleLifespan = PluginLifespan.Cast(GetPlugin(PluginLifespan));
		// if there isa lifespan plugin (client side)
		if (moduleLifespan)
		{	// return the list of types available
			return moduleLifespan.GetBeards();
		}
		// empty list
		return {};
	}
};