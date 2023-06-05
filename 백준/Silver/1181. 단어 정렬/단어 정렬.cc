#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<string>w;

bool compare(string s1, string s2) {
	if (s1.length() == s2.length()) 
	{
		return (s1 < s2);
	}
	else return s1.length() < s2.length();
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		w.push_back(s);
	}
	sort (w.begin(), w.end(), compare);
	w.erase(unique(w.begin(),w.end()), w.end());
	for(auto it = w.begin() ;it != w.end();it++) {
		cout << *it << "\n";
	}
}