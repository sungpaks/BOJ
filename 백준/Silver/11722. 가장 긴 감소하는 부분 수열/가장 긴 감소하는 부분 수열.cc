#include <iostream>

using namespace std;

int n;
int num[1001];
int dp[1001];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> num[i];
        dp[i] = 1;
    }
    int result = 1;
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if (num[i] >= num[j]) continue;
            dp[i] = max(dp[i], dp[j]+1);
        }
        if (result < dp[i]) result = dp[i];
    }
    cout << result;
}
