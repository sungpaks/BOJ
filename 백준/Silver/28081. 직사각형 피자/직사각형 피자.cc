#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long w, h, k;
	cin >> w >> h >> k;
	int n;
	cin >> n;
	vector<long long>y;
	vector<long long>tmpy(n);
	for(int i=0;i<n;i++) {
		cin >> tmpy[i];
		if (i == 0) y.push_back(tmpy[i]);
		else y.push_back(tmpy[i] - tmpy[i-1]);
	}
	y.push_back(h-tmpy.back());
	int m;
	cin >> m;
	vector<long long>x;
	vector<long long>tmpx(m);
	for(int i=0;i<m;i++) {
		cin >> tmpx[i];
		if (i == 0) x.push_back(tmpx[i]);
		else x.push_back(tmpx[i] - tmpx[i-1]);
	}
	x.push_back(w - tmpx.back());
	long long cnt = 0;
	sort(y.begin(), y.end());
	for(int i=0;i< x.size();i++) {
		long long left = 0;
		long long right = y.size()-1;
		while (left <= right) {
			long long mid = (left+right)/2;
			if (x[i] * y[mid] > k) right = mid - 1;
			else left = mid + 1;
		}
		cnt += left;
	}
	cout << cnt;
}