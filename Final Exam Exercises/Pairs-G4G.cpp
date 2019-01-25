#include<iostream>
#include<list>
using namespace std;

int getSum(list<int> nums)
{
	int maxSum = 0;

	list<int>::iterator it;

	bool isNumberCountEven = nums.size() % 2 == 0 ? true : false;
	int rows = isNumberCountEven == true ? nums.size() : nums.size() - 1;

	int currSum = 0;

	for (it = nums.begin(); it != nums.end() && rows > 0; it++, rows--)
	{
		if ((*it) == 1)
		{
			maxSum += currSum;
			currSum = 0, maxSum += 1;
			continue;
		}

		if (rows % 2 != 0)
		{
			currSum *= (*it);
			maxSum += currSum;
			currSum = 0;
		}
		else
			currSum += (*it);
	}

	if (!isNumberCountEven)
		maxSum += nums.back();

	return maxSum;
}

int main()
{
	int t, n;
	cin >> t;

	for (size_t i = 0; i < t; i++)
	{
		cin >> n;

		list<int> positive;
		list<int> negative;

		int maxSum = 0;

		for (size_t j = 0; j < n; j++)
		{
			int num;
			cin >> num;

			if (num > 0)
				positive.push_back(num);
			else
				negative.push_back(num);
		}

		positive.sort(greater<int>());
		negative.sort();

		int positivesSum = getSum(positive);
		int negativesSum = getSum(negative);

		int max = positivesSum + negativesSum;

		cout << max << endl;
	}
}