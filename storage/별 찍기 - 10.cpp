#include <iostream>
using namespace std;

void starboy(int n);
void starboy2(int n, int flag);
void starboy3(int n, int i, int j);

int main(){
    int n;
    cin >> n;
    //starboy2(n, 0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            starboy3(n, i, j);
        }
        cout<<endl;
    }
}

void starboy(int n)
{
    if (n==1) {
        cout<<"*";
        return;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (!((n/3 <= i && i < (n/3)* 2) && (n/3 <= j && j < (n/3)* 2)))
            {
                /*for(int k=0;k<(n/3)*(n/3);k++)
                {
                    //if(k>=n/3 && k%3==0) cout<<endl;
                    cout<<" ";
                }*/
                starboy(n/3);
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }//���ุ ��ġ�� �ɵ�?? 
}

void starboy2(int n, int flag)
{
    if (n==1) {
        if (flag == 1)
            cout<<"*";
        else
            cout<<" ";
        return;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int flag;
            if (!((n/3 <= i && i < (n/3)* 2) && (n/3 <= j && j < (n/3)* 2)))
                flag = 1;
            else
                flag = 0; //0�̸� ����
            starboy2(n/3, flag);
        }
        cout<<endl;
    }
}
void starboy3(int n, int i, int j)
{
    if (n==1)
    {
        if (i%3==1 && j%3==1) cout<<" ";
        else cout<<"*";
        return;
    }
    if ((i%n)/(n/3) == 1 && (j%n)/(n/3) == 1) cout<<" ";
    else starboy3(n/3, i, j);
}
/*
���� ����, n�� ���� ���� ��ġ�� i, j�� �߾� �������� ����
(nxn����� ���μ��� 3����ؼ� �߾� ����)
�߾ӿ� �ش��ϸ� ������ ����ϰ�, �ٵ� �װ� �ƴϸ�?
���ȣ���ؼ� n/3�� ���� �� �߾����� �ƴ��� Ȯ���Ѵ�
�߾ӿ� �ش��ϸ� ������ ����ϰ�, �ٵ� �װ� �ƴϸ�?
���ȣ���ؼ� n/3/3�� ���� �� �߾����� �ƴ��� Ȯ���Ѵ�
...
n�� 1�� �Ǿ��ٸ�?
���������� �� �� �� Ȯ���ϰ�, ������ �߾ӿ����� �ɸ��� �ʾҴٸ�
+�� ����ϰ� ������. �̰� nxn���� �� ���鼭 ����

ó������ .. ����Լ����� ��� ����� �ذ��Ϸ��� �ߴµ�
�� ������δ� ������ �� �� ����ϰ� �� ������ ���ƿ� ���� ����
***
* *
***<<������� ������, �� ���� ������.. ������ ���� ����
���ٴ� �̾߱�.. 
�׷��� �����ϴٰ�, ������ �ǵ��� �׳� .. Ȯ�θ�
��ͷ� �϶�°ǰ�? �; �ٲ㼭 Ǯ������ ��

*/