#include <iostream>

using namespace std;

int dp[2][100001];
int score[2][100001];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> score[0][i];
			dp[0][i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> score[1][i];
			dp[1][i] = 0;
		}
		dp[0][0] = score[0][0];
		dp[1][0] = score[1][0];
		for (int i = 1; i < n; i++)
		{
			dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + score[0][i]);
			dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + score[1][i]);
		}
		int result = max(dp[0][n - 1], dp[1][n - 1]);
		cout << result << "\n";
	}
}