#include <stdio.h>
#include <math.h>

int main () {
	int t;
	scanf("%d", &t);
	while(t--) {
		int x, y;
		scanf("%d %d", &x, &y);
		long long gap = y-x;
		long long k = 1;
		while (1) {
			if (k*k >= gap) {
				printf("%lld\n", 2*k-1);
				break;
			}
			else if (k*k + k >= gap) {
				printf("%lld\n", 2*k);
				break;
			}
			k++;
		}
	}
}
//1 : 2
//2 : 2
//3 : 3
//4 : 0->1->2->1->0 = 3
//5 : 0->1->1->2->1->0 = 4
//6 : 0->1->2->2->1->0 = 4
//7 : 0->1->1->2->2->1->0 = 5
//8 : 0->1->2->2->2->1->0 = 5
//9 : 0->1->2->3->2->1->0 = 5
//10 : 0 1 1 2 3 2 1 0 = 6
//11 : 0 1 2 2 3 2 1 0 = 6
//12 : 0 1 2 3 3 2 1 0 = 6
//13 : 1 1 2 3 3 2 1 0 = 7
//14 : 1 2 2 3 3 2 1 0 = 7
//15 : 1 2 3 3 3 2 1 0 = 7
//16 : 1 2 3 4 3 2 1 0 = 7
//17 : 1 1 2 3 4 3 2 1 = 8
//18 : 1 2 2 3 4 3 2 1 = 8
//19 : 1 2 3 3 4 3 2 1 = 8
//20 : 1 2 3 4 4 3 2 1 = 8
//21 : 1 2 3 4 5 4 3 2 1 = 9
// n(n+1)/2 + (n-1)n/2 = n*n
// n(n+1)