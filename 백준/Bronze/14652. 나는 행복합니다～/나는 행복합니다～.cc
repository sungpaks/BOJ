#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)

int main () {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int pos = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (pos == k) printf("%d %d", i, j);
			pos++;
		}
	}
}