#include <iostream>
#include <algorithm>
#define INF 1000 * 1000 + 1

using namespace std;

int cost[1001][3];
int dp[1001][3];
int n;
int result = INF;

void makeDP(int st)
{
	for (int i = 0; i < 3; i++)
	{
		if (i == st)
			dp[0][st] = cost[0][st];
		else
			dp[0][i] = INF;
	}
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = min(dp[i - 1][1] + cost[i][0], dp[i - 1][2] + cost[i][0]);
		dp[i][1] = min(dp[i - 1][0] + cost[i][1], dp[i - 1][2] + cost[i][1]);
		dp[i][2] = min(dp[i - 1][0] + cost[i][2], dp[i - 1][1] + cost[i][2]);
	}
	for (int j = 0; j < 3; j++)
	{
		if (j != st)
			result = min(result, dp[n - 1][j]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	makeDP(0);
	makeDP(1);
	makeDP(2);
	cout << result;
}