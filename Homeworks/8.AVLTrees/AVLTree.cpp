#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Node
{
	double value;
	Node *left;
	Node *right;
	int height;

	Node(double value, Node *left, Node *right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
		height = 1;
	}
};

class AVLTree
{
private:
	Node *root;

	bool containsRecursive(Node *current, double value)
	{
		if (current == NULL)
		{
			return false;
		}

		if (current->value == value)
		{
			return true;
		}

		if (value < current->value)
		{
			return containsRecursive(current->left, value);
		}
		else
		{
			return containsRecursive(current->right, value);
		}
	}

	void printRecursive(Node *current)
	{
		if (current == NULL)
		{
			return;
		}

		printRecursive(current->left);
		cout << current->value << " ";
		printRecursive(current->right);
	}

public:
	AVLTree()
	{
		root = NULL;
	}

	int getHeight(Node* node)
	{
		if (node == NULL)
			return 0;

		return node->height;
	}

	int getBalance(Node* node)
	{
		if (node == NULL)
			return 0;

		int balance = getHeight(node->left) - getHeight(node->right);

		return balance;
	}

	Node* rotateRight(Node* node)
	{
		Node* n = node->left;
		node->left = n->right;
		n->right = node;

		n->height = max(getHeight(n->left), getHeight(n->right))/* + 1*/;

		return n;
	}

	Node* rotateLeft(Node* node)
	{
		Node* n = node->right;
		node->right = n->left;
		n->right = node;

		n->height = max(getHeight(n->left), getHeight(n->right))/* + 1*/;

		return n;
	}

	Node* BSTinsert(Node* node, double value)
	{
		if (node == NULL)
			return new Node(value, NULL, NULL);

		if (value < node->value)
		{
			node->left = BSTinsert(node->left, value);
		}
		else if (value > node->value)
		{
			node->right = BSTinsert(node->right, value);
		}
		else
		{
			cout << value << " already added" << endl;
			return node;
		}

		node->height = max(getHeight(node->left), getHeight(node->right))/* + 1*/;
		int balance = getBalance(node);

		if (balance > 1)
		{
			if (value < node->left->value)
				node = rotateRight(node);
			else
			{
				node->right = rotateRight(node->right);
				node = rotateLeft(node);
			}
		}
		else if (balance < -1)
		{
			if (value > node->right->value)
				node = rotateLeft(node);
			else
			{
				node->left = rotateLeft(node->left);
				node = rotateRight(node);
			}
		}

		return node;
	}

	void add(double value)
	{
		root = BSTinsert(this->root, value);
	}

	Node* findMinValue(Node* node)
	{
		Node* temp = node;
		while (temp->left != NULL)
			temp = temp->left;

		return temp;
	}

	Node* BSTdelete(Node* node, double value)
	{
		if (node == NULL)
		{
			cout << value << " not found to remove" << endl;
			return node;
		}

		if (value < node->value)
			node->left = BSTdelete(node->left, value);
		else if (value > node->value)
			node->right = BSTdelete(node->right, value);
		else if (node->left && node->right)
		{
			Node* min = findMinValue(node->right);
			node->value = min->value;
			node->right = BSTdelete(node->right, min->value);
		}
		else
		{
			Node* temp = node->right != NULL ? node->right : node->left;

			if (temp != NULL)
			{
				node = temp;
			}
			else
			{
				temp = node;
				node = NULL;
			}
		}

		if (node == NULL)
			return node;

		node->height = max(getHeight(node->left), getHeight(node->right))/* + 1*/;
		int balance = getBalance(node);

		if (balance > 1)
		{
			if (getBalance(node->left) >= 0)
				return rotateRight(node);
			else
			{
				root->left = rotateLeft(root->left);
				root = rotateRight(node);
			}
		}
		else if (balance < -1)
		{
			if (getBalance(node->right) <= 0)
				return rotateLeft(node);
			else
			{
				root->right = rotateRight(root->right);
				root = rotateLeft(node);
			}
		}

		return node;
	}

	void remove(double value)
	{
		root = BSTdelete(root, value);
	}

	bool contains(double value)
	{
		if (root == NULL)
		{
			return false;
		}

		return containsRecursive(root, value);
	}

	void print()
	{
		if (root == NULL)
		{
			return;
		}

		printRecursive(root);
		cout << endl;
	}
};

int main()
{
	AVLTree tree;
	string operation;
	double number;
	int N;

	cin >> N;
	cout << fixed << setprecision(6);

	for (size_t i = 0; i < N; i++)
	{
		cin >> operation;
		if (operation != "print")
		{
			cin >> number;
		}

		if (operation == "add")
		{
			tree.add(number);
		}
		else if (operation == "remove")
		{
			tree.remove(number);
		}
		else if (operation == "contains")
		{
			if (tree.contains(number))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
		else if (operation == "print")
		{
			tree.print();
		}
	}
}