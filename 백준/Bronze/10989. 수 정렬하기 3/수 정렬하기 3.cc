#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v(10001);

int main() {
	long long n;
	scanf("%lld", &n);
	for(int i=0;i<n;i++) {
		int index;
		scanf("%d", &index);
		v[index]++;
	}
	for(int i=0;i<10001;i++) {
		for(int j=0;j<v[i];j++) {
			printf("%d\n", i);
		}
	}
}