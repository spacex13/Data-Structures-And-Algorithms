#include<iostream>
#include<vector>
#include<list> 
#include<algorithm> 
using namespace std;

int nodeCount = 0;
vector<int> nodeGroups;

void addEdge(vector<int>* adj, int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void DFSUtil(vector<int>* adj, int v, bool visited[])
{
	visited[v] = true;
	nodeCount++;

	vector<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); i++)
	{
		if (!visited[*i])
		{
			DFSUtil(adj, *i, visited);
		}
	}
}

void connectedComponents(vector<int>* adj, int V)
{
	bool *visited = new bool[V + 1];

	for (int v = 0; v < V; v++)
		visited[v] = false;

	for (int v = 0; v < V; v++)
	{
		if (visited[v] == false)
		{
			nodeCount = 0;

			DFSUtil(adj, v, visited);

			if (nodeCount > 1)
				nodeGroups.push_back(nodeCount);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> adj[2 * n];

	int u, v;

	for (size_t i = 0; i < n; i++)
	{
		cin >> u >> v;
		addEdge(adj, u, v);
	}

	connectedComponents(adj, 2 * n);

	sort(nodeGroups.begin(), nodeGroups.end());

	cout << nodeGroups.front() << " " << nodeGroups.back() << endl;
}