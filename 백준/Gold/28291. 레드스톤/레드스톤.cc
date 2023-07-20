#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

queue< pair<int,int> >lamp; 
queue< pair<int,int> >block; //큐의 first, second는 각각 x,y좌표임
int map[51][51];
int visited[51][51];
int w, h, n;

void dfs(int y, int x, int cnt) {
	if (x < 0 || y < 0 || x >= w || y >= h || cnt <= 0 || map[y][x] <= -1) return;
	//맵 밖을 벗어났거나, 더이상 신호의 강도(cnt)가 남지 않았거나, 해당 좌표가 회로블럭이 아닌 경우(-1)
	if (visited[y][x] >= cnt) return; //또한 이미 방문했고 현재 cnt가 더 크지 않은 경우 
	visited[y][x] = cnt;
	map[y][x] = cnt;
	dfs(y+1, x, cnt-1);
	dfs(y, x+1, cnt-1);
	dfs(y-1, x, cnt-1);
	dfs(y, x-1, cnt-1);
}

bool isOn(int y, int x) {
	//cout << x << y << ":" << map[y][x] << ",";
	if (x < 0 || y < 0 || x >= w || y >= h) return false;
	if (map[y][x] >= 2) return true;
	else return false;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> w >> h;
	cin >> n;
	for(int i=0;i<h;i++) {
		for(int j=0;j<w;j++) {
			map[i][j] = -1;
		}
	}
	for(int i=0;i<n;i++) {
		string in;
		int x, y;
		cin >> in >> x >> y;
		if (in == "redstone_dust") {
			map[y][x] = 0;
		}
		if (in == "redstone_block") {
			map[y][x] = 15;
			block.push(make_pair(y,x));
		}
		if (in == "redstone_lamp") {
			map[y][x] = -2;
			lamp.push(make_pair(y,x));
		}
	}


	while (block.size()) {
		pair<int,int>tmp = block.front();
		block.pop();
		visited[tmp.first][tmp.second] = 15;
		dfs(tmp.first+1, tmp.second, 15);
		dfs(tmp.first-1, tmp.second, 15);
		dfs(tmp.first, tmp.second+1, 15);
		dfs(tmp.first, tmp.second-1, 15);
	}
	/*
	for(int i=0;i<h;i++) {
		for(int j=0;j<w;j++) {
			cout << map[i][j] <<" ";
		}
		cout << "\n";
	}*/
	while (lamp.size()) {
		pair<int,int>tmp = lamp.front();
		lamp.pop();
		if (!isOn(tmp.first+1, tmp.second) && \
			!isOn(tmp.first, tmp.second+1) && \
			!isOn(tmp.first-1, tmp.second) && \
			!isOn(tmp.first, tmp.second-1)) {
				cout << "failed";
				return 0;
			}
	}
	cout << "success";
}