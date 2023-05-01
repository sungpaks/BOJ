#include <iostream>
#include <vector>
using namespace std;

vector<int>v;

void MnNs(int n, int m, int current);
int main(){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		v.push_back(0);
	}
	MnNs(n,m,0);
}

void MnNs(int n, int m, int current)
{
	if (current == m)
	{
		for(int i=0;i<m;i++) cout << v[i] << " ";
		cout << "\n";
		return;
	}
	for(int i=1;i<=n;i++){
		v[current] = i;
		MnNs(n,m,current+1);
	}
}