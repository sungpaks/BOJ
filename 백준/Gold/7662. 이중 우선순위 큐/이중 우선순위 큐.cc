#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

/*
멀티셋 : 정렬된 채로 유지됨
*/

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for(int i=0;i<t;i++) {
		int k;
		cin >> k;
		multiset<int> dpq;
		for(int j=0;j<k;j++) {
			char o;
			int n;
			cin >> o >> n;
			if (o == 'I') {
				dpq.insert(n);
			}
			else if (o == 'D') {
				if (dpq.empty()) continue;
				else if (n == 1) {
					auto it = dpq.end();
					dpq.erase(--it);
				}
				else if (n == -1) {
					dpq.erase(dpq.begin());
				}
			}
		}
		if (dpq.empty()) cout << "EMPTY\n";
		else {
			auto back = dpq.end();
			back--;
			cout << *back << " " << *dpq.begin() << "\n";
		}
	}
}