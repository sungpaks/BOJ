#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#define INF 500000
#define max(a,b) (((a)>(b))?(a):(b)) 
int n;
int A[51];
int B[51];

void mySwap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main() {
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", A + i);
	for (int i = 0;i < n;i++) scanf("%d", B + i);
	int sum = 0;
	for (int i = 0;i < n;i++) {
		int aMin = INF;
		int bMax = 0;
		int aMinIndex = i;
		int bMaxIndex = i;
		for (int j = i;j < n;j++) {
			if (aMin > A[j]) {
				aMin = A[j];
				aMinIndex = j;
			}
			if (bMax < B[j]) {
				bMax = B[j];
				bMaxIndex = j;
			}
		}
		mySwap(&A[i], &A[aMinIndex]);
		mySwap(&B[i], &B[bMaxIndex]);
		sum += aMin * bMax;
	}
	printf("%d", sum);
}