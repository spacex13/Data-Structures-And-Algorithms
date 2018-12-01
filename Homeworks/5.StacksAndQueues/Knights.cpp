#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

Node* addNode(int data)
{
	Node *temp = new Node;
	temp->next = temp;
	temp->data = data;

	return temp;
}

int main()
{
	int n;
	cin >> n;

	Node *head = addNode(1);
	Node *current = head;

	for (int i = 2; i <= n; i++)
	{
		if (i % 2 != 0)
		{
			current->next = addNode(i);
			current = current->next;
		}
	}

	current->next = head;

	Node* og = head;
	Node* helper = og;

	while (og->next != og)
	{
		helper = og;
		og = og->next;

		helper->next = og->next;
		og = helper->next;
	}

	cout << og->data << endl;
}