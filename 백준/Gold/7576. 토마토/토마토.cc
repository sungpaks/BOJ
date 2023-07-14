#include <iostream>
#include <queue>
using namespace std;

typedef struct info {
	int x, y, d;
}info;

int map[1001][1001];
//bool visited[101][101][101];
int m,n;
int maxDay = 0;

queue<info>q;
void tomato() {
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	while (q.size()) {
		info curInfo = q.front();
		q.pop();
		int x = curInfo.x;
		int y = curInfo.y;
		if (curInfo.d > maxDay) maxDay = curInfo.d;
		for(int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 0) {
				map[nx][ny] = 1;
				q.push({nx,ny,curInfo.d+1});
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({i,j,0});
				//visited[i][j][k] = true;
			}
		}
	}
	tomato();
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (map[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << maxDay;
}