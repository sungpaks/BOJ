#include <iostream>
#include <queue>
using namespace std;

typedef struct info {
	int x, y, z, d;
}info;

int map[101][101][101];
//bool visited[101][101][101];
int m,n,h;
int maxDay = 0;

queue<info>q;
void tomato() {
	int dx[6] = { 1, -1, 0, 0, 0, 0 };
	int dy[6] = { 0, 0, 1, -1, 0, 0 };
	int dz[6] = { 0, 0, 0, 0, 1, -1 };
	while (q.size()) {
		info curInfo = q.front();
		q.pop();
		int x = curInfo.x;
		int y = curInfo.y;
		int z = curInfo.z;
		if (curInfo.d > maxDay) maxDay = curInfo.d;
		for(int i=0;i<6;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx < 0 || ny < 0 || nz < 0 || nz >= h || ny >= m || nx >= n) continue;
			if (map[nx][ny][nz] == 0) {
				map[nx][ny][nz] = 1;
				q.push({nx,ny,nz,curInfo.d+1});
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n >> h;
	for(int k=0;k<h;k++) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push({i,j,k,0});
					//visited[i][j][k] = true;
				}
			}
		}
	}
	tomato();
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			for(int k=0;k<h;k++) {
				if (map[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << maxDay;
}