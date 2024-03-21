#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int dp[31][31];
	for (int i = 1; i <= 30; i++)
	{
		dp[i][1] = 1;
		dp[i][i] = 1;
	}
	for (int i = 2; i < 30; i++)
	{
		for (int j = 2; j < i; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	cout << dp[n][k];
}
/*
	[1][1]
[2][1]  [2][2]

*/