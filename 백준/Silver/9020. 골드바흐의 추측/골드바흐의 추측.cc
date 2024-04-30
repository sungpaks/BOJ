#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isPrime[10001];

void init()
{
	for (int i = 2; i <= 10000; i++)
	{
		isPrime[i] = true;
	}
	for (int i = 2; i * i <= 10000; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= 10000; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

void getTwoPrime(int n)
{
	for (int i = 0; i <= n / 2; i++)
	{
		if (isPrime[n / 2 - i] && isPrime[n / 2 + i])
		{
			cout << n / 2 - i << " " << n / 2 + i << "\n";
			return;
		}
	}
}

int main()
{
	init();

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		getTwoPrime(n);
	}
}