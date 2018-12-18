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

		n->height = max(getHeight(n->left), getHeight(n->right));

		return n;
	}

	Node* rotateLeft(Node* node)
	{
		Node* n = node->right;
		node->right = n->left;
		n->right = node;

		n->height = max(getHeight(n->left), getHeight(n->right));

		return n;
	}

	Node* BSTinsert(Node* node, double value)
	{
		if (node == NULL)
		{
			return new Node(value, NULL, NULL);
		}

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
			return node;
		}

		node->height = max(getHeight(node->left), getHeight(node->right));
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

	bool contains(double value)
	{
		if (root == NULL)
		{
			return false;
		}

		return containsRecursive(root, value);
	}

	int getCount(Node* node)
	{
		if (node == NULL)
			return 0;

		int count = 1;

		if (node->left != NULL)
			count += getCount(node->left);
		if (node->right != NULL)
		count += getCount(node->right);

		return count;
	}

	void printCount()
	{
		cout << getCount(root) << endl;
	}
};

int main()
{
	AVLTree tree;
	int m, N;

	cin >> m >> N;

	tree.add(m);

	int x, y;

	for (size_t i = 0; i < N; i++)
	{
		cin >> x >> y;

		if (tree.contains(x))
		{
			tree.add(y);
		}
	}

	tree.printCount();
}