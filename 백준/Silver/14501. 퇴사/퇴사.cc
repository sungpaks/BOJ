#include <iostream>

using namespace std;

pair<int,int>t_and_p[20];
int dp[30];

int main () {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        int t, p;
        cin >> t >> p;
        t_and_p[i] = make_pair(t,p);
    }
    dp[0] = 0;
    for(int i=1;i<=n;i++) {
        int t_i = t_and_p[i].first;
        int p_i = t_and_p[i].second;
        dp[i+1] = max(dp[i+1], dp[i]);
        dp[i+t_i] = max(dp[i] + p_i, dp[i+t_i]);
       // if (!dp[i]) dp[i] = dp[i-1];
    }
    cout << dp[n+1];
}