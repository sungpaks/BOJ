#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#define INF 100000000

typedef struct edge {
	int s, e, w;
}edge;


int n, m, wormhole;

int myMin(int a, int b) {
	return a > b ? b : a;
}

int BellmanFord(int d[], edge edges[]) {
	/*for (int i = 0;i <= n;i++) {
		d[i] = INF;
	}*/
	d[1] = 0;
	for (int i = 0;i <= n;i++) {
		for (int j = 0;j < 2 * m + wormhole;j++) {
			int u = edges[j].s;
			int z = edges[j].e;
			if (d[u] != INF && d[z] > d[u]+edges[j].w)
			{
				d[z] = d[u] + edges[j].w;
				if (i == n) {
					return 0; //무한히 과거여행 가능
				}
			}
		}
	}
	return 1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &wormhole);
		int d[501] = {0,};
		edge edges[5201] = {0,};
		for (int i = 0;i < 2 * m;i += 2) {
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);
			edges[i].s = s;
			edges[i].e = e;
			edges[i].w = t;
			edges[i + 1].s = e;
			edges[i + 1].e = s;
			edges[i + 1].w = t;
		}
		for (int i = 2 * m;i < 2 * m + wormhole;i++) {
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);
			edges[i].s = s;
			edges[i].e = e;
			edges[i].w = -t;
		}
		if (!BellmanFord(d, edges)) printf("YES\n");
		else printf("NO\n");
	}
}