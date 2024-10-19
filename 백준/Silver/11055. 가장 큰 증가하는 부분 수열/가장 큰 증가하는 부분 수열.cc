#include <iostream>

using namespace std;

int dp[1001];
int num[1001];
int n;

int main () {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> num[i];
    }
    dp[0]=num[0];
    int result = dp[0];
    for(int i=1;i<n;i++) {
        dp[i] = num[i];
        for(int j=0;j<i;j++) {
            if (num[i] <= num[j]) continue;
            dp[i] = max(dp[j]+num[i], dp[i]);
        }
        if (dp[i] > result) result = dp[i];
    }
    cout << result;
}
