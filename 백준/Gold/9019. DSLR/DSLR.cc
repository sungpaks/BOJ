#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int D(int n)
{
	return (2 * n) % 10000;
}
int S(int n)
{
	return (n == 0 ? 9999 : n - 1);
}
int L(int n)
{
	int d[5];
	for (int i = 4; i >= 1; i--)
	{
		d[i] = n % 10;
		n /= 10;
	}
	return (d[2] * 1000 + d[3] * 100 + d[4] * 10 + d[1]);
}
int R(int n)
{
	int d[5];
	for (int i = 4; i >= 1; i--)
	{
		d[i] = n % 10;
		n /= 10;
	}
	return (d[4] * 1000 + d[1] * 100 + d[2] * 10 + d[3]);
}

void AtoB(int a, int b)
{
	queue<int> q;
	string visited[10000];
	q.push(a);
	while (q.size())
	{
		int cur = q.front();
		q.pop();
		if (cur == b)
		{
			cout << visited[cur] << "\n";
			return;
		}
		int d = D(cur);
		int s = S(cur);
		int l = L(cur);
		int r = R(cur);
		if (visited[d] == "" || visited[d].length() > visited[cur].length() + 1)
		{
			if (cur != d)
			{
				visited[d] = visited[cur] + "D";
				q.push(d);
			}
		}
		if (visited[s] == "" || visited[s].length() > visited[cur].length() + 1)
		{
			if (cur != s)
			{
				visited[s] = visited[cur] + "S";
				q.push(s);
			}
		}
		if (visited[l] == "" || visited[l].length() > visited[cur].length() + 1)
		{
			if (cur != l)
			{
				visited[l] = visited[cur] + "L";
				q.push(l);
			}
		}
		if (visited[r] == "" || visited[r].length() > visited[cur].length() + 1)
		{
			if (cur != r)
			{
				visited[r] = visited[cur] + "R";
				q.push(r);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		AtoB(a, b);
	}
}