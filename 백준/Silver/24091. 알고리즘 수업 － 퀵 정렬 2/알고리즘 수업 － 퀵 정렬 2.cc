#include <iostream>
#include <algorithm>

using namespace std;

void quick_sort(int A[], int p, int r);
int partition(int A[], int p, int r);

int cnt = 0, k, n;

int main()
{
	scanf("%d %d", &n, &k);
	int A[10001] = {0};
	for(int i=0;i<n;i++)
	{
		scanf("%d", &A[i]);
	}
	quick_sort(A, 0, n-1);
	if (cnt < k) printf("-1");
}

void quick_sort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = partition(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
}
int partition(int A[], int p, int r)
{
	int i = p - 1;
	for(int j=p;j<r;j++)
		if (A[j] <= A[r]) {
			swap(A[++i], A[j]);
			if (++cnt == k) for(int i=0;i<n;i++) printf("%d ", A[i]);
		}
	if (i+1 != r) {
		swap(A[i+1], A[r]);
		
			if (++cnt == k) for(int i=0;i<n;i++)printf("%d ", A[i]);
	}
	return (i+1);
}