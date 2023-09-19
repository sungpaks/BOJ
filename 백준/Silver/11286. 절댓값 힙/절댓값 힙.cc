#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)

long H[100002];
int n = 0;

long my_abs(long n) {
	if (n < 0) return -1 * n;
	else return n;
}
void swap(long* a, long* b) {
	long tmp = *a;
	*a = *b;
	*b = tmp;
}

void insertHeap(long x) {
	n++;
	H[n] = x;
	int i = n, j = n/2;
	while (i > 1) {
		if (my_abs(H[i]) < my_abs(H[j])) swap(H + i, H + j);
		else if (my_abs(H[i]) == my_abs(H[j])) {
			if (H[i] < H[j]) swap(H + i, H + j);
		}
		else break;
		i /= 2;
		j = i / 2;
	}
}
void deleteHeap() {
	if (n == 0) {
		printf("0\n");
		return;
	}
	printf("%ld\n", H[1]);
	H[1] = H[n];
	H[n] = 0;
	int i = 1, j = 2;
	while (j < n) {
		if (j + 1 < n) {
			if ((my_abs(H[j]) > my_abs(H[j + 1])) || (my_abs(H[j]) == my_abs(H[j + 1]) && H[j] > H[j+1])) j++;
		}
		if (my_abs(H[i]) > my_abs(H[j])) swap(H + i, H + j);
		else if (my_abs(H[i]) == my_abs(H[j])) {
			if (H[i] > H[j]) swap(H + i, H + j);
		}
		else break;
		i = j;
		j = 2 * i;
	}
	n--;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		long x;
		scanf("%ld", &x);
		if (x == 0) deleteHeap();
		else insertHeap(x);
	}
}