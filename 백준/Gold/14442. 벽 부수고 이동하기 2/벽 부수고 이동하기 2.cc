#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct info {
	int y, x, d, breaked;
}info;

int map[1001][1001];
bool visited[1001][1001][11];
int n, m, k;

void move() {
	queue<info>q;
	q.push({0,0,1,0});
	visited[0][0][0] = true;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1};
	//벽이 아닌데 현 상태에서 가본적없거나,
	//벽인데 k번보다 적게 부순 상태인 경우
	while (q.size()) {
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().d;
		int breaked = q.front().breaked;
		q.pop();
		if (x == m-1 && y == n-1) {
			printf("%d", d);
			return;
		}
		//cout <<y<<x<<d<<breaked<<" ";
		for(int i=0;i<4;i++) {
			int nx = x+dx[i], ny = y+dy[i];
			if (nx >= m || ny >= n || nx < 0 || ny < 0) continue;
			if (map[ny][nx] == 1) {
				//벽인경우,
				if (breaked < k && !visited[ny][nx][breaked+1]) {
					q.push({ny,nx,d+1,breaked+1});
					visited[ny][nx][breaked+1] = true;
				}
			}
			else {
				//벽이 아닌 경우,
				if (!visited[ny][nx][breaked]) {
					q.push({ny,nx,d+1,breaked});
					visited[ny][nx][breaked] = true;
				}
			}
		}
	}
	printf("-1");
}

int main () {
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	move();
}