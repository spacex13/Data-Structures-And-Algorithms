#include <algorithm>
#include <iostream> 
#include <string>
#include <iterator>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	string v1string;
	getline(std::cin, v1string);
	string v2string;
	getline(std::cin, v2string);
	string v3string;
	getline(std::cin, v3string);

	istringstream iss1(v1string);
	vector<int> v1{ istream_iterator<int>{iss1},
							istream_iterator<int>() };

	istringstream iss2(v2string);
	vector<int> v2{ istream_iterator<int>{iss2},
		istream_iterator<int>() };

	istringstream iss3(v3string);
	vector<int> v3{ istream_iterator<int>{iss3},
		istream_iterator<int>() };

	int departureTimeMins[3];

	departureTimeMins[0] = v1[0] * 60 + v1[1];
	departureTimeMins[1] = v2[0] * 60 + v2[1];
	departureTimeMins[2] = v3[0] * 60 + v3[1];

	int arriveTimeMins[3];

	arriveTimeMins[0] = v1[2] * 60 + v1[3];
	arriveTimeMins[1] = v2[2] * 60 + v2[3];
	arriveTimeMins[2] = v3[2] * 60 + v3[3];

	int travelTime[3];

	for (int i = 0; i < 3; i++)
	{
		int start = departureTimeMins[i];
		int end = arriveTimeMins[i];

		if (start > end)
		{
			end += 24 * 60;
		}

		travelTime[i] = end - start;
	}

	int minimum = min(min(travelTime[0], travelTime[1]), travelTime[2]);
	int maximum = max(max(travelTime[0], travelTime[1]), travelTime[2]);

	int maxHours = maximum / 60;
	int maxMins = maximum % 60;

	int minHours = minimum / 60;
	int minMins = minimum % 60;

	cout << minHours << ":";

	if (minMins < 10)
		cout << "0";
	cout << minMins << endl;

	cout << maxHours << ":";

	if (maxMins < 10)
		cout << "0";
	cout << maxMins << endl;

	system("pause");
}