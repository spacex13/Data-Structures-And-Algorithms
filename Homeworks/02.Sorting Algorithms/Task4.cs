using System;
using System.Linq;

class Solution
{
    public static void Main()
    {
        int q = int.Parse(Console.ReadLine());

        for (int i = 0; i < q; i++)
        {
            int n = int.Parse(Console.ReadLine());
            var arr = Console.ReadLine().Split(new[] { " " }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();

            long c = MergeSort(arr, 0, n - 1);

            Console.WriteLine(c);
        }
    }

    public static long Merge(int[] arr, int l, int m, int r)
    {
        long count = 0;

        int leftLen = m - l + 1;
        int rightLen = r - m;

        int[] left = new int[leftLen];
        int[] right = new int[rightLen];

        int i = 0;
        int j = 0;

        for (i = 0; i < leftLen; ++i)
        {
            left[i] = arr[l + i];
        }

        for (j = 0; j < rightLen; ++j)
        {
            right[j] = arr[m + 1 + j];
        }

        i = 0; j = 0;

        int index = l;

        while (i < leftLen && j < rightLen)
        {
            if (left[i] <= right[j])
            {
                arr[index] = left[i];
                i++;
            }
            else
            {
                count += leftLen - i;
                arr[index] = right[j];
                j++;
            }

            index++;
        }

        while (i < leftLen)
        {
            arr[index] = left[i];
            i++;
            index++;
        }

        while (j < rightLen)
        {
            arr[index] = right[j];
            j++;
            index++;
        }

        return count;
    }

    public static long MergeSort(int[] arr, int l, int r)
    {
        long count = 0;

        if (l < r)
        {
            int m = (l + r) / 2;

            count = MergeSort(arr, l, m);
            count += MergeSort(arr, m + 1, r);

            count += Merge(arr, l, m, r);
        }

        return count;
    }
}