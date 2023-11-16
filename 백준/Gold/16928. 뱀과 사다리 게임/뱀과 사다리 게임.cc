#include <iostream>
#include <queue>
#define INF 2147483647

using namespace std;

int n, m;
int snake[101];
int ladder[101];
int dist[101];

void getMin()
{
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (q.size())
	{
		int cur = q.front();
		q.pop();
		if (snake[cur])
		{
			dist[snake[cur]] = min(dist[snake[cur]], dist[cur]);
			cur = snake[cur];
		}
		else if (ladder[cur])
		{
			dist[ladder[cur]] = min(dist[ladder[cur]], dist[cur]);
			cur = ladder[cur];
		}
		for (int i = 1; i <= 6; i++)
		{
			int next = cur + i;
			if (next <= 100 && dist[next] > dist[cur] + 1)
			{
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	cin.tie(0)->ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i <= 100; i++)
		dist[i] = INF;
	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;
		snake[start] = end;
	}
	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;
		ladder[start] = end;
	}
	getMin();
	cout << dist[100];
}