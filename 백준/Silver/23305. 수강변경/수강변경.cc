#include <stdio.h>

int A[1000001];

int main () {
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		int a;
		scanf("%d", &a);
		A[a]++;
	}
	int cnt = 0;
	for(int i=0;i<n;i++) {
		int b;
		scanf("%d", &b);
		if (A[b]) {
			A[b]--;
			cnt++;
		}
	}
	printf("%d", n-cnt);
}