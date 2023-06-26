#include <iostream>
#include <string>
#include <map>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false);
	int cnt = 0;
	int n, m;
	map<string, bool>dbj;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		dbj.insert({s, false});
	}
	for(int i=0;i<m;i++) {
		string s;
		cin >> s;
		auto f = dbj.find(s);
		if (f != dbj.end()) {
			f->second = true;
			cnt++;
		}
	}
	cout << cnt << "\n";
	for(auto p : dbj) {
		if (p.second) cout << p.first << "\n";
	}
}