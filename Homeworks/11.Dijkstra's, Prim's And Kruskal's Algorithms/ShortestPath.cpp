#include<iostream>
#include<list>
#include<queue>
#include <climits>
using namespace std;
# define INF LLONG_MAX

vector<pair<int, long long>> *adj;

void addEdge(int u, int v, long long w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

void dijkstraShortestPath(int s, int n)
{
	vector<long long> dist;
	vector<int> p;

	dist.assign(n, INF);
	p.assign(n, -1);

	vector<bool> visited(n, false);

	dist[s] = 0;

	for (int i = 1; i < n; i++)
	{
		int u = -1;

		for (int j = 1; j < n; j++)
		{
			if (!visited[j] && (u == -1 || dist[j] < dist[u]))
				u = j;
		}

		if (dist[u] == INF)
			break;

		visited[u] = true;

		vector<pair<int, long long>>::iterator it;

		for (it = adj[u].begin(); it != adj[u].end(); it++)
		{
			int v = (*it).first;
			long long w = (*it).second;

			if (dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				p[v] = v;
			}
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (dist[i] != INF && i != s)
			cout << dist[i] << " ";
		else if (i != s && dist[i] == INF)
			cout << "-1 ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;

	for (size_t i = 0; i < t; i++)
	{
		int n, m;

		cin >> n >> m;
		adj = new vector<pair<int, long long>>[n + 1];

		long long u, v, w;
		for (size_t i = 0; i < m; i++)
		{
			cin >> u >> v >> w;
			addEdge(u, v, w);
		}

		int s;
		cin >> s;

		dijkstraShortestPath(s, n + 1);
		cout << endl;
	}
}