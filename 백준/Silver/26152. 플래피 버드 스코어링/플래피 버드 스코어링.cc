#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> width;
int rSearch(int l, int r, int w)
{
	int mid = (l + r) / 2;
	if (l >= r)
	{
		return r;
		// return width[mid].first >= w ? width[mid - 1].second : width[mid].second;
	}
	if (width[mid] >= w)
		return rSearch(mid + 1, r, w);
	else
		return rSearch(l, mid, w);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int A;
		cin >> A;
		width.push_back(A);
	}
	for (int i = 0; i < n; i++)
	{
		int B;
		cin >> B;
		width[i] -= B;
		if (i > 0 && width[i] > width[i - 1])
			width[i] = width[i - 1];
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int bird;
		cin >> bird;
		int result = rSearch(0, n, bird);
		printf("%d\n", result);
	}
}
// 1 3 5 6 7 8 9

// 1 2 3