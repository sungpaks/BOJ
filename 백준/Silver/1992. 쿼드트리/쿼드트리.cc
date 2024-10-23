#include <iostream>
#include <string>

using namespace std;

char grid[65][65];
int n;

char compress(int start_i, int start_j, int width)
{
	char numberOfThisArea = grid[start_i][start_j];
	for (int di = 0; di < width; di++)
	{
		for (int dj = 0; dj < width; dj++)
		{
			int i = start_i + di;
			int j = start_j + dj;
			char cur = grid[i][j];
			if (cur == '0' && numberOfThisArea == '1')
				return 0;

			if (cur == '1' && numberOfThisArea == '0')
				return 0;
		}
	}
	return numberOfThisArea;
}

string getQuadTree(int i, int j, int curN)
{
	if (curN < 1)
		return "";
	char compressed = compress(i, j, curN);
	if (!compressed)
	{
		string leftTop = getQuadTree(i, j, curN / 2);
		string rightTop = getQuadTree(i, j + curN / 2, curN / 2);
		string leftBottom = getQuadTree(i + curN / 2, j, curN / 2);
		string rightBottom = getQuadTree(i + curN / 2, j + curN / 2, curN / 2);
		return "(" + leftTop + rightTop + leftBottom + rightBottom + ")";
	}
	else
	{
		return to_string(compressed - '0');
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}
	cout << getQuadTree(0, 0, n);
}