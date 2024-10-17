#include <iostream>

using namespace std;
int dp[101][10];
int division = 1000000000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n = 0;
	cin >> n;
	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		dp[i + 1][0] = (dp[i][1]) % division;
		dp[i + 1][9] = (dp[i][8]) % division;
		for (int j = 1; j < 9; j++)
		{
			dp[i + 1][j] = (dp[i][j - 1] + dp[i][j + 1]) % division;
		}
	}
	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		result = (result + dp[n][i]) % division;
	}
	cout << result;
}
// 10,  12
// 21,  23
// 32,  34
// 43,  45
// 54,  56
// 65,  67
// 76,  78
// 87,  89
// 98,
// dp[2][0] = 1,
// dp[2][1] = 2,
// dp[2][2] = 2,
// dp[2][3] = 2,
// dp[2][4] = 2,
// dp[2][5] = 2,
// dp[2][6] = 2,
// dp[2][7] = 2,
// dp[2][8] = 2,
// dp[2][9] = 2,

// 101, 121, 123, 210, 212, 232, 234, 321, 323, 343, 345,
// 	432, 434, 454, 456, 543, 545, 565, 567, 654, 656, 676, 678, 765, 767, 787, 789,
// 	876, 878, 898, 987, 989

// 2*dp[i-1]-i-1인가?
// dp[3] = 32