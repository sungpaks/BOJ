#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>v(501,vector<int>(501, 0));
int current_area=0;
int max_area=0;
int cnt = 0;
vector<vector<int>>visited(501,vector<int>(501));
//벡터선언은 기본적으로 0초기화네? 
int n = 0;
int m = 0;
void get_area(int current_i, int current_j);
void picasso(int current_i, int current_j);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m; //세로 줄 n, 가로 줄 m
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> v[i][j];
		}
	}
	picasso(0,0);
	cout << cnt << "\n";
	cout << max_area;
}

void get_area(int current_i, int current_j)
{
	if (v[current_i][current_j] == 0 || visited[current_i][current_j]) {
		//visited[current_i][current_j] = 1;
		return;
	}

	current_area++;
	visited[current_i][current_j] = 1;
	if (current_i > 0 && (!visited[current_i - 1][current_j] && v[current_i - 1][current_j])) get_area(current_i - 1, current_j);
	get_area(current_i + 1, current_j);
	if (current_j > 0 && (!visited[current_i][current_j - 1] && v[current_i][current_j - 1])) get_area(current_i, current_j - 1);
	get_area(current_i, current_j + 1);

}
void picasso(int current_i, int current_j)
{
	/*
	각 자리들을 확인함
	세로줄 끝에 왔으면 끝남

	옆자리가 가로줄을 벗어나면 재귀호출을 current_i+1
	그게 아니면 재귀호출을 current_j+1로 부름
	넘어간 자리 벡터가 0이면 넘어감
	visited가 0인 1을 만나면 그 오른쪽을 쭉 가보고,
	오른쪽에 0을 만나면 다시 돌아가서, 밑으로 내려가고, 오른쪽 확인을 반복
	*/ 
	if (current_i == n) return;
	else
	{
		if (v[current_i][current_j] == 1 && visited[current_i][current_j] == 0)
		{
			//visited[current_i][current_j] = 1;
			get_area(current_i, current_j);
			if (current_area > max_area) max_area = current_area;
			current_area = 0;
			cnt++;
		} // 벡터 1이고 visited 0이면 넓이구하러 떠남
		 //벡터가 0이면 그냥 넘어가
		//visited[current_i][current_j] = 1;
		if (current_j + 1 < m) picasso(current_i, current_j + 1);
		else picasso(current_i + 1, 0);
	}
	/*
	처음에 쓴 방법 :
	자신의 왼쪽과 위를 확인해보고, 1과 이어져있는지 확인하고자 함
	근데 당연히 이러면 안 되겠죠?
	*/
}

