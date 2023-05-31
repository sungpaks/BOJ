#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool superhero(string str, stack<char>s);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		stack<char>s;
		string str;
		getline(cin, str);
		if (str == ".") break;
		bool b = superhero(str, s);
		if (b == true) cout << "yes\n";
		else cout << "no\n"; 
	}
}

bool superhero(string str, stack<char>s) {
	int i = 0;
	while(str[i]) {
		if (str[i] == '(') s.push(str[i]);
		if (str[i] == '[') s.push(str[i]);
		if (str[i] == ')') {
			if (s.empty() || s.top() != '(') return false;
			s.pop();
		}
		if (str[i] == ']') {
			if (s.empty() || s.top() != '[') return false;
			s.pop();
		}
		i++;
	}
	if (s.empty()) return true;
	else return false;
}