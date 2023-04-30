#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v(20, vector<int>(20, 0));
int n;
vector<int>comb;
vector<bool>bit_perm;
vector<int>comb_result;
vector<int>other_team;
bool flag = true;

int getPowerDifference();
void getNextComb();
int main(){
	scanf("%d", &n);
	int sum = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &v[i][j]);
			sum += v[i][j];
		}
	}
	for(int i=0;i<n;i++){
		comb.push_back(i+1);
		bit_perm.push_back(false);
	}
	for(int i=0;i<n/2;i++) {
		bit_perm[i]=true;
		comb_result.push_back(i+1);
		other_team.push_back(n/2+i+1);
	}
	//1,2,3,..,n까지 조합 초기화
	/*
	조합 만들기 : bit_perm에서 안 뽑아본 true순열을 가져오고,
	해당 true자리의 숫자를 뽑는다
	*/
	int hwang_bal = getPowerDifference();
	while(flag == true)
	{
		int power_difference = getPowerDifference();
		if (hwang_bal > power_difference) hwang_bal = power_difference;
		getNextComb();
	}
	printf("%d", hwang_bal);
}

void getNextComb()
{
	flag = prev_permutation(bit_perm.begin(), bit_perm.end());
	int j = 0;
	int k = 0;
	for(int i=0;i<n;i++){
		if (bit_perm[i]==true) comb_result[j++] = comb[i];
		else other_team[k++] = comb[i];
	}
}

int getPowerDifference()
{
	int team1 = 0;
	int team2 = 0;
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			if (i==j) continue;
			team1 += v[comb_result[i] - 1][comb_result[j] - 1];
			team2 += v[other_team[i] - 1][other_team[j] - 1];
		}
	}
	return (team1 > team2 ? (team1-team2) : (team2-team1));
}