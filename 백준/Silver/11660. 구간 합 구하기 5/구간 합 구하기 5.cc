#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int map[1025][1025];

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			int tmp;
			cin >> tmp;
			if (j > 0) {
				tmp += map[i][j-1];
			}
			map[i][j] = tmp;
		}
	}
	/*
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}*/

	for(int i=0;i<m;i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		int cumSum = 0;
		x1--, x2--, y1--, y2--;
		for(int k=y1; k<=y2;k++) {
			if (x1 == 0) cumSum += map[k][x2];
			else cumSum += map[k][x2] - map[k][x1-1];
		}
		cout << cumSum << "\n";
	}
}