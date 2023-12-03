#include <iostream>
#include <vector>

using namespace std;
int n;
int paper[101][101];

int main()
{
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		for (int i = y; i < y + 10; i++)
		{
			for (int j = x; j < x + 10; j++)
			{
				paper[i][j] = 1;
			}
		}
	}
	int di[4] = {1, 0, -1, 0};
	int dj[4] = {0, 1, 0, -1};
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (paper[i][j])
			{
				for (int k = 0; k < 4; k++)
				{
					int ni = i + di[k];
					int nj = j + dj[k];
					if (ni < 0 || ni > 100 || nj < 0 || nj > 100)
						continue;
					if (!paper[ni][nj])
						sum++;
				}
			}
		}
	}
	cout << sum;
}