#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	vector<int>num_count(11,0);
	int a, b, c;
	cin >> a >> b >> c;
	int num = a * b * c;
	while (num > 0) {
		num_count[num%10]++;
		num/=10;
	}
	for(int i=0;i<10;i++) cout << num_count[i] << "\n";
}