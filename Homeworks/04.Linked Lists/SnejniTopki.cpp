#include<iostream>
#include<algorithm> 
#include<vector>
using namespace std;

struct Node {
	struct Node *next;
	vector<long long> snowballs;
};

class List
{
public:
	Node *head;

	List()
	{
		head = NULL;
	}

	void addLastNode(vector<long long> newData)
	{
		Node* newNode = new Node();
		Node* last = head;

		newNode->snowballs = newData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
		{
			while (last->next != NULL)
				last = last->next;

			last->next = newNode;
		}
	}

	Node* getNodeAt(long long index)
	{
		long long count = 0;
		Node* result = head;

		while (result != NULL)
		{
			if (count == index)
				break;
			result = result->next;
			count++;
		}

		return result;
	}

	long long sumSnowballs()
	{
		Node* current = head;
		long long sum = 0;

		while (current != NULL)
		{
			for (size_t i = 0; i < current->snowballs.size(); i++)
			{
				sum += current->snowballs[i];
			}

			current = current->next;
		}

		return sum;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);

	List *list = new List();

	int n;
	cin >> n;

	vector<long long> snow = { 0 };
	list->addLastNode(snow);

	for (size_t i = 0; i < n; i++)
	{
		int p, m;
		cin >> p >> m;

		Node* current = list->getNodeAt(p);

		vector<long long> copySnow = current->snowballs;

		if (m > 0)
		{
			copySnow.push_back(m);
		}
		else
		{
			copySnow.pop_back();
		}

		list->addLastNode(copySnow);
	}

	long long sum = list->sumSnowballs();
	cout << sum << endl;
}