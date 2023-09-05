#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main () {
	int n;
	cin >> n;
	pair<int,int> *dp = new pair<int,int>[1000001];
	dp[1] = {0,0}; dp[2] = {1,1}; dp[3] = {1,1};
	//dp배열의 i번째에는, first가 연산횟수최솟값, second는 직전값
	for(int i=4;i<=1000000;i++) {
		dp[i] = {dp[i-1].first+1, i-1};
		if (i%3 == 0 && dp[i/3].first + 1 < dp[i].first) dp[i] = {dp[i/3].first + 1, i/3};
		if (i%2 == 0 && dp[i/2].first + 1 < dp[i].first) dp[i] = {dp[i/2].first + 1, i/2};
	}
	printf("%d\n", dp[n].first);
	while (n > 0) {
		printf("%d ", n);
		n = dp[n].second;
	}
}