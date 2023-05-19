#include <iostream>
#include <map>

using namespace std;

map<long long, int>cards;
//key : 카드에 적힌 정수 , value : 해당 정수의 카드 수

int main() {
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		long long lln;
		scanf("%lld", &lln);
		cards[lln]++;
	}
	map<long long, int>::iterator it = cards.begin();
	long long maxkey = 0;
	int maxvalue = 0;
	for(it; it!=cards.end();it++) {
		if (it->second > maxvalue) {
			maxvalue = it->second;
			maxkey = it->first;
		}
	}
	printf("%lld", maxkey);
}