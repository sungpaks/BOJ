#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int>v[27];
vector<int>checked(27);
stack<char>s;
queue<char>q;

void preorder(int current);
void inorder(int current);
void postorder(int current);
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		char p, l, r; // 입력은 부모 노드, 왼쪽 자식 노드, 오른쪽 자식 노드 순
		cin >> p >> l >> r;
		v[p - 'A'].push_back(l);
		v[p - 'A'].push_back(r);
	}
	preorder(0);
	cout << "\n";
	inorder(0);
	while (!(q.empty()))
	{
		cout << q.front();
		q.pop();
	}
	cout <<"\n";
	postorder(0);
	while (!(q.empty()))
	{
		cout << q.front();
		q.pop();
	}
}
//기본적으로 이동은 왼쪽 우선으로 쭉 들어갔다가, 돌아오면 오른쪽
void preorder(int current)
{ //이동할 때마다 노드 출력
	cout << (char)(current + 'A');
	if (v[current][0] == '.' && v[current][1] == '.') return;
	if (v[current][0] != '.') preorder(v[current][0] - 'A');
	if (v[current][1] != '.')preorder(v[current][1] - 'A');
}

void inorder(int current)
{//엣지에 왔거나, 한 번 거슬러 올라갈 때 큐에 넣음
	if (v[current][0] == '.' && v[current][1] == '.') 
	{
		q.push((char)(current + 'A'));
		return;
	}
	if (v[current][0] != '.') inorder(v[current][0] - 'A');
	q.push((char)(current + 'A'));
	if (v[current][1] != '.') inorder(v[current][1] - 'A');
}

void postorder(int current)
{ //끝까지 내려가면 큐에 넣고, 자식을 모두 참조한 경우 큐에 넣음
	if (v[current][0] == '.' && v[current][1] == '.') {
		q.push((char)(current + 'A'));
		return;
	}
	if (v[current][0] != '.') postorder(v[current][0] - 'A');
	if (v[current][1] != '.') postorder(v[current][1] - 'A');
	q.push((char)(current + 'A'));
}