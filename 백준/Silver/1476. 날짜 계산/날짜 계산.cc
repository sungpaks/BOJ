#include <iostream>

using namespace std;

int main()
{
	int E, S, M;
	cin >> E >> S >> M;

	int ee=1,ss=1,mm=1;
	int year = 1;
	while (1)
	{
		if (ee==E && ss==S && mm==M) break;
		ee++;
		ss++;
		mm++;
		year++;
		if (ee > 15) ee=1;
		if (ss > 28) ss=1;
		if (mm > 19) mm=1;
	}
	cout << year <<endl;

}

/*
시간제한 2초나 주길래 그냥.. 깡으로 돌리라는거같아서
E, S, M 셋 다 같아질때까지 계속 돌렸습니다
시간 대충 재봤는데 0.1초도 안걸리더라구여
*/