#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int adjArray[20001][20001];
int visited[20001];
int maxDist = 0;
int maxCnt = 0;

void bfs(int n) {
    queue<int>q;
    q.push(1);
    visited[1] = 1;
    while(q.size()) {
        int cur = q.front();
        q.pop();
        //if (visited[cur]) continue;
        for(int i=1;i<=n;i++) {
            if(adjArray[cur][i] && (visited[i] > visited[cur]+1 || !visited[i])) {
                q.push(i);
                visited[i] = visited[cur]+1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (int i=0;i<edge.size();i++) {
        adjArray[edge[i][0]][edge[i][1]] = 1;
        adjArray[edge[i][1]][edge[i][0]] = 1;
    }
    bfs(n);
    for(int i=1;i<=n;i++) {
        if (maxDist < visited[i]) {
            maxDist = visited[i];
            answer = 1;
        }
        else if (maxDist == visited[i]) answer++;
    }
    return answer;
}