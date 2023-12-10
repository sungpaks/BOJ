#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<pair<int, long long>> node[1001];
bool visited[1001];

void dfs(int cur, int dst, long long dist)
{
	if (visited[cur])
		return;
	if (cur == dst)
	{
		cout << dist << "\n";
		return;
	}
	visited[cur] = true;
	for (int i = 0; i < node[cur].size(); i++)
	{
		dfs(node[cur][i].first, dst, dist + node[cur][i].second);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		long long w;
		cin >> u >> v >> w;
		node[u].push_back({v, w});
		node[v].push_back({u, w});
	}
	for (int i = 0; i < m; i++)
	{
		memset(visited, 0, 1001);
		int start, end;
		cin >> start >> end;
		dfs(start, end, 0);
	}
}