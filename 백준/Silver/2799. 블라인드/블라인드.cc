#include <iostream>
#include <vector>

using namespace std;

char fullStatus[1000][1000];

int whatKindsOfBlind(int i, int j)
{
	int k = 0;
	while (fullStatus[i + k][j] == '*')
	{
		k++;
	}
	return k;
}
int main()
{
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < 5 * n + 1; i++)
	{
		for (int j = 0; j < 5 * m + 1; j++)
		{
			cin >> fullStatus[i][j];
		}
	}
	int kindsOfBlind[5] = {0, 0, 0, 0, 0};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			kindsOfBlind[whatKindsOfBlind(i * 5 + 1, j * 5 + 1)]++;
		}
	}
	for (int i = 0; i < 5; i++)
		cout << kindsOfBlind[i] << " ";
}

// 각 grid의 시작점
// i : 1, 6, 11, ...
// j : 1, 6, 11, ...