#include <stdio.h>

int array[501][501];
int dp[501][501];

int max(int a, int b) {
	return a > b ? a : b;
}

int main () {
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=i;j++) {
			scanf("%d", &array[i][j]);
		}
	}
	dp[1][1] = array[1][1];
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=i;j++) {
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]+array[i+1][j]);
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+array[i+1][j+1]);
		}
	}
	int result = dp[n][1];
	for(int i=1;i<=n;i++) {
		result = max(result, dp[n][i]);
	}
	printf("%d",result);
}