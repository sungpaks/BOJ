#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main () {
	int n;
	cin >> n;
	int m;
	cin >> m;
	string s;
	cin >> s;
	//IOIOIOI시작~끝 길이를 재고, 그 안에 Pn이 몇개인지
	int isP = 0;
	int Plen = 0;
	int result = 0;
	//0은 Pn이 아닌 상태, 1은 O가 나올차례, 2는 I가 나올차례
	for(int i=0;i<s.length();i++) {
		if (s[i] == 'I') {
			if (isP == 0) isP = 1;
			else if (isP == 1) {
				isP = 1;
				if (Plen >= n) result += (Plen-n+1);
				Plen = 0;
			}
			else if (isP == 2) {
				isP = 1;
				Plen++;
			}
		}
		else if (s[i] == 'O') {
			if (isP == 0) ;
			else if (isP == 1) {
				isP = 2;
			}
			else if (isP == 2) {
				isP = 0;
				if (Plen >= n) result += (Plen-n+1);
				Plen = 0;
			}
		}
	}
	if (Plen >= n) result += (Plen-n+1);
	cout << result;
}