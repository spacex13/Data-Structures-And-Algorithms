using System;

public class Program
{
    public static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        int[] array = new int[n];

        for (int i = 0; i < n; i++)
        {
            array[i] = int.Parse(Console.ReadLine());
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int c = i + 1; c < n; c++)
            {
                if (!FirstIsBigger(array[i], array[c]))
                {
                    int temp = array[i];
                    array[i] = array[c];
                    array[c] = temp;
                }
            }
        }

        string result = string.Join("", array);

        if (result.StartsWith("0"))
            Console.WriteLine("0");
        else
            Console.WriteLine(result);
    }

    public static bool FirstIsBigger(int a, int b)
    {
        long one = long.Parse(a + "" + b);
        long two = long.Parse(b + "" + a);

        if (one > two)
            return true;

        return false;
    }
}