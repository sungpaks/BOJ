#include <iostream>
#include <vector>

using namespace std;

int n, m;
int result = 0;
int map[501][501];
bool visited[501][501];
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

void dfs(int i, int j, int cnt, int curSum)
{
	if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j])
		return;
	curSum += map[i][j];
	if (cnt == 3)
	{
		if (curSum > result)
			result = curSum;
		return;
	}
	visited[i][j] = true;
	for (int k = 0; k < 4; k++)
	{
		int ni = i + di[k];
		int nj = j + dj[k];
		dfs(ni, nj, cnt + 1, curSum);
	}
	visited[i][j] = false;
}
void checkT(int i, int j)
{
	int sum = map[i][j];
	if (j + 2 < m)
	{
		int sum1 = sum + map[i][j + 1] + map[i][j + 2];
		int sum2 = sum1;
		if (i + 1 < n)
			sum1 += map[i + 1][j + 1];
		if (i - 1 >= 0)
			sum2 += map[i - 1][j + 1];
		int larger = sum1 > sum2 ? sum1 : sum2;
		if (result < larger)
			result = larger;
	}
	if (i + 2 < n)
	{
		int sum1 = sum + map[i + 1][j] + map[i + 2][j];
		int sum2 = sum1;
		if (j + 1 < m)
			sum1 += map[i + 1][j + 1];
		if (j - 1 >= 0)
			sum2 += map[i + 1][j - 1];
		int larger = sum1 > sum2 ? sum1 : sum2;
		if (result < larger)
			result = larger;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dfs(i, j, 0, 0);
			checkT(i, j);
		}
	}
	cout << result;
}