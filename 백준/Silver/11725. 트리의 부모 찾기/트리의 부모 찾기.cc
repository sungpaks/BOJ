#include <iostream>
#include <vector>
using namespace std;

vector<int>v[100001];
int parent[100001] = {0};

void check(int current);

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	parent[1] = 1;
	//a, b가 나오면, 노드 a의 벡터에 같이 나온 b를 적을거임
	//b에도 똑같이
	//그럼 큐에 push하듯이 하면
	for(int i=0;i<n-1;i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		//push_back : 맨 뒤에 값을 넣음 : 큐like
	}
	check(1);
	for(int i=2;i<=n;i++){
		cout << parent[i] << "\n";
	}
}

//처음 나오면, 같이 나온 숫자가 부모
//--> 해당 인덱스에 부모 넣음

void check(int current)
{ //n에서부터, 자기가 갖고있는 노드들의 부모를 자신으로 함
//맨 밑까지 왔으면, 끝
	if (v[current].size() == 1 && parent[v[current].back()]) {
		parent[current] = v[current].back();
		return;
	} // 맨 밑이면 끝임
	// while (v[current].empty() == false){
	// 	if (parent[node] == 0) {
	// 		parent[node] = current;
	// 		check(node, n);
	// 	}
	// 	v[current].pop_back();
	// }
	for(int i=0;i<(int)v[current].size();i++){
		int node = v[current][i];
		if (parent[node]==0)
		{
			parent[node] = current;
			check(node);
		}
	}
	//그게 아니면 밑으로 내려가봄
}