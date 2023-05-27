#include <iostream>
#include <vector>

using namespace std;

vector<int>e;

int main()
{
	int n, m;
	scanf("%d %d", &m, &n);
	//e.push_back(2);
	for(int i=2;i*i<=n;i++) e.push_back(i);
	for(int i=m;i<=n;i++)
	{
		if (i == 1) continue;
		int flag = 1;
		for(int j=0;j<e.size();j++)
		{
			if (i == e[j]) break;
			else if (i % e[j] == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) printf("%d\n", i);
	}
}