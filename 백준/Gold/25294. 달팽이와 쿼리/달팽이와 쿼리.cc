#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int query1(int n, int x, int y) {
	//이 함수에서 x는 가로, y는 세로
	//n X n 달팽이배열에서 x, y좌표에 있는 수를 찾는다
	if (y == 1) return x;
	if (x == n/2+1 && y == n/2+1) return n*n;
	int cur = n;
	int curX = n, curY = 1;
	int flag = 0;
	int i = 1;
	while (1) {
		if (curX == x) {
			cur += y - curY;
			return cur;
		}
		curY += n-i;
		cur += n-i;
		if (curY == y) {
			cur += curX - x;
			return cur;
		}
		curX -= n-i;
		cur += n-i;
		i++;
		if (curX == x) {
			cur += curY - y;
			return cur;
		}
		curY -= n-i;
		cur += n-i;
		if (curY == y) {
			cur += x - curX;
			return cur;
		}
		curX += n-i;
		cur += n-i;
		i++;
	}
}

void query2(int n, int z) {
	if (z <= n) {
		cout << "1 " << z << "\n";
		return;
	}
	if (z == n*n) {
		cout << n/2+1 << " " << n/2+1 << "\n";
		return;
	}
	int cur = n;
	int curX = n, curY = 1;
	int flag = 0;
	int i = 1;
	while (1) {
		if (cur + n-i >= z) {
			curY += z - cur;
			cout << curY << " " << curX << "\n";
			return;
		}
		curY += n-i;
		cur += n-i;
		if (cur + n-i >= z) {
			curX -= z - cur;
			cout << curY << " " << curX << "\n";
			return;
		}
		curX -= n-i;
		cur += n-i;
		i++;
		if (cur + n-i >= z) {
			curY -= z - cur;
			cout << curY << " " << curX << "\n";
			return;
		}
		curY -= n-i;
		cur += n-i;
		if (cur + n-i >= z) {
			curX += z - cur;
			cout << curY << " " << curX << "\n";
			return;
		}
		curX += n-i;
		cur += n-i;
		i++;
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> q;
	for(int i=0;i<q;i++) {
		int t;
		cin >> t;
		if (t == 1) {
			//n, x, y 쿼리
			int n, x, y;
			cin >> n >> x >> y;
			cout << query1(n,y,x) << "\n";
		}
		else if (t == 2) {
			//n, z 쿼리
			int n, z;
			cin >> n >> z;
			query2(n,z);
		}
	}
}