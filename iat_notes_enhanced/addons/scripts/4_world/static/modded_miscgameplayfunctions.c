modded class MiscGameplayFunctions
{
    static const int MAX_NOTE_LENGTH = 2048;

    override static string SanitizeString(string input)
    {
        // int max_length = MAX_NOTE_LENGTH;// 512; //vanilla
        string output = input;

        output = output.Substring(0,Math.Clamp(MAX_NOTE_LENGTH,0,output.Length()));
        // Print("Sanitizing string input: " + input);
        // Print("Sanitizing string output: " + output);
        return output;
    }
};