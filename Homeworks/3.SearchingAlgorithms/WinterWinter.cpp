#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	long long k;

	cin >> n >> k;

	long long arr[100000];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int time = 0;

	while (true)
	{
		sort(arr, arr + n);

		if (arr[n - 1] <= 0)
			break;

		arr[n - 1] -= k;
		time++;

		for (int i = 0; i < n; i++)
		{
			if (i != n - 1 && arr[i] > 0)
			{
				arr[i]--;
			}
		}
	}

	cout << time << endl;
}