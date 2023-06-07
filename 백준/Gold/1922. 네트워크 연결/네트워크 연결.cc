#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct lines {
	int node1, node2, cost;
	lines(int a, int b, int c) { //생성자
		this->node1 = a;
		this->node2 = b;
		this->cost = c;
	}
	bool operator<(const lines l) const { //비교연산자오버로딩
		return this->cost > l.cost;
	}
}lines;

vector<bool> visited(1001, false);
vector<int> parent(1001);

int findParent (int x);
void unionParent(int a, int b);

int n, m;
priority_queue<lines>pq;
int kruskal();

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	cin >> m;
	for(int i=0;i<m;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push(lines(a,b,c));
		parent[a] = a;
		parent[b] = b;
	}
	cout << kruskal();
}

int kruskal()
{
	int cnt = 0;
	long long sum = 0;
	while (!(pq.empty())) { //n개의 정점을 모두 연결하려면 n-1개 간선이 필요
		lines current = pq.top();
		pq.pop();
		//부모가 같은 놈을 이으면 안됩니다 findParent
		if (findParent(current.node1) == findParent(current.node2)) continue;
		unionParent(current.node1, current.node2);
		//잇고 나면 부모는 둘 중 하나로 통일
		sum += (long long)current.cost;
		
		cnt++;
	}
	return sum;
}

int findParent (int x) {
	if (parent[x] == x) return x;
	else return parent[x] = findParent(parent[x]);
}
void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a != b) parent[a] = b;
}
