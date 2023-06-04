#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>v;

int main() {
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for(auto it = v.begin(); it!=v.end();it++) {
		printf("%d\n", *it);
	}
}