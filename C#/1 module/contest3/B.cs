partial class Program
{
    private static void GetLetterDigitCount(string line, out int digitCount, out int letterCount)
    {
        digitCount = 0;
        letterCount = 0;
        foreach (char c in line)
        {
            digitCount += c >= '0' && c <= '9' ? 1 : 0;
            letterCount += c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' ? 1 : 0;
        }
    }
}
