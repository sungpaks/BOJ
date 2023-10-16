#include <iostream>

using namespace std;

char plate[1002][1002];
int n;
bool isInPlate(int i, int j)
{
	return (1 <= i && i <= n) && (1 <= j && j <= n);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	int heartX = 0, heartY = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> plate[i][j];
			if (!heartX && !heartY && plate[i][j] == '*')
			{
				heartY = i + 1;
				heartX = j;
			}
		}
	}
	int rArm = 0, lArm = 0, waist = 0, rleg = 0, lleg = 0;
	for (int j = heartX - 1;; j--)
	{
		if (isInPlate(heartY, j) && plate[heartY][j] == '*')
			lArm++;
		else
			break;
	}
	for (int j = heartX + 1;; j++)
	{
		if (isInPlate(heartY, j) && plate[heartY][j] == '*')
			rArm++;
		else
			break;
	}
	for (int i = heartY + 1;; i++)
	{
		if (isInPlate(i, heartX) && plate[i][heartX] == '*')
			waist++;
		else
			break;
	}
	for (int i = heartY + waist + 1;; i++)
	{
		if (!isInPlate(i, heartX - 1) || !isInPlate(i, heartX + 1) || (plate[i][heartX - 1] == '-' && plate[i][heartX + 1] == '-'))
			break;
		if (plate[i][heartX - 1] == '*')
			lleg++;
		if (plate[i][heartX + 1] == '*')
			rleg++;
	}
	cout << heartY << " " << heartX << "\n"
		 << lArm << " " << rArm << " " << waist << " " << lleg << " " << rleg;
}