/*
OXXO
=> XXXO => OOOX => xOOX => OXOX => XXOX => OOXX => XOXX => OXXX => XXXX
9번..
O의 위치만큼 2의 제곱인가??
*/
#include <iostream>
#include <cmath>
#define D 1000000007

using namespace std;

long long power(int n)
{
	if (n <= 0)
		return 1;
	if (n == 1)
		return 2;
	else
	{
		long long x = power(n / 2) % D;
		if (n % 2 == 0)
			return (x * x) % D;
		else
			return (x * x * 2) % D;
	}
}

int main()
{
	string s;
	cin >> s;
	long long result = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'O')
		{
			result = (result + power(i)) % D;
			//  result = result % div;
		}
	}
	cout << result;
}