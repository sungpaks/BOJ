#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
typedef struct point
{
	int x, y;
} point;

point p[1501];

bool isRightTriangle(point a, point b, point c)
{
	ULL abLength = abs((LL)(a.x - b.x) * (LL)(a.x - b.x) + (LL)(a.y - b.y) * (LL)(a.y - b.y));
	ULL bcLength = abs((LL)(b.x - c.x) * (LL)(b.x - c.x) + (LL)(b.y - c.y) * (LL)(b.y - c.y));
	ULL caLength = abs((LL)(c.x - a.x) * (LL)(c.x - a.x) + (LL)(c.y - a.y) * (LL)(c.y - a.y));
	if (abLength == bcLength + caLength)
		return true;
	if (bcLength == abLength + caLength)
		return true;
	if (caLength == abLength + bcLength)
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (isRightTriangle(p[i], p[j], p[k]))
					cnt++;
			}
		}
	}
	cout << cnt;
}