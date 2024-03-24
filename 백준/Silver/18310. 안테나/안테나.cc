#include <iostream>
#include <algorithm>

using namespace std;

int house[200001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> house[i];
	}
	sort(house, house + n);

	cout << house[(n - 1) / 2];
}