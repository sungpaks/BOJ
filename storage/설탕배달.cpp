#include <iostream>
using namespace std;

int bts_sugar(int n);

int main(){
    int n;
    cin >> n;
    cout << bts_sugar(n) << endl;
}

int bts_sugar(int n)
{

    int kg3 = 0;
    int kg5 = n / 5;
    while ((kg5 * 5) + (kg3 * 3) != n)
    {
        if ((kg5 * 5) + (kg3 * 3) > n)
            kg5--;
        else if ((kg5 * 5) + (kg3 * 3) < n)
            kg3++;

        if (kg3 > n / 3) return (-1);
    }
    return (kg5 + kg3);
}

/*
5kg�� n/5��ŭ ��� �����Ѵ�
n/5�� ������ �������� �״�� ���� �ǰ�����??
n/5�� ������ �������� ������ ������ �Ҽ����� �������Ƿ�
(int)n/5�� �׻� (double)n/3���� �۰ų� ����

����.. ���� n���� ũ��? 5Ű�� �ϳ� ����,
���� n���� ������?? 3Ű�� �ϳ� ���
�ٵ� kg3�� ����������?? -1
*/