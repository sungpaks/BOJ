#include <iostream>
#include <queue>
#define INF 1000000
#define END 100000

using namespace std;

int d[100002];
int a, b, n, m;

void bfs()
{
	queue<int> q;
	q.push(n);
	d[n] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur + 1 <= END && d[cur + 1] > d[cur] + 1)
		{
			d[cur + 1] = d[cur] + 1;
			q.push(cur + 1);
		}
		if (cur - 1 >= 0 && d[cur - 1] > d[cur] + 1)
		{
			d[cur - 1] = d[cur] + 1;
			q.push(cur - 1);
		}
		if (cur - a >= 0 && d[cur - a] > d[cur] + 1)
		{
			d[cur - a] = d[cur] + 1;
			q.push(cur - a);
		}
		if (cur + a <= END && d[cur + a] > d[cur] + 1)
		{
			d[cur + a] = d[cur] + 1;
			q.push(cur + a);
		}
		if (cur - b >= 0 && d[cur - b] > d[cur] + 1)
		{
			d[cur - b] = d[cur] + 1;
			q.push(cur - b);
		}
		if (cur + b <= END && d[cur + b] > d[cur] + 1)
		{
			d[cur + b] = d[cur] + 1;
			q.push(cur + b);
		}
		if (cur * a <= END && d[cur * a] > d[cur] + 1)
		{
			d[cur * a] = d[cur] + 1;
			q.push(cur * a);
		}
		if (cur * b <= END && d[cur * b] > d[cur] + 1)
		{
			d[cur * b] = d[cur] + 1;
			q.push(cur * b);
		}
	}
}

int main()
{
	cin >> a >> b >> n >> m;
	for (int i = 0; i <= END; i++)
		d[i] = INF;
	bfs();
	cout << d[m];
}