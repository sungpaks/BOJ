#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int>v; //고장난버튼들
int current = 100;

int main () {
	int n;
	cin >> n; //이동하려는 채널
	int m;
	cin >> m;
	for(int i=0;i<m;i++) {
		int b;
		cin >> b;
		v.push_back(b);
	}
	for(int i=0;i<=1000000;i++) {
		int tmp = i;
		if (i == 0 && find(v.begin(),v.end(),i) != v.end()) continue;
		while (tmp > 0) {
			if (find(v.begin(),v.end(),tmp%10) != v.end()) break;
			tmp = tmp/10;
		}
		//if (find(v.begin(),v.end(),tmp%10) != v.end()) continue;
		if (tmp == 0 && abs(n-i) < abs(n-current)) current = i; 
	}
	int cnt = 0, div = 1;
	if (current != 100) {
		while (current / div > 0) {
			div *= 10;
			cnt++;
		}
		if (current == 0) cnt++;
	}
	cnt += abs(n - current);
	if (abs(n-100) < cnt) cnt = abs(n-100);
	cout << cnt << " ";
}