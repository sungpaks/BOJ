#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long k;
	cin >> n >> k;
	vector<long long> course(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> course[i];
	}
	long long cur = 0;
	int i = 0;
	int j = n - 1;
	while (true)
	{
		if (i >= n)
		{
			if (j < 0)
			{
				cout << 1;
				return 0;
			}
			if (cur + course[j] > k)
				break;
			cur += course[j--];
		}
		else
		{
			if (cur + course[i] > k)
				break;
			cur += course[i++];
		}
	}
	if (i < n)
		cout << i + 1;
	else
		cout << j + 1;
}