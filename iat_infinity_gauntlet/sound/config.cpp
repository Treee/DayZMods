class CfgPatches
{
    class IAT_InfinityGauntlet_Sound
    {
        requiredAddons[] = { "DZ_Data","DZ_Sounds_Effects" };
    };
};

class CfgSoundShaders
{
    class IAT_InfinityGauntlet_SoundShader_Base
    {
        samples[] = {};
        frequency = 1;
        range = 1000;
        volume = 1;
    };

    class IAT_InfinityGauntlet_SoundShader_FingerSnap : IAT_InfinityGauntlet_SoundShader_Base
    {
        samples[] = { {"iat_infinity_gauntlet\sound\data\fingersnap.ogg",1} };
    };
};

class CfgSoundSets
{
    class IAT_InfinityGauntlet_SoundSet_FingerSnap
    {
        soundShaders[] = { "IAT_InfinityGauntlet_SoundShader_FingerSnap" };
    };
};