#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char campus[601][601];
bool visited[601][601];
int n, m;

int bfs(int start_i, int start_j)
{
	int r = 0;
	queue<pair<int,int>>q;
	q.push({start_i, start_j});
	visited[start_i][start_j] = true;
	int di[4] = {1, 0, -1, 0};
	int dj[4] = {0, 1, 0, -1};
	while (q.size())
	{
		int curi = q.front().first;
		int curj = q.front().second;
		q.pop();
		if (campus[curi][curj] == 'P') r++;
		for(int i=0;i<4;i++) {
			int nexti = curi+di[i], nextj = curj+dj[i];
			if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < m &&
				 !visited[nexti][nextj] && campus[nexti][nextj] != 'X') {
				q.push({nexti, nextj});
				visited[nexti][nextj] = true;
			}
		}
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int start_i=0, start_j=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin >> campus[i][j];
			if (campus[i][j] == 'I') 
			{
				start_i = i;
				start_j = j;
			}
		}
	}
	int cnt = bfs(start_i, start_j);
	if (!cnt) cout << "TT";
	else cout << cnt;
}