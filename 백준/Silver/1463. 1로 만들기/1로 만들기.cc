#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *dp = new int[n+1];
	dp[1] = 0;
	int cnt = 0;
	for(int i=2;i<=n;i++) {
		//i로 넘어오는 경우는, i-1에서 건너왔거나, i/2에서 건너왔거나, i/3에서 건너왔거나
		//세 가지 경우 중 최솟값을 dp에
		dp[i] = dp[i-1]+1;
		if (i%3 == 0 && dp[i] > dp[i/3]+1) dp[i] = dp[i/3]+1;
		if (i%2 == 0 && dp[i] > dp[i/2]+1) dp[i] = dp[i/2]+1;
	}
	cout << dp[n];
}