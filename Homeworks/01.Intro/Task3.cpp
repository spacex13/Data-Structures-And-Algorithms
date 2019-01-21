#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countOfSameChars(vector<char> str, char ch)
{
	int count = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ch)
			count++;
	}

	return count;
}

int countOfSameChars(string str, char ch)
{
	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ch)
			count++;
	}

	return count;
}

int main()
{
	string first;
	getline(cin, first);
	string second;
	getline(cin, second);

	vector<char> v;

	sort(first.begin(), first.end());
	sort(second.begin(), second.end());

	for (int i = 0; i < first.length(); i++)
	{
		for (int k = 0; k < second.length(); k++)
		{
			if (first[i] == second[k])
			{
				if (countOfSameChars(v, first[i]) >= min(countOfSameChars(first, first[i]), countOfSameChars(second, first[i])))
				{
					break;
				}

				v.push_back(first[i]);
				break;
			}
		}
	}

	sort(v.begin(), v.end());
	int s = v.size();

	for (int i = 0; i < s; i++)
	{
		cout << v[i];
	}

	cout << endl;
}