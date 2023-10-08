#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	char c[201][201];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < 2 * n; i++)
	{
		for (int j = 0; j < 2 * m; j++)
		{
			c[i][j] = c[i % n][j % m];
		}
	}
	long long cnt[30];
	for (int i = 0; i < 2 * n; i++)
	{
		for (int j = 0; j < 2 * m; j++)
		{
			int cur = c[i][j] - 'A';
			cnt[cur] += (i + 1) * (2 * n - i) * (j + 1) * (2 * m - j);
		}
	}
	for (int i = 0; i < 26; i++)
	{
		cout << cnt[i] << "\n";
	}
}

/*
GOODGOOD
LUCKLUCK
GOODGOOD
LUCKLUCK
[i][j]번째 문자를 포함하며 부분직사각형을 만드는 경우의 수
1차원으로, 문자열이 0~length-1이고 i라고 하면
(i+1) * (length-i) :
	i보다 작거나 같은 위치에서 시작해서, i보다 크거나 같은 위치로 끝나야함
따라서 2차원으로 보면
(i+1)*(2*n-i)*(j+1)*(2*m-1)
*/