#include <iostream>
#include <vector>

using namespace std;

int *A;
int cnt = 0;
int result = -1;
int k;

void merge_sort(int p, int r);
void merge(int p, int q, int r);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n >> k;
	A = new int[n];
	for(int i=0;i<n;i++) {
		cin >> A[i];
	}
	merge_sort(0, n-1);
	cout << result;
	delete [] A;
}

void merge_sort(int p, int r) {
	if (p < r) {
		int q = (p+r)/2; //중간지점 q
		merge_sort(p, q);
		merge_sort(q+1, r); //반 갈라서 재귀, 정렬
		merge(p, q, r); //병합
	}
}
void merge(int p, int q, int r) {
	//p~q, q+1~r은 이미 정렬되어있고, 이를 병합하여 p~r로 만듬
	int i = p, j = q+1, t = 0;
	int *tmp = new int[r-p+1]; //1~5면, 5자리 필요하니까, +1
	while (i <= q && j <= r) {
		if (A[i] <= A[j]) tmp[t++] = A[i++];
		else tmp[t++] = A[j++];
		//작은 쪽을 순차적으로 넣다가
	}
	while (i<=q) tmp[t++] = A[i++];
	while (j<=r) tmp[t++] = A[j++]; //끝나고 남은쪽 배열값 넣기
	i = p; t = 0;
	while (i <= r) { //결과인 tmp를 A의 p~r범위에 복사
		A[i++] = tmp[t++];
		//이 타이밍에 저장횟수 카운트
		if (++cnt == k) result = A[i-1];
	}
	delete [] tmp;
}