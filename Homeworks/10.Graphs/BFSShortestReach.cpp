#include<iostream>
#include<vector>
#include<list>
using namespace std;

const int EDGE_WEIGHT = 6;

void addEdge(vector<int>* adj, int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printDistances(int* distances, int source, int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (i != source)
		{
			if (distances[i] == 0)
				cout << "-1 ";
			else
				cout << distances[i] << " ";
		}
	}

	cout << endl;
}

void bfs(int source, int n, vector<int>* adj)
{
	bool visited[n + 1];
	int distances[n + 1];

	for (size_t i = 1; i <= n; i++)
	{
		visited[i] = false;
		distances[i] = 0;
	}

	list<int> q;
	q.push_back(source);
	distances[source] = 0;
	visited[source] = true;

	while (!q.empty())
	{
		int s = q.front();

		for (size_t i = 0; i < adj[s].size(); i++)
		{
			if (visited[adj[s][i]] == 0)
			{
				int v = adj[s][i];
				distances[v] = distances[s] + EDGE_WEIGHT;
				visited[v] = 1;
				q.push_back(v);
			}
		}

		q.pop_front();
	}

	printDistances(distances, source, n);
}

int main()
{
	int q;
	cin >> q;

	for (size_t i = 0; i < q; i++)
	{
		int n, m;
		cin >> n >> m;
		vector<int> adj[n + 1];

		int u, v;

		for (size_t i = 0; i < m; i++)
		{
			cin >> u >> v;
			addEdge(adj, u, v);
		}

		int source;
		cin >> source;

		bfs(source, n, adj);
	}
}