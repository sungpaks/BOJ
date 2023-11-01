#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)
double dis(int n, int m, int n2, int m2)
{
	double dis = sqrt(pow(n2 - n, 2) + pow(m2 - m, 2));
	return dis;
}
int main()
{
	int t, n ;
	int start[2] = { 0, }, end[2] = { 0, };
	int info_plan[100][3] = { 0, };
	scanf("%d", &t);
	for (int i = 0;i < t;i++)
	{
        int res = 0;
		scanf("%d %d %d %d", &start[0], &start[1], &end[0], &end[1]);
		scanf("%d", &n);
		for (int j = 0;j < n;j++)
		{
			scanf("%d %d %d", &info_plan[j][0], &info_plan[j][1], &info_plan[j][2]);
			if (dis(info_plan[j][0], info_plan[j][1], start[0], start[1])< info_plan[j][2]) //반지름이 더 큼
			{
				if (dis(info_plan[j][0], info_plan[j][1], end[0], end[1]) > info_plan[j][2])
					res++;
			}
			if(dis(info_plan[j][0], info_plan[j][1], end[0], end[1]) < info_plan[j][2]) //반지름이 더 큼
			{
				if (dis(info_plan[j][0], info_plan[j][1], start[0], start[1]) > info_plan[j][2])
					res++;
			}
		}
        printf("%d\n", res);
	}
	return 0;
}