#include <iostream>
#include <vector>

using namespace std;

vector<char>board[51];

char init;
//int cnt = 0;
int min_cnt = 100;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			char c;
			cin >> c;
			board[i].push_back(c);
		}
	}
	for(int i=0;i<n-7;i++)
	{
		for(int j=0;j<m-7;j++)
		{
			init = board[i][j];
			int cnt = 0;
			for(int ii = i; ii<i+8;ii++)
			{
				for(int jj = j; jj<j+8; jj++)
				{
					if (ii%2 - jj%2 == 0 && board[ii][jj] != init) cnt++;
					else if (ii%2 - jj%2 != 0 && board[ii][jj] == init) cnt++;
				}
			}
			if (min_cnt > cnt) min_cnt = cnt;
			if (64 - cnt < min_cnt) min_cnt = 64 - cnt;
		}
	}
	cout << min_cnt;
}