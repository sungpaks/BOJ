#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	long long a = 0, b = 0;
	cin >> a >> b;
	queue<pair<long long, long long>> numbers = queue<pair<long long, long long>>();
	numbers.push({a, 1});
	int result = -1;
	while (numbers.size())
	{
		long long cur = numbers.front().first;
		int count = numbers.front().second;
		numbers.pop();
		long long next1 = cur * 2;
		long long next2 = cur * 10 + 1;
		if (next1 <= b)
		{
			numbers.push({next1, count + 1});
		}
		if (next2 <= b)
		{
			numbers.push({next2, count + 1});
		}
		if ((next1 == b || next2 == b) && (result == -1 || result > count + 1))
		{
			result = count + 1;
		}
	}
	cout << result;
}
// 430000000 503270511
// 2147483647