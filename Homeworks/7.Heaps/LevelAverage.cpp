#include<iostream>
#include<map>
#include<vector>
#include <iomanip>     

using namespace std;

int currentLevel = 0;

map<int, vector<float>> values;

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int data)
	{
		this->left = NULL;
		this->right = NULL;
		this->data = data;
	};
};

class BST
{
public:
	int getHeight(Node* root)
	{
		int height = 0;

		if (root == NULL)
			return 0;

		int lH = getHeight(root->left);
		int rH = getHeight(root->right);

		if (lH > rH)
			return lH + 1;

		return rH + 1;
	}

	Node* insert(Node* root, float data) {
		if (root == NULL)
			return new Node(data);

		Node* cur;
		if (data < root->data) {
			cur = insert(root->left, data);
			root->left = cur;
		}
		else {
			cur = insert(root->right, data);
			root->right = cur;
		}

		return root;
	}

	void level(Node* root, int l)
	{
		if (root == NULL)
			return;

		if (l == 1)
		{
			values[currentLevel].push_back(root->data);
		}
		else
		{
			level(root->left, l - 1);
			level(root->right, l - 1);
		}
	}

	void getLevelsAverage(Node* root)
	{
		int h = getHeight(root);

		for (size_t i = 1; i <= h; i++)
		{
			currentLevel = i;

			level(root, i);
		}
	}
};

int main()
{
	cout << fixed << setprecision(2);
	long n;
	cin >> n;

	Node* root = NULL;
	BST* bst = new BST();
	float data;

	for (size_t i = 0; i < n; i++)
	{
		cin >> data;
		root = bst->insert(root, data);
	}

	bst->getLevelsAverage(root);
	int h = bst->getHeight(root);

	for (size_t i = 1; i <= h; i++)
	{
		float sum = 0;

		for (size_t k = 0; k < values[i].size(); k++)
			sum += values[i].at(k);

		float avg = sum / values[i].size();
		cout << avg << endl;
	}
}