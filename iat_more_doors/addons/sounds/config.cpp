class CfgPatches
{
	class IAT_MoreDoors_Sounds
	{
		requiredAddons[] = { "DZ_Data", "DZ_Sounds_Effects" };
	};
};

class CfgSoundShaders
{
	class IAT_Door_SoundShader_Base
	{
		samples[] = {};
		frequency = 1;
		range = 25;
		rangeCurve[] =
		{
			{0,1},
			{80,0.5},
			{100,0.30000001},
			{150,0.2},
			{200,0}
		};
		volume = 2;
	};

	class IAT_Door_MetalSmallOpen : IAT_Door_SoundShader_Base
	{
		samples[] = { {"\DZ\sounds\environment\buildings\doors\MetalSmall\doorMetalSmallOpen_1", 1} };
	};
	class IAT_Door_MetalSmallClose : IAT_Door_SoundShader_Base
	{
		samples[] = { {"\DZ\sounds\environment\buildings\doors\MetalSmall\doorMetalSmallClose_1", 1} };
	};

	class IAT_Door_MetalContainerOpen : IAT_Door_SoundShader_Base
	{
		samples[] =
		{
			{"\DZ\sounds\environment\buildings\doors\MetalContainer\doorMetalContainerOpen_1", 0.5},
			{"\DZ\sounds\environment\buildings\doors\MetalContainer\doorMetalContainerOpen_2", 0.5},
		};
	};
	class IAT_Door_MetalContainerClose : IAT_Door_SoundShader_Base
	{
		samples[] =
		{
			{"\DZ\sounds\environment\buildings\doors\MetalContainer\doorMetalContainerClose_1", 0.5},
			{"\DZ\sounds\environment\buildings\doors\MetalContainer\doorMetalContainerClose_2", 0.5},
		};
	};
};

class CfgSoundSets
{
	class IAT_Door_MetalSmallOpen_SoundSet
	{
		soundShaders[] = { "IAT_Door_MetalSmallOpen" };
	};
	class IAT_Door_MetalSmallClose_SoundSet
	{
		soundShaders[] = { "IAT_Door_MetalSmallClose" };
	};

	class IAT_Door_MetalContainerOpen_SoundSet
	{
		soundShaders[] = { "IAT_Door_MetalContainerOpen" };
	};
	class IAT_Door_MetalContainerClose_SoundSet
	{
		soundShaders[] = { "IAT_Door_MetalContainerClose" };
	};
};