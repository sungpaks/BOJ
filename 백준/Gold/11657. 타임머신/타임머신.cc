#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#define INF 70000000

typedef struct edge {
	int s, e;
	long long w;
}edge;


int n, m, s;
long long d[501];
edge edges[6001];
/*
edge min_heap[1001];
int hSize = 0;
void swap(edge* a, edge* b) {
	edge tmp = *a;
	*a = *b;
	*b = tmp;
}

void upHeap(int i) {
	int j = i / 2;
	while (i > 1) {
		if (min_heap[i].w < min_heap[j].w) swap(min_heap + i, min_heap + j);
		i = j;
		j = i / 2;
	}
}
void downHeap(int i) {
	int j = i * 2;
	while (j <= hSize) {
		if (j+1 <= hSize && min_heap[j].w > min_heap[j + 1].w) j++;
		if (min_heap[i].w > min_heap[j].w) swap(min_heap + i, min_heap + j);
		i = j;
		j = i * 2;
	}
}
edge removeMin() {
	edge rv = min_heap[1];
	min_heap[1] = min_heap[hSize];
	min_heap[hSize].w = INF;
	downHeap(1);
	hSize--;
	return rv;
}

void insertItem(int s, int e, int w) {
	min_heap[++hSize].s = s;
	min_heap[hSize].e = e;
	min_heap[hSize].w = w;
	upHeap(hSize);
}*/

int myMin(int a, int b) {
	return a > b ? b : a;
}

int BellmanFord(int s) {
	for (int i = 0;i <= n;i++) {
		d[i] = INF;
		//insertItem(i, d[i]);
	}
	d[s] = 0;
	for (int i = 0;i <= n;i++) {
		for (int j = 0;j < m;j++) {
			int u = edges[j].s;
			int z = edges[j].e;
			if (d[u] != INF && d[z] > d[u]+edges[j].w)
			{
				d[z] = d[u] + edges[j].w;
				if (i == n) {
					printf("-1");
					return 0; //무한히 과거여행 가능
				}
			}
		}
	}
	return 1;
}

int main() {
	//for (int i = 0;i <= 10000;i++)min_heap[i].w = INF;
	scanf("%d %d", &n, &m);
	for (int i = 0;i < m;i++) {
		int u, v, w;
		scanf("%d %d %lld", &u, &v, &w);
		edges[i].s = u;
		edges[i].e = v;
		edges[i].w = w;
	}
	if (BellmanFord(1)) {
		for (int i = 2;i <= n;i++) {
			if (d[i] == INF) printf("-1\n");
			else printf("%d\n", d[i]);
		}
	}
}