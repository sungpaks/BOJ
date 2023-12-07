#include <stdio.h>
#include <stdlib.h>
#define INF 200000

typedef struct info {
	int i, j, c;
}info;
int n;
int adjArray[126][126];
int d[126][126];
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

int hSize = 0;
info min_heap[10001];
void swap(info* a, info* b) {
	info tmp = *a;
	*a = *b;
	*b = tmp;
}

void upHeap(int i) {
	int j = i / 2;
	while (i > 1) {
		if (min_heap[i].c < min_heap[j].c) swap(min_heap + i, min_heap + j);
		i = j;
		j = i / 2;
	}
}
void downHeap(int i) {
	int j = i * 2;
	while (j <= hSize) {
		if (j+1 <= hSize && min_heap[j].c > min_heap[j + 1].c) j++;
		if (min_heap[i].c > min_heap[j].c) swap(min_heap + i, min_heap + j);
		i = j;
		j = i * 2;
	}
}
info removeMin() {
	info rv = min_heap[1];
	min_heap[1] = min_heap[hSize];
	min_heap[hSize].i = 0;
	min_heap[hSize].j = 0;
	min_heap[hSize].c = INF;
	hSize--;
	downHeap(1);
	//hSize--;
	return rv;
}

void insertItem(int i, int j, int c) {
	min_heap[++hSize].i = i;
	min_heap[hSize].j = j;
	min_heap[hSize].c = c;
	upHeap(hSize);
}

void dijkstra()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			d[i][j] = INF;
		}
	}
	d[0][0] = adjArray[0][0];
	insertItem(0,0,d[0][0]);
	while (hSize)
	{
		info curInfo = removeMin();
		int cost = curInfo.c;
		for (int k = 0; k < 4; k++)
		{
			int ni = curInfo.i + di[k];
			int nj = curInfo.j + dj[k];
			if (ni < 0 || ni >= n || nj < 0 || nj >= n)
				continue;
			int nCost = cost + adjArray[ni][nj];
			if (d[ni][nj] > nCost)
			{
				d[ni][nj] = nCost;
				insertItem(ni,nj,nCost);
			}
		}
	}
}

int main()
{
	int cnt = 0;
	while (++cnt)
	{
		scanf("%d", &n);
		if (!n)
			return 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &adjArray[i][j]);
			}
		}
		dijkstra();
		printf("Problem %d: %d\n", cnt, d[n-1][n-1]);
	}
}