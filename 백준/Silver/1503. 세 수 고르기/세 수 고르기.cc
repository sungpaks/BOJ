#include <iostream>
#include <cmath>
using namespace std;

bool S[1001];
int main()
{
	int N, M;
	cin >> N >> M;
	if (!M)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < M; i++)
	{
		int s;
		cin >> s;
		S[s] = true;
	}

	int min = 2147483647;
	for (int i = 1; i <= 1000; i++)
	{
		if (S[i])
			continue;
		for (int j = 1; j <= 1000; j++)
		{
			if (S[j])
				continue;
			for (int k = 1; k <= 1001; k++)
			{
				if (S[k])
					continue;
				int cur = abs(N - i * j * k);
				if (cur < min)
					min = cur;
			}
		}
	}
	cout << min;
}
// 1,000,000,000
// 2,147,483,647
