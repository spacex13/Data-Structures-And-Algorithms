#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

class List
{
public:
	Node *head;
	List()
	{
		head = NULL;
	}

	void add(int data)
	{
		Node* node = new Node();
		node->data = data;
		node->next = this->head;
		this->head = node;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);

	List *list = new List();

	int num;

	while (cin >> num)
	{
		list->add(num);
	}

	int max = INT32_MIN;
	int min = INT32_MAX;
	long long sum = 0;

	Node* headNode = list->head;
	while (headNode != NULL)
	{
		if (headNode->data > max)
			max = headNode->data;

		if (headNode->data < min)
			min = headNode->data;

		sum += headNode->data;
		headNode = headNode->next;
	}

	cout << min << " " << max << " " << sum << endl;
}