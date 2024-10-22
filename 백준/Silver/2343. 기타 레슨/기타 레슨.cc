#include <iostream>

using namespace std;
int lectures[100001];
int n, m; // 강의의 수 N, 블루레이 M개

int howManyBluelay(int size)
{
	int result = 0;
	int curSize = 0;
	for (int i = 0; i < n; i++)
	{
		if (lectures[i] > size)
			return -1;
		if (curSize + lectures[i] > size)
		{
			// 블루레이 크기를 넘어가게 되면 다음 블루레이에 넣어야 함
			result++;
			curSize = lectures[i];
		}
		else
		{
			curSize += lectures[i];
		}
	}
	return result;
}

int main()
{
	// 각 블루레이 크기(모든 블루레이의 크기는 동일해야 함)의 가장 최소값을 구하자
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> lectures[i];
	}

	int left = 0;
	int right = 2147483646;
	int mid = (left + right) / 2;
	while (left <= right)
	{
		int amountOfBluelay = howManyBluelay(mid); // 현재 길이로 몇 개 블루레이가 나오는지 계산
		// cout << left << " " << right << " : " << amountOfBluelay << "\n";
		if (amountOfBluelay == -1 || amountOfBluelay >= m)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
		mid = (right + left) / 2;
	}
	cout << left;
}