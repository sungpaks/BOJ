#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> v;
void printStr()
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cout << "\n";
}
bool isCapital(string s)
{
	while (s[0] == '_')
	{
		s = s.substr(1);
	}
	return ('A' <= s[0] && s[0] <= 'Z');
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	int totalLength = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
		totalLength += s.length();
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < (m - totalLength) / (n - 1); j++)
		{
			v[i] = '_' + v[i];
		}
	}
	int leftCnt = (m - totalLength) % (n - 1);
	for (int i = 1; i < n && leftCnt; i++)
	{
		if (!isCapital(v[i]))
		{
			v[i] = '_' + v[i];
			leftCnt--;
		}
	}
	for (int i = v.size() - 1; i >= 1 && leftCnt; i--)
	{
		if (isCapital(v[i]))
		{
			v[i] = '_' + v[i];
			leftCnt--;
		}
	}
	printStr();
}