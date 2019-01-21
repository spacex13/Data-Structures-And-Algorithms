#include<iostream>
#include<vector>
using namespace std;

void quickSort(int elements[], int left, int right)
{
	int i = left, j = right;
	double pivot = elements[(left + right) / 2];

	while (i <= j)
	{
		while (elements[i] < pivot)
			i++;

		while (elements[j] > pivot)
			j--;

		if (i <= j)
		{
			double tmp = elements[i];
			elements[i] = elements[j];
			elements[j] = tmp;

			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(elements, left, j);

	if (i < right)
		quickSort(elements, i, right);
}

int main()
{
	int n, k;
	cin >> n >> k;

	int toys[100000];

	for (int i = 0; i < n; i++)
	{
		cin >> toys[i];
	}

	quickSort(toys, 0, n - 1);

	int boughtToys = 0;

	for (int i = 0; i < n; i++)
	{
		if (k - toys[i] >= 0)
		{
			boughtToys++;
			k -= toys[i];
		}
		else
			break;
	}

	cout << boughtToys << endl;
}