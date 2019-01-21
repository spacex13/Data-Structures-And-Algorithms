#include<iostream>
#include<algorithm>

using namespace std;

int first(long long arr[], int l, int r, long long x)
{
	if (l <= r)
	{
		int m = (l + r) / 2;

		if (arr[m] == x && (m == 0 || x > arr[m - 1]))
			return m + 1;
		else if (arr[m] < x)
			return first(arr, m + 1, r, x);
		else
			return first(arr, l, m - 1, x);
	}

	return -1;
}

int last(long long arr[], int l, int r, long long x, int n)
{
	if (l <= r)
	{
		int m = (l + r) / 2;

		if (arr[m] == x && (arr[m + 1] > x || m == n))
			return m + 1;
		else if (arr[m] > x)
			return last(arr, l, m - 1, x, n);
		else
			return last(arr, m + 1, r, x, n);
	}

	return -1;
}

int main()
{
	int n, q;
	cin >> n;

	long long arr[n]; // n = array size

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cin >> q;
	long long p;

	for (int i = 0; i < q; i++)
	{
		cin >> p;

		int firstIndex = first(arr, 0, n - 1, p);
		int lastIndex = last(arr, 0, n - 1, p, n - 1);

		cout << firstIndex << " " << lastIndex << endl;
	}
}