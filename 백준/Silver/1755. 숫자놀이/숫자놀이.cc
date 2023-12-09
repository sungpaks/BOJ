#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string toString(int n)
{
	switch (n)
	{
	case 0:
		return "zero";
		break;
	case 1:
		return "one";
		break;
	case 2:
		return "two";
		break;
	case 3:
		return "three";
		break;
	case 4:
		return "four";
		break;
	case 5:
		return "five";
		break;
	case 6:
		return "six";
		break;
	case 7:
		return "seven";
		break;
	case 8:
		return "eight";
		break;
	case 9:
		return "nine";
		break;
	}
	return "";
}

int main()
{
	int m, n;
	cin >> m >> n;
	vector<pair<string, int>> v;
	for (int i = m; i <= n; i++)
	{
		string s = toString(i % 10);
		if (i >= 10)
			s = toString(i / 10) + " " + s;
		v.push_back({s, i});
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].second;
		if (i % 10 == 9)
			cout << "\n";
		else
			cout << " ";
	}
}