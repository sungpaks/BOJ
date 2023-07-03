#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

//int result = 0;
int dp[50001] = {0};
void getDP(int n)
{
	for(int i=1;i*i<=n;i++) {
		if (dp[n] == 0) dp[n] = dp[i*i] + dp[n-i*i];
		else dp[n] = min(dp[n], dp[i*i] + dp[n-i*i]);
	}
}

int main () {
	int n;
	cin >> n;
	/*
	int a[4];
	int t = 0;
	int num = n;
	while (num > 0)
	{
		num = n;
		int a[4] = {0};

		a[0] = (int)sqrt(num) - t;
		num -= a[0] * a[0];
		for(int i=1;i<4;i++) {
		a[i] = (int)sqrt(num);
		num -= a[i]*a[i];
		}
		t++;
	}
	int cnt = 0;
	for(int i=0;i<4;i++) {
		if (a[i] != 0) cnt++;
		//cout << a[i] << " ";
	}
	//cout << "\n";
	cout<<cnt;
	*/
	for(int i=1;i*i<=n;i++) dp[i*i] = 1; //제곱수들은 모두 1로하고,
	for(int i=1;i<=n;i++) {
		if (!dp[i]) getDP(i);
	}//제곱수가 아닌 자연수들은 점화식에 대입
	cout << dp[n];
}