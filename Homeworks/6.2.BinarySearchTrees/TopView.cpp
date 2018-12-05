#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

class Solution {
public:
	Node* insert(Node* root, int data) {
		if (root == NULL) {
			return new Node(data);
		}
		else {
			Node* cur;
			if (data <= root->data) {
				cur = insert(root->left, data);
				root->left = cur;
			}
			else {
				cur = insert(root->right, data);
				root->right = cur;
			}

			return root;
		}
	}

	void topView(Node * root) {
		if (root == NULL)
			return;

		queue<Node*> nodes;
		map<int, int> elements;
		map<Node*, int> hdNodes;

		int hd = 0;
		nodes.push(root);
		hdNodes[root] = hd;

		while (nodes.size())
		{
			hd = hdNodes[root];

			if (elements.count(hd) == 0)
				elements[hd] = root->data;

			if (root->left != NULL)
			{
				hdNodes[root->left] = hd - 1;
				nodes.push(root->left);
			}

			if (root->right != NULL)
			{
				hdNodes[root->right] = hd + 1;
				nodes.push(root->right);
			}

			nodes.pop();
			if (nodes.size() > 0)
				root = nodes.front();
		}

		for (auto data = elements.begin(); data != elements.end(); data++)
		{
			cout << data->second << " ";
		}
	}
};

int main() {

	Solution myTree;
	Node* root = NULL;

	int t;
	int data;

	std::cin >> t;

	while (t-- > 0) {
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	myTree.topView(root);

	return 0;
}
