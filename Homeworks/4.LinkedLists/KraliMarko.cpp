#include<iostream>
#include<algorithm> 
#include<vector>
#include <map>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

class List
{
public:
	Node *head, *tail;

	List()
	{
		head = NULL;
		tail = NULL;
	}

	void addNode(int newData)
	{
		Node* newNode = new Node();
		Node* last = head;

		newNode->data = newData;
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

	int getNodeAt(int index)
	{
		int count = 0;
		Node* result = head;

		while (result != NULL)
		{
			if (count == index)
				break;
			result = result->next;
			count++;
		}

		return result->data;
	}
};

int main()
{
	int n, p;
	cin >> n;

	List *list = new List();

	for (size_t i = 0; i < n; i++)
	{
		int data;
		cin >> data;

		list->addNode(data);
	}

	cin >> p;
	vector<long long> v;
	for (size_t i = 0; i < min(p, 1234); i++)
	{
		long long el;
		cin >> el;
		v.push_back(el);
	}

	int couples = 0;
	sort(v.begin(), v.end());

	int prev = list->getNodeAt(0);

	vector<int> p1;
	vector<int> p2;

	for (size_t i = 0; i < n - 1; i++)
	{
		int next = list->getNodeAt(i + 1);
		bool r = binary_search(v.begin(), v.end(), prev);
		bool l = binary_search(v.begin(), v.end(), next);

		bool pairExists = false;

		for (size_t k = 0; k < couples; k++)
		{
			if ((p1[k] == next && p2[k] == prev) || (p1[k] == prev && p2[k] == next))
			{
				pairExists = true;
				break;
			}
		}

		if (l && r && !pairExists)
		{
			p1.push_back(prev);
			p2.push_back(next);
			couples++;
		}

		prev = next;
	}

	cout << couples << endl;
}