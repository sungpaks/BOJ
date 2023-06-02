#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
#include <map>
using namespace std;
//주어진 카드의 숫자를 키, 갯수를 밸류??
map<long long, int>cards;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		long long num;
		cin >> num;
		cards[num]++;
	}
	int m;
	cin >> m;
	for(int i=0;i<m;i++) {
		long long num;
		cin >> num;
		cout << cards[num] << " ";
	}
}