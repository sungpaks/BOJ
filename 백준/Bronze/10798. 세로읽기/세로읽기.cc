#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main () {
	string s[5];
	for(int i=0;i<5;i++) {
		cin >> s[i];
	}
	for(int i=0;i<16;i++) {
		for(int j=0;j<5;j++) {
			if (s[j].length() > i) cout << s[j][i];
		}
	}
}