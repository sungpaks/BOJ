#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	priority_queue<int> pq;
	while (t--)
	{
		int j, n;
		cin >> j >> n;
		for (int i = 0; i < n; i++)
		{
			int w, h;
			cin >> w >> h;
			pq.push(w * h);
		}
		int cnt = 0;
		while (!pq.empty() && j > 0)
		{
			j -= pq.top();
			pq.pop();
			cnt++;
		}
		cout << cnt << "\n";
		while(!pq.empty()) pq.pop();
	}
}