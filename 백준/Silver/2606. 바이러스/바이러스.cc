#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>computer[101];
vector<bool>visited(101,0);
queue<int>q;
int n;
int cnt = 0;
void infection(int start);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int m;
	cin >> m;
	for(int i=0;i<m;i++) {
		int n1, n2;
		cin >> n1 >> n2;
		computer[n1].push_back(n2);
		computer[n2].push_back(n1);	
	}
	infection(1);
	cout<<cnt;
}

void infection(int start)
{
	q.push(start);
	visited[start] = true;
	while (!(q.empty()))
	{
		int current = q.front();
		q.pop();

		for(int i=0;i<computer[current].size();i++)
		{
			if (visited[computer[current][i]] == false)
			{
				visited[computer[current][i]] = true;
				cnt++;
				q.push(computer[current][i]);
			}
		}
	}
}