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
    }//개행만 고치면 될듯?? 
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
                flag = 0; //0이면 공백
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
가장 먼저, n에 대해 현재 위치인 i, j가 중앙 영역인지 본다
(nxn사이즈를 가로세로 3등분해서 중앙 영역)
중앙에 해당하면 공백을 출력하고, 근데 그게 아니면?
재귀호출해서 n/3에 대해 또 중앙인지 아닌지 확인한다
중앙에 해당하면 공백을 출력하고, 근데 그게 아니면?
재귀호출해서 n/3/3에 대해 또 중앙인지 아닌지 확인한다
...
n이 1이 되었다면?
마지막으로 한 번 더 확인하고, 끝까지 중앙영역에 걸리지 않았다면
+을 출력하고 끝낸다. 이걸 nxn동안 쭉 돌면서 ㄱㄱ

처음에는 .. 재귀함수에서 모든 출력을 해결하려고 했는데
이 방법으로는 패턴을 한 번 출력하고 그 옆으로 돌아올 길이 없다
***
* *
***<<여기까지 왔으면, 그 다음 패턴을.. 옆에다 놓을 수가
없다는 이야기.. 
그래서 생각하다가, 문제의 의도가 그냥 .. 확인만
재귀로 하라는건가? 싶어서 바꿔서 풀었더니 됨

*/