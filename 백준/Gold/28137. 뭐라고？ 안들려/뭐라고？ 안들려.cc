#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#define INF 2147483647

using namespace std;

map<long long, int>points;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int k;
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		int x, y;
		cin >> x >> y;
		points[y-(long long)k*x]++;
	}
	long long cnt = 0;
	for(auto it = points.begin(); it != points.end(); it++) {
		//if (it->second <= 0) continue;
		cnt += (long long)(it->second)*(it->second - 1);
	}
	cout << cnt;
}

/*
y - K*x
*/