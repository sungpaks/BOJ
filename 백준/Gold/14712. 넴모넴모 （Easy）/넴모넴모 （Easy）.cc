#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
bool nemo[26][26];
int cnt = 0;

void backTracking(int curi, int curj)
{
	if (curj >= m)
	{
		curj = 0;
		curi = curi + 1;
	}
	if (curi >= n)
	{
		cnt++;
		return;
	}
	nemo[curi][curj] = 0;
	backTracking(curi, curj + 1);
	nemo[curi][curj] = 1;
	if (curi > 0 && curj > 0 && nemo[curi][curj] && nemo[curi - 1][curj] && nemo[curi][curj - 1] && nemo[curi - 1][curj - 1])
		return;
	backTracking(curi, curj + 1);
}

int main()
{
	cin >> n >> m;
	backTracking(0, 0);
	cout << cnt;
}

/*
n-2C2 * m-2C2 ?
nCr = n-1Cr-1 + n-1Cr

OOOOO
OOOOO
OOOOO
*/