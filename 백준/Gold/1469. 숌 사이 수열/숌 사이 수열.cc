#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
bool isShorm(int *S, int n) {
	for(int i=0;i<2*n;i++) {
		if ((i+S[i]+1 < 2*n && S[i] == S[i+S[i]+1]) \
		|| (i-S[i]-1 >= 0 && S[i] == S[i-S[i]-1])) continue;
		else return false;
	}
	return true;
}*/

void backTracking(int *X, int *S, int *isUsed, int n, int cur) {
	if (cur == 2*n) {
		for(int i=0;i<2*n;i++) cout << S[i] << " ";
		exit(0);
	}
	if (S[cur] != -1) return backTracking(X, S, isUsed, n, cur+1);
	for(int i=0;i<n;i++) {
		if (!isUsed[i] && (cur + X[i] + 1 < 2*n) && \
		S[cur] == -1 && S[cur+X[i]+1] == -1) {
			S[cur] = X[i];
			S[cur + X[i] + 1] = X[i];
			isUsed[i]=1;
			backTracking(X, S, isUsed, n, cur+1);
			isUsed[i]=0;
			S[cur] = -1;
			S[cur + X[i] + 1] = -1;
		}
	}
}

int main () {
	int n;
	cin >> n;
	int X[10];
	for(int i=0;i<n;i++) cin >> X[i];
	sort(X, X+n);
	int S[20];
	int isUsed[10];
	for(int i=0;i<10;i++) {
		isUsed[i] = 0;
	}
	for(int i=0;i<20;i++) S[i] = -1;
	backTracking(X,S,isUsed,n,0);
	cout << -1;
}