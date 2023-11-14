#include <iostream>

using namespace std;

int Left[10002];
int Right[10002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, k;
	cin >> x >> k;
	for (int i = 0; i < x; i++)
	{
		int in;
		cin >> in;
		Left[in]++;
	}
	for (int i = 0; i < x; i++)
	{
		int in;
		cin >> in;
		Right[in]++;
	}
	long long result = 0;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (i != j)
				result += (long long)Left[i] * (long long)Right[j];
		}
	}
	cout << result;
}