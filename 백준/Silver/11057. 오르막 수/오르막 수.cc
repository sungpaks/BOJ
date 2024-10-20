#include <iostream>

using namespace std;

int lastNumbers[1001][10];

int main () {
    int n;
    cin >> n;
    for(int i=0;i<10;i++) lastNumbers[1][i] = 1;
    for(int i=2;i<=n;i++) {
        lastNumbers[i][0] = 1;
        for(int j=1;j<10;j++) {
            for(int k=0;k<=j;k++) {
                lastNumbers[i][j] = (lastNumbers[i][j] + lastNumbers[i-1][k])%10007;
            }
        }
    }
    int result = 0;
    for(int i=0;i<10;i++) {
        //cout << lastNumbers[n][i] << " ";
        result = (result + lastNumbers[n][i])%10007;
    }
    cout << result;
}

/*
1 => 0,1,2,3,4,5,6,7,8,9
2 => 10,9,8,7,6,5,4,3,2,1
그 뒤에는, 0은 하나, 1은 2, 2는 3개, ..
 */