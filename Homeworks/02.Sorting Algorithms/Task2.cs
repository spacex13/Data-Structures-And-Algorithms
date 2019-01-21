using System;

namespace ex2
{
    public class Program
    {
        public static void Main(string[] args)
        {
            string s = Console.ReadLine().ToLower();

            int[] lettersCount = new int[26];
            int len = s.Length;

            for (int i = 0; i < len; i++)
            {
                int index = s[i] - 97;
                lettersCount[index]++;
            }

            bool isPossible = true;

            for (int i = 0; i < 26; i++)
            {
                if (lettersCount[i] > Math.Ceiling((double)len / 2))
                {
                    isPossible = false;
                }
            }

            string result = isPossible ? "Yes" : "No";
            Console.WriteLine(result);
        }
    }
}