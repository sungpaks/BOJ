#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long>A(100001);

int is_exist(long long check, int n);

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> A[i];
	}
	sort(&A[0], &A[n]);
	int m;
	cin >> m;
	for(int i=0;i<m;i++)
	{
		long long check;
		cin >> check;
		cout << is_exist(check, n) << "\n";
	}
}

int is_exist(long long check, int n)
{
	int start = 0;
	int end = n - 1;
	while (start <= end)
	{
		int index = (start + end) / 2;
		if (A[index] == check) return 1;
		else if (A[index] > check) end = index - 1;
		else if (A[index] < check) start = index + 1;
	}
	return 0;
}