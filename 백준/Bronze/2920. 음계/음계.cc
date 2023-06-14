#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int flag = 0;
	//1이면 asc, 2이면 desc, 0이면 mixed
	int prev = 0;
	for(int i=0;i<8;i++) {
		int n;
		cin >> n;
		if (i == 0) prev = n;
		else if (i == 1) {
			if (prev < n) flag = 1;
			else if (prev > n) flag = 2;
			prev = n;
		}
		else {
			if (prev < n && flag == 2) {
				flag = 0;
				break;
			}
			if (prev > n && flag == 1) {
				flag = 0;
				break;
			}
			prev = n;
		}
	}
	if (flag == 0) cout << "mixed";
	else if (flag == 1) cout << "ascending";
	else cout << "descending";
}