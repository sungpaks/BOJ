#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define LL long long

using namespace std;

vector<pair<int, LL>> vertex[100001];
bool visited[100001];
int v;
LL curMax = 0;
int endNode = 0;

void dfs(int cur, LL curDist)
{
	if (curDist > curMax)
	{
		curMax = curDist;
		endNode = cur;
	}
	visited[cur] = true;
	for (int i = 0; i < vertex[cur].size(); i++)
	{
		if (!visited[vertex[cur][i].first])
		{
			dfs(vertex[cur][i].first, vertex[cur][i].second + curDist);
		}
	}
	visited[cur] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> v;
	while (v--)
	{
		int n;
		cin >> n;
		while (true)
		{
			int to;
			cin >> to;
			if (to == -1)
				break;
			LL d;
			cin >> d;
			vertex[n].push_back({to, d});
		}
	}
	dfs(1, 0);
	dfs(endNode, 0);
	cout << curMax;
}