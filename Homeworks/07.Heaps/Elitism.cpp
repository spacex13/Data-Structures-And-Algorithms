#include<queue>
#include<iostream>
#include<iomanip>
#include<functional>
using namespace std;

template <class TComp>
struct Heap
{
	vector<int> values;
	TComp comparator;

	void push(int value)
	{
		values.push_back(value);
		push_heap(values.begin(), values.end(), comparator);
	}

	int pop()
	{
		int val = top();
		pop_heap(values.begin(), values.end(), comparator);
		values.pop_back();

		return val;
	}

	int top() const
	{
		return values.front();
	}

	size_t size() const
	{
		return values.size();
	};
};

Heap<less<int>> lowerValues;
Heap<greater<int>> higherValues;

double getMedian()
{
	int lowerSize = lowerValues.size();
	int higherSize = higherValues.size();

	if ((lowerSize + higherSize) % 2 > 0)
	{
		if (lowerValues.size() > higherValues.size())
			return lowerValues.top();
		else
			return higherValues.top();
	}
	else
		return ((double)lowerValues.top() + higherValues.top()) / 2;
}

void swapLowerValueForNew(int value)
{
	if (value < lowerValues.top())
	{
		int data = lowerValues.top();
		higherValues.push(data);
		lowerValues.pop();
		lowerValues.push(value);
	}
	else
		higherValues.push(value);
}

void swapHigherValueForNew(int value)
{
	if (value > higherValues.top())
	{
		int data = higherValues.top();
		lowerValues.push(data);
		higherValues.pop();
		higherValues.push(value);
	}
	else
		lowerValues.push(value);
}

void addValue(int value)
{
	if (lowerValues.size() == 0)
	{
		lowerValues.push(value);
	}
	else if (higherValues.size() == 0)
	{
		swapLowerValueForNew(value);
	}
	else if (lowerValues.size() > higherValues.size())
	{
		swapLowerValueForNew(value);
	}
	else
		swapHigherValueForNew(value);
}

int main() {
	int n;
	cin >> n;

	int value;
	cout << fixed << setprecision(1);

	for (size_t i = 0; i < n; i++)
	{
		cin >> value;

		addValue(value);

		double median = getMedian();

		cout << median << endl;
	}
}