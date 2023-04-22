#include <iostream>
#include <ctime>
using namespace std;

//void get_bridge(int* left, int* right, int &cnt, int current);
long long get_comb(long long m, long long n);

int main(){
    int n, m;
    cin >> n >> m;
    clock_t start, finish;
    
    start = clock();

    long long cnt = get_comb(m, n);
    //mCn�� ���ϸ� ��

    finish = clock();
    cout << cnt << endl;
    cout << (double)(finish - start)/CLOCKS_PER_SEC << endl;
}

long long get_comb(long long m, long long n)
{
    if (n == 0) return 1;
    if (m == n) return 1;
    return (get_comb(m-1, n-1) + get_comb(m-1, n));
}
/*
void get_bridge(int *left, int *right, int &cnt, int current)
{
    if (*left == -1) 
    {
        cnt++;
        return;
    }
    else if (right[current] == -1)
        return;

    while (right[current] != -1)
    {
        if (right[current] == 0){
            *left = 1;
            right[current] = 1;
            get_bridge(left+1, right, cnt, current+1);
            *left = 0;
            right[current] = 0;
        }
        current++;
    }
}
*/

/*n�� ����ó�� ����Ž��?��Ʈ��ŷ? �ణ �׷���������
Ǯ���µ� �ð��� �ʹ� ���� �ɸ��°�.. 13 29 �ϸ�
���� 2��? �׷��� ��.. ���� �ʹ� ��ȿ�������� Ǯ����
�; �� �ô���?? �׳� mCn ���� ���ϸ� �Ǵ°ſ���
�����޾�����.. mCn ���ϴ� �Լ��� ���� Ǯ�����ϴ�
�ٵ� �� ��ó������ mCn�� m!/(n!*(m-n)!) �̷�������
���丮�� �Լ��� ��������� �Ϲݽ����� Ǫ�ϱ�
�������� �ʾ�Ŀ�� ���� �� ���� ���淡..
�ٸ���� ã�ƺ��ϱ� C(n, r) = C(n-1, r-1) + C(n-1, r)
�̷� ������� �ִٰ� ����Ƽ�� �˷����
�׷��� �׷��� Ǯ������ 13 29 ���� ������ 0.3�ʵ� �� �ɷȴ�
20230417
*/
