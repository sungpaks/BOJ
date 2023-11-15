#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)

int n;
int adjMatrix[101][101];
int result[101][101];

int main() {
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			scanf("%d", *(adjMatrix + i) + j);
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			for (int k = 0;k < n;k++) {
				if (adjMatrix[i][k] && adjMatrix[k][j])
					adjMatrix[i][j] = 1;
			}
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			for (int k = 0;k < n;k++) {
				if (adjMatrix[i][k] && adjMatrix[k][j])
					adjMatrix[i][j] = 1;
			}
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			printf("%d ", adjMatrix[i][j]);
		}
		printf("\n");
	}
}
