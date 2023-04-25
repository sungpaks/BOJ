#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double cho_paik_distance = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
		if (cho_paik_distance == 0 && r1 == r2) cout << "-1" << endl;
		else if ((abs(r1 - r2) < cho_paik_distance) && (cho_paik_distance < r1 + r2)) cout << "2" << endl;
		else if ((abs(r1 - r2) == cho_paik_distance) || (r1 + r2 == cho_paik_distance)) cout << "1" << endl;
		else cout << "0" << endl;
	}
}