#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define ll long long

typedef struct teleport{
	int x1, y1, x2, y2;
}teleport;
teleport p[3];
int xs, ys, xe, ye;
ll minTime = 0;
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int moveTime (int x1, int x2, int y1, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

void backTracking(int curX, int curY, ll curTime, int cnt) {
	if (cnt >= 3) {
		curTime += (ll)moveTime(curX, xe, curY, ye);
		if (minTime > curTime) minTime = curTime;
		return;
	}
	for(int j=0;j<3;j++) {
		ll nextTime = (ll)curTime + (ll)moveTime(curX, p[j].x1, curY, p[j].y1) + 10;
		backTracking(p[j].x2, p[j].y2, nextTime, cnt+1);
		nextTime = (ll)curTime + (ll)moveTime(curX, p[j].x2, curY, p[j].y2) + 10;
		backTracking(p[j].x1, p[j].y1, nextTime, cnt+1);
	}
	if (curTime) backTracking(curX, curY, curTime, cnt+1);
}

int main () {
	scanf("%d %d %d %d", &xs, &ys, &xe, &ye);
	minTime = (ll)moveTime(xs, xe, ys, ye);
	for(int i=0;i<3;i++) {
		scanf("%d %d %d %d", &(p[i].x1), &(p[i].y1), &(p[i].x2), &(p[i].y2));
	}
	backTracking(xs, ys, 0, 0);
	printf("%lld", minTime);
}
//2,147,483,647