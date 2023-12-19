
#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#define INF 2147483647

typedef struct edge {
	int s, e, w;
	struct edge* next;
}edge;

int n, m;
int disjointSet[200001];
edge *graph[200001];

edge* getNewNode(int u, int v, int w) {
	edge* newNode = (edge*)malloc(sizeof(edge));
	newNode->next = 0;
	newNode->s = u;
	newNode->e = v;
	newNode->w = w;
	return newNode;
}

void initGraph() {
	for (int i = 0;i <= m;i++) {
		graph[i] = getNewNode(-1, -1, 0);
	}
}

void insertNode(int u, int v, int w) {
	edge* cur = graph[u];
	while (cur->e != -1 && cur->w < w) cur = cur->next;
	if (!cur) {
		//cur->e = v;
		return;
	}
	edge* newNode = getNewNode(u, v, w);
	newNode->s = cur->s;
	newNode->e = cur->e;
	newNode->w = cur->w;
	cur->s = u;
	cur->e = v;
	cur->w = w;
	newNode->next = cur->next;
	cur->next = newNode;
}

int findParent(int n) { //recursive
	if (n == disjointSet[n]) return n;
	else return findParent(disjointSet[n]);
}
void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a != b) disjointSet[a < b ? b : a] = a < b ? a : b;
}
int MSTsum = 0;
void Baruvka() {
	int cnt = 0;
	while (cnt < m-1) {
		for (int i = 0;i < m;i++) {
			if (graph[i]->e == -1) continue;
			if (findParent(graph[i]->s) == findParent(graph[i]->e));
			else {
				unionParent(graph[i]->s, graph[i]->e);
				MSTsum += graph[i]->w;
				cnt++;
			}
			edge* prev = graph[i];
			graph[i] = graph[i]->next;
			free(prev);
		}
	}
}

void freeGraph() {
	for (int i = 0;i <= m;i++) {
		if (graph[i]) free(graph[i]);
	}
}

int main() {
	while (1) {
		for (int i = 0;i <= m;i++) disjointSet[i] = 0;
		int OriginSum = 0;
		MSTsum = 0;
		scanf("%d %d", &m, &n); //집의 수가 m임
		if (!m && !n) return 0;
		initGraph();
		for (int i = 0;i < n;i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			insertNode(x, y, z);
			insertNode(y, x, z);
			disjointSet[x] = x;
			disjointSet[y] = y;
			OriginSum += z;
		}
		Baruvka();
		printf("%d\n", OriginSum - MSTsum);
		freeGraph();
	}
}
