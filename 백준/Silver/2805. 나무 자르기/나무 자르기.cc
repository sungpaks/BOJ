#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<long long>v;
/*
H설정
처음 : (0 + max) / 2
목표보다 적으면, 더 잘라야하니까 H를 내림 : top = H-1.
목표보다 크면, 좀 덜 잘라야하니까 H를 올림 : bottom = H+1.
*/
void setH(long long top, long long bottom);

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	long long max = 0;
	for(int i=0;i<n;i++) {
		long long tmp;
		cin >> tmp;
		v.push_back(tmp);
		if (tmp > max) max = tmp;
	}
	setH(max, 0);
}

void setH(long long top, long long bottom) {
	if (top < bottom) {
		cout << (top+bottom)/2;
		return;
	}
	long long curH = (top + bottom)/2;
	long long sumOfLength = 0;
	for(int i=0;i<n;i++) {
		if (v[i] - curH > 0) sumOfLength+=v[i]-curH;
	}
	if (sumOfLength < m) setH(curH-1, bottom);
	else if (sumOfLength > m) setH(top, curH + 1);
	else cout << curH;
}