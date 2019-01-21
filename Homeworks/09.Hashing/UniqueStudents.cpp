#include<iostream>
#include<list>
using namespace std;

const int ARRAY_SIZE = 2000;

int hashFunc(int x)
{
	return abs(x) % ARRAY_SIZE;;
}

void insertNumber(list<long long> llist[], int hashIndex, int num)
{
	bool exists = false;

	if (llist[hashIndex].size() == 0)
	{
		llist[hashIndex].push_back(num);
	}
	else if (llist[hashIndex].size() > 0 && llist[hashIndex].front() != num)
	{
		for (auto i = llist[hashIndex].begin(); i != llist[hashIndex].end(); i++)
		{
			if (*i == num)
			{
				exists = true;
				break;
			}
		}

		if (!exists)
		{
			llist[hashIndex].push_back(num);
		}
	}
}

int getCount(list<long long> llist[])
{
	int count = 0;

	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		if (llist[i].size() > 0)
		{
			for (auto it = llist[i].begin(); it != llist[i].end(); it++)
			{
				count++;
			}
		}
	}

	return count;
}

int main()
{
	list<long long> llist[ARRAY_SIZE];

	int n;
	cin >> n;
	long long num;

	for (size_t i = 0; i < n; i++)
	{
		cin >> num;

		int hashIndex = hashFunc(num);

		insertNumber(llist, hashIndex, num);
	}

	int count = getCount(llist);

	cout << count << endl;
}