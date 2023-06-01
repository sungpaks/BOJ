#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<int>>v(501, vector<int>(501));

int narasi(int curH);

int n, m, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
/*
땅의 최솟값과 최댓값을 찾고,
최대 최소 같아질 때까지,
전체 칸에 대해 + 또는 - 진행
둘 중 하나만 해도 되면, 시간 짧게 걸리는 쪽 선택
둘 다 해도 최소높이 최대높이가 아직 차이나면 계속 ㄱㄱ
*/
	cin >> n >> m >> b;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin >> v[i][j];
		}
	}
	int minTime = narasi(0);
	int minH = 0; //0으로 가려면 무조건 부숴야해서 ㄱㅊ
	for(int i=1;i<=256;i++) {
		int curTime = narasi(i);
		if (curTime == -1) continue;
		else if (curTime <= minTime) {
			minTime = curTime;
			minH = i;
		}
	}
	cout << minTime << " " << minH;
}

int narasi(int curH) {
	int t = 0;
	int blocks = b;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (v[i][j] > curH) {
				int destroy = v[i][j] - curH;
				//높으면, 부순다 : 2초 * 높이차이
				t += destroy * 2;
				blocks += destroy;
			}
			else if (v[i][j] < curH) {
				//낮으면, 설치한다 : 1초씩
				int build = curH - v[i][j];
				t += build;
				blocks -= build;
			}
		}
	}
	if (blocks >= 0) return t; //블록 수 괜찮으면, 그대로 반환
	else return -1; //블록 수 부족하면, -1
}