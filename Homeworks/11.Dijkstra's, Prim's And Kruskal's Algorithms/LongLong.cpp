#include<iostream> 
#include<limits.h> 
#include<list> 
#include<stack> 
#include<list>
using namespace std;

list<pair<int, long long>>* adj;

void topologicalSort(int v1, bool visited[], stack<long long>& st)
{
	visited[v1] = true;

	list<pair<int, long long>>::iterator i;

	for (i = adj[v1].begin(); i != adj[v1].end(); i++)
	{
		int v2 = (*i).first;

		if (!visited[v2])
			topologicalSort(v2, visited, st);
	}

	st.push(v1);
}

long long longestPath(int s, int t, int n)
{
	stack<long long> st;
	long long dist[1000];

	bool* visited = new bool[1000];

	for (int i = 1; i <= n; i++)
		visited[i] = false;

	for (int i = 1; i <= n; i++)
		if (visited[i] == false)
			topologicalSort(i, visited, st);

	for (int i = 1; i <= n; i++)
		dist[i] = INT_MIN;

	dist[s] = 0;

	while (!st.empty())
	{
		int v1 = st.top();
		st.pop();

		list<pair<int, long long>>::iterator i;

		if (dist[v1] != INT_MIN)
		{
			for (i = adj[v1].begin(); i != adj[v1].end(); ++i)
			{
				int v2 = (*i).first;
				int w = (*i).second;

				if (dist[v2] < dist[v1] + w)
					dist[v2] = dist[v1] + w;
			}
		}
	}

	if (dist[t] == INT_MIN)
		return -1;

	return dist[t];
}

int main()
{
	int n, m, s, t;
	cin >> n >> m >> s >> t;

	adj = new list<pair<int, long long>>[n + 1];

	int v1, v2;
	long long w;

	for (size_t i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> w;
		adj[v1].push_back(make_pair(v2, w));
	}

	long long result = longestPath(s, t, n);
	cout << result << endl;
}