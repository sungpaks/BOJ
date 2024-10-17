#include <iostream>

using namespace std;

int wine[10001];
int dp[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> wine[i];
	}
	dp[0] = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], max(dp[i - 2] + wine[i], dp[i - 1]));
	}
	cout << dp[n];
}

/*
X _ O O : dp[i-3], wine[i-1], wine[i]를 먹는다
X O _ O : dp[i-2], wine[i]를 먹는다
X O O _ : dp[i-1]에서 wine[i]안먹고 지나간다
*/