#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<pair<string, int>> bee;

int main()
{
	int total = 0;
	bee.push_back({"Re", 0});
	bee.push_back({"Pt", 0});
	bee.push_back({"Cc", 0});
	bee.push_back({"Ea", 0});
	bee.push_back({"Tb", 0});
	bee.push_back({"Cm", 0});
	bee.push_back({"Ex", 0});
	string s;
	while (cin >> s)
	{
		for (int i = 0; i < bee.size(); i++)
		{
			if (bee[i].first == s)
				bee[i].second++;
		}
		if (++total >= 24)
			break;
	}
	for (auto p : bee)
	{
		printf("%s %d %.2f\n", p.first.c_str(), p.second, (float)p.second / (float)total);
	}
	printf("Total %d 1.00", total);
}