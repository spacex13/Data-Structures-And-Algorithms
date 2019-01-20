#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string name;

	map<string, int> nameOccurrences;
	map<string, string> names;
	set<string> prefixes;

	for (size_t i = 0; i < n; i++)
	{
		cin >> name;
		string prefix;

		for (size_t i = 0; i < name.size(); i++)
		{
			if (nameOccurrences.count(name) > 0)
			{
				nameOccurrences[name]++;
				cout << name << " " << nameOccurrences[name] << endl;
				break;
			}

			prefix += name[i];

			if (i == name.size() - 1)
			{
				nameOccurrences[name]++;
				cout << name << endl;
				break;
			}

			if (prefixes.count(prefix) == 0 && names[prefix].empty())
			{
				names[prefix] = name;
				nameOccurrences[name]++;
				cout << prefix << endl;
				break;
			}
		}

		if (!prefix.empty())
		{
			prefix = "";
			for (size_t i = 0; i < name.size(); i++)
			{
				prefix += name[i];
				prefixes.insert(prefix);
			}
		}
	}
}