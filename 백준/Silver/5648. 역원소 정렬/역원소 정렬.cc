#include <iostream>
#include <algorithm>

using namespace std;

long long reverseNumber(long long n)
{
	long long result = 0;
	while (n)
	{
		result *= 10;
		result += n % 10;
		n /= 10;
	}
	return result;
}
long long reversedNums[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long lln;
		cin >> lln;
		reversedNums[i] = reverseNumber(lln);
	}
	sort(reversedNums, reversedNums + n);
	for (int i = 0; i < n; i++)
	{
		cout << reversedNums[i] << "\n";
	}
}