#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n[3] = {0};
    for(int i=0;i<=2;i++) cin >> n[i];
    sort(n, n+3);
    while (n[2] >= n[1] + n[0])
    {
        n[2]--;
    }
    cout << n[0] + n[1] + n[2] << endl;
}

/*
a, b, c중 가장 큰 값이 나머지 두 변의 합보다 작으면
삼각형 만들 수 있음
==> 내림차순으로 정렬하고, 최댓값이 나머지 두 값의 합보다
작아질 때까지 while돌리면서 최댓값을 줄여줌
*/