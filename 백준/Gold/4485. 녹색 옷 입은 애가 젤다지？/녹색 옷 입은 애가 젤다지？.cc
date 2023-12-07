#include <iostream>
#include <queue>
#define INF 200000

using namespace std;

int n;
int adjArray[126][126];
int d[126][126];
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

void dijkstra()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			d[i][j] = INF;
		}
	}
	d[0][0] = adjArray[0][0];
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({-d[0][0], {0, 0}});
	while (pq.size())
	{
		pair cur = pq.top().second;
		int cost = -1 * pq.top().first;
		pq.pop();
		for (int k = 0; k < 4; k++)
		{
			int ni = cur.first + di[k];
			int nj = cur.second + dj[k];
			if (ni < 0 || ni >= n || nj < 0 || nj >= n)
				continue;
			int nCost = cost + adjArray[ni][nj];
			if (d[ni][nj] > nCost)
			{
				d[ni][nj] = nCost;
				pq.push({-nCost, {ni, nj}});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cnt = 0;
	while (++cnt)
	{
		cin >> n;
		if (!n)
			return 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> adjArray[i][j];
			}
		}
		dijkstra();
		cout << "Problem " << cnt << ": " << d[n - 1][n - 1] << "\n";
	}
}