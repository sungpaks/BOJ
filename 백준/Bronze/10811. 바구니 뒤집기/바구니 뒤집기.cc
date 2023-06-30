#include <iostream>
#include <vector>

using namespace std;

int main () {
	int bucket[101] = {0};
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++) {
		bucket[i] = i;
	}
	for(int t=0;t<m;t++) {
		int i, j;
		scanf("%d %d", &i, &j);
		for(int k=0;k<j-i;k++) {
			if (i+k > j-k) break;
			int tmp = bucket[i+k];
			bucket[i+k] = bucket[j-k];
			bucket[j-k] = tmp;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ", bucket[i]);
}