#include <iostream>
#include <vector>
#define INF 10000000

using namespace std;

int balchagi(int s, int t, int cnt)
{
	if (s == t)
		return cnt;
	else if (s > t)
		return INF;

	int a = balchagi(s + 1, t, cnt + 1);
	int b = balchagi(2 * s, t + 3, cnt + 1);
	return (a < b ? a : b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int s, t;
		cin >> s >> t;
		cout << balchagi(s, t, 0) << "\n";
	}
}