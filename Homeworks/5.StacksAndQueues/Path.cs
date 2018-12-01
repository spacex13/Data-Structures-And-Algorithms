using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Stack<int> stack = new Stack<int>();
        for (int i = 0; i < n; i++)
        {
            string[] line = Console.ReadLine().Split(' ');
            string color = line[0];
            int k = int.Parse(line[1]);
            if (color == "green")
            {
                int sum = 0;
                for (int p = 0; p < k; p++)
                {
                    if (stack.Count > 0)
                    {
                        int data = int.Parse(stack.Peek().ToString());
                        sum += data;
                        stack.Pop();
                    }
                }

                k = sum;
            }
            else if (color == "blue")
            {
                int max = 0;
                for (int p = 0; p < k; p++)
                {
                    if (stack.Count > 0)
                    {
                        int data = int.Parse(stack.Peek().ToString());
                        stack.Pop();
                        if (max < data)
                            max = data;
                    }
                }

                k = max;
            }

            stack.Push(k);
        }

        string s = string.Join(" ", stack.Reverse());

        Console.WriteLine(s);
    }
}