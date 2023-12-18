#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#define INF 100000000

typedef struct info {
	int v, w;
	struct info* next;
}info;

info* graph[10001];
//info* tail[10001];
int topoLevel[10001];
int n;

info* getNewNode(int v, int w) {
	info* newNode = (info*)malloc(sizeof(info));
	newNode->next = 0;
	newNode->v = v;
	newNode->w = w;
	return newNode;
}

void initGraph() {
	for (int i = 1;i <= n;i++) {
		graph[i] = 0;
	}
}

void insertNode(int u, int v, int w) {
	//info* cur = graph[u];
	//while (cur->v != -1 && cur->v < v) cur = cur->next;
	if (!graph[u]) {
		graph[u] = getNewNode(v, w);
		//tail[u] = graph[u];
		//tail[u]->v = v;
		//tail[u]->w = w;
		return;
	}
	info* newNode = getNewNode(v, w);
	newNode->next = graph[u];
	graph[u] = newNode;
	//tail[u] = newNode;
}

void print() {
	for (int i = 1;i <= n;i++) {
		info* cur = graph[i];
		while (cur) {
			printf("%d-%d ", cur->v, cur->w);
			cur = cur->next;
		}
		printf("\n");
	}
}

void topologyDFS(int v) {
	//if(topoLevel[v] < t) topoLevel[v] = t;
	info* cur = graph[v];
	while (cur && cur->v > v) {
		if (topoLevel[cur->v] < topoLevel[v] + cur->w) topoLevel[cur->v] = topoLevel[v] + cur->w;
		//topologyDFS(cur->v);
		//printf("%d", cur->v);
		cur = cur->next;
	}
	//if (graph[v] && topoLevel[v] < t + graph[v]->w) topoLevel[v] = t + graph[v]->w;
}

int main() {
	scanf("%d", &n);
	initGraph();
	for (int i = 1;i <= n;i++) {
		int w, cnt;
		scanf("%d %d", &w, &cnt);
		topoLevel[i] = w;
		for (int j = 0;j < cnt;j++) {
			int k;
			scanf("%d", &k);
			insertNode(k, i, w);
		}
	}
	for (int i = 1;i <= n;i++) {
		topologyDFS(i);
	}
	int max = 0;
	for (int i = 1;i <= n;i++) if (topoLevel[i] > max) max = topoLevel[i];
	printf("%d", max);
}