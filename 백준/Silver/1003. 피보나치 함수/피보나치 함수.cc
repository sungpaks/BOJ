#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int zero, one;
pair<int,int>dp[41];

void setDP() {
	dp[0] = make_pair(1, 0);
	dp[1] = make_pair(0, 1);
	for(int i=2;i<=40;i++) {
		dp[i].first = dp[i-1].first + dp[i-2].first;
		dp[i].second = dp[i-1].second + dp[i-2].second;
	}
}

int fibonacci(int n) {
	if (n == 0) {
		zero++;
		return 0;
	}
	else if (n == 1) {
		one++;
		return 0;
	}
	else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	setDP();
	for(int i=0;i<t;i++) {
		int n;
		cin >> n;
		cout << dp[n].first << " " << dp[n].second <<"\n";
	}
}

/*
3 : 1 2
4 : 3과 2로 나뉘니까.. 2 3
5 : 4와 3으로 나뉘니까.. 3 5
6 : 5와 4로 나뉘니까.. 5 8
*/