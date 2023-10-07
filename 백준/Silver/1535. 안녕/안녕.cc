#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int dp[101];
// first : weight, second : value
bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first == p2.first)
	{
		return p1.second > p2.second;
	}
	else
		return p1.first < p2.first;
}
int main()
{
	int n;
	cin >> n;
	int L[21];
	int J[21];
	for (int i = 0; i < n; i++)
	{
		cin >> L[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> J[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 100; j >= L[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
		}
	}
	cout << dp[99];
}