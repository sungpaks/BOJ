#include <iostream>
#include <algorithm>
using namespace std;

int n;
int seat[1025][1025];

int getSecondNumber(int a, int b, int c, int d)
{
	int fourSeats[4] = {a, b, c, d};
	sort(fourSeats, fourSeats + 4);
	return fourSeats[1];
}

int getSpecialAward(int i, int j, int width)
{
	if (width == 1)
		return seat[i][j];
	if (width == 2)
	{
		return getSecondNumber(seat[i][j], seat[i][j + 1], seat[i + 1][j + 1], seat[i + 1][j]);
	}
	width /= 2;
	return getSecondNumber(
		getSpecialAward(i, j, width),
		getSpecialAward(i, j + width, width),
		getSpecialAward(i + width, j, width),
		getSpecialAward(i + width, j + width, width));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> seat[i][j];
		}
	}
	cout << getSpecialAward(0, 0, n);
}