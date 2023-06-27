#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main () {
	int n, m;
	cin >> n >> m;
	vector<int>v(n,0);
	for(int i=0;i<n;i++) {
		cin >> v[i];
	}
	int max = 0;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			for(int k=j+1;k<n;k++) {
				int sum = v[i] + v[j] + v[k];
				if (sum <= m && sum > max) max = sum;
			}
		}
	}
	cout << max;
} 