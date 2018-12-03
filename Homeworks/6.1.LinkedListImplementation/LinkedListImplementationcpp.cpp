#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int val, Node* next)
	{
		this->data = val;
		this->next = next;
	}
};

class LinkedList {
public:
	LinkedList()
	{
		head = NULL;
		size = 0;
	}

	void addFirst(int val)
	{
		Node* temp = head;
		Node* newNode = new Node(val, temp);

		head = newNode;
		size++;
		return;
	}

	void add(int val, int pos) {
		if (pos < 0 || pos > size)
		{
			cout << "add_last";
			pos = size;
		}

		if (pos == 0 && head != NULL)
		{
			addFirst(val);
			return;
		}

		if (head == NULL)
		{
			head = new Node(val, NULL);
			size++;
			return;
		}

		int i = 0;
		Node* temp = head;

		for (i = 0; i < pos - 1 && temp->next != NULL; i++)
		{
			temp = temp->next;
		}

		Node* newNode = new Node(val, temp->next);
		temp->next = newNode;

		size++;
		return;
	}

	void print() {
		Node* temp = head;

		while (temp != NULL)
		{
			cout << temp->data << "#";
			temp = temp->next;
		}
	}

	void remove(int pos) {
		if (pos < 0 || pos >= size)
		{
			cout << "remove_failed";
			return;
		}

		Node* temp = head;

		if (pos == 0)
		{
			head = temp->next;
			size--;
			return;
		}

		for (size_t i = 0; i < pos - 1; i++)
			temp = temp->next;

		Node* prev = temp->next;
		temp->next = prev->next;
		size--;
	}

	void reverse() {
		Node* curr = head;
		Node* prev = NULL;
		Node* next = NULL;

		while (curr != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		head = prev;
	}

	void remove_all(int val) {
		Node* temp = head;

		for (size_t i = 0; temp != NULL;)
		{
			if (temp->data == val)
			{
				remove(i);
				temp = head;
				if (i != 0)
					i--;
			}
			else
			{
				if (temp->next == NULL)
					break;
				temp = temp->next;
				i++;
			}
		}
	}

	void group(int a, int b) {
		if (a < 0 || b >= size || b < a)
		{
			cout << "fail_grouping";
			return;
		}

		Node* curr = head;

		for (size_t i = 0; i < a; i++)
			curr = curr->next;

		for (size_t i = a; i < b; i++)
		{
			Node* temp = curr->next->next;
			curr->data += curr->next->data;
			delete curr->next;

			curr->next = temp;
			size--;
		}
	}

	void count(int val) {
		Node* temp = head;
		int count = 0;

		while (true)
		{
			if (temp->data == val)
				count++;

			if (temp->next != NULL)
				temp = temp->next;
			else
				break;
		}

		cout << count;
	}

	void is_palindrome() {
		int* arr = new int[size];
		Node* temp = head;

		for (size_t i = 0; i < size; i++)
		{
			arr[i] = temp->data;
			temp = temp->next;
		}

		for (size_t i = 0; i < size / 2; i++)
		{
			if (arr[i] != arr[size - i - 1])
			{
				cout << "false";
				return;
			}
		}

		cout << "true";

	}

	~LinkedList() {
		Node* curr = head;
		Node* next;

		while (curr != NULL)
		{
			next = curr->next;
			delete curr;
			curr = next;
		}

		head = NULL;
	}

private:
	Node* head;
	int size;
};

int main() {
	int cases;
	cin >> cases;

	for (int i = 0; i < cases; i++)
	{
		LinkedList ll;
		int ops;
		string op;
		cin >> ops;

		for (int j = 0; j < ops; j++)
		{
			cin >> op;

			if (op == "count") {
				int arg1;
				cin >> arg1;
				ll.count(arg1);
			}

			if (op == "add") {
				int arg1, arg2;
				cin >> arg1 >> arg2;
				ll.add(arg1, arg2);
			}

			if (op == "print") {
				ll.print();
			}

			if (op == "remove") {
				int arg1;
				cin >> arg1;
				ll.remove(arg1);
			}

			if (op == "reverse") {
				ll.reverse();
			}

			if (op == "remove_all") {
				int arg1;
				cin >> arg1;
				ll.remove_all(arg1);
			}

			if (op == "group") {
				int arg1, arg2;
				cin >> arg1 >> arg2;
				ll.group(arg1, arg2);
			}

			if (op == "is_palindrom") {
				ll.is_palindrome();
			}
		}

		cout << endl;
	}
}