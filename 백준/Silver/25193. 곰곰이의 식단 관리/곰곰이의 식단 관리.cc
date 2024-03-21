#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	int chickenCnt = 0;
	int otherCnt = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'C')
			chickenCnt++;
		else
			otherCnt++;
	}
	cout << ceil((double)chickenCnt / (double)(otherCnt + 1));
}