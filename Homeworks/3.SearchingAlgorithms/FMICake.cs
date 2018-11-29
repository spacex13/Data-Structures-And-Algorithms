using System;

class Solution
{
    public static void Main(string[] args)
    {
        int t = int.Parse(Console.ReadLine());

        for (int i = 0; i < t; i++)
        {
            int n = int.Parse(Console.ReadLine());
            int days = 0;

            int[] arr = MakeArray(n);

            int m = n;

            while (m > 0)
            {
                days++;
                m /= 2;

                for (int k = 0; k < n; k++)
                {
                    if (arr[k] - arr[m] >= 0)
                        arr[k] -= arr[m];
                }
            }

            Console.WriteLine(days);
        }
    }

    public static int[] MakeArray(int n)
    {
        int[] arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }

        return arr;
    }
}