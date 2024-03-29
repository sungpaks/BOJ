#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	long long cnt = 0;
	if (n == 1)
		cnt = 1;
	else if (n == 2)
	{
		if (m >= 7)
			cnt = 4;
		else if (m >= 5)
			cnt = 3;
		else if (m >= 3)
			cnt = 2;
		else
			cnt = 1;
	}
	else
	{
		if (m <= 4)
			cnt = m;
		else if (m <= 6)
			cnt = 4;
		else
		{
			cnt = m - 7 + 5;
		}
	}
	cout << cnt;
}
/*
xoxxxxx
xxoxoxx
oxoxxxo
7일 때 6인데
*/