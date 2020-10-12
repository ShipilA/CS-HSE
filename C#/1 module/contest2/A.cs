using System;

namespace Contest2
{
    class Program
    {
        static void Main(string[] args)
        {
            if (uint.TryParse(Console.ReadLine(), out uint n))
            {
                uint sum = 0;
                for (; n > 0; n /= 10)
                    sum += n % 10;
                Console.WriteLine(sum);
            }
            else
                Console.WriteLine("Incorrect input");
        }
    }
}
