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
a, b, c�� ���� ū ���� ������ �� ���� �պ��� ������
�ﰢ�� ���� �� ����
==> ������������ �����ϰ�, �ִ��� ������ �� ���� �պ���
�۾��� ������ while�����鼭 �ִ��� �ٿ���
*/