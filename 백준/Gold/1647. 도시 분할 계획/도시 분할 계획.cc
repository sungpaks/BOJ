#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#define INF 2147483647

typedef struct edge {
	int s, e, w;
}edge;

int n, m;
int disjointSet[1000100];
edge *edges;

int findParent(int n) { //recursive
	if (n == disjointSet[n]) return n;
	else return findParent(disjointSet[n]);
}
void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a != b) disjointSet[a < b ? b : a] = a < b ? a : b;
}
void quick_sort(struct edge* data, int start, int end) {
	if (start >= end) {
		return;
	}
	int pivot = start;
	int i = pivot + 1;
	int j = end; struct edge temp;
	while (i <= j) {
		while (i <= end && data[i].w <= data[pivot].w) {
			i++;
		}
		while (j > start && data[j].w >= data[pivot].w) {
			j--;
		}
		if (i > j) {
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quick_sort(data, start, j - 1);
	quick_sort(data, j + 1, end);
}

long long kruskal() {
	long long sum = 0;
	int last = 0;
	int cnt = 0;
	while (cnt < m) {
		edge current = edges[cnt];
		int pa = findParent(current.s);
		int pb = findParent(current.e);
		if (pa != pb) {
			unionParent(pa, pb);
			//printf(" %d", current.w);
			sum += (long long)current.w;
			last = current.w;
		}
		cnt++;
	}
	return sum-(long long)last;
}

int main() {
	scanf("%d %d", &n, &m);
	edges = (edge*)malloc(sizeof(edge) * (m + 1));
	for (int i = 0;i <= n;i++) disjointSet[i] = i;
	for (int i = 0;i < m;i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edges[i].s = u;
		edges[i].e = v;
		edges[i].w = w;
	}
	quick_sort(edges, 0, m - 1);
	printf("%lld", kruskal());
	return 0;
}
