using System;
using System.Collections.Generic;
using System.Linq;

public class MagicNumbers
{
    public static Queue<long> magicNums = new Queue<long>();

    public static void FindMagicNumbers(long n)
    {
        for (int i = 0; i <= 9; i++)
        {
            Queue<long> q = new Queue<long>();
            q.Enqueue(i);

            while (q.Count > 0)
            {
                long currNum = q.Peek();
                q.Dequeue();

                if (currNum <= n && currNum >= 1)
                {
                    magicNums.Enqueue(currNum);
                }

                if (i == 0 || currNum > n)
                    continue;

                var lastDigit = currNum % 10;

                var a = lastDigit - 2;
                var b = lastDigit + 2;

                var first = currNum * 10 + a;
                var second = currNum * 10 + b;

                if (a >= 0)
                    q.Enqueue(first);
                if (b < 10)
                    q.Enqueue(second);
            }
        }
    }

    public static void Main(string[] args)
    {
        long n = long.Parse(Console.ReadLine());

        FindMagicNumbers(n);

        var result = magicNums.OrderBy(x => x);

        Console.WriteLine(string.Join(" ", result));
    }
}
