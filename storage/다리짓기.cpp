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
    //mCn만 구하면 됨

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

/*n퀸 문제처럼 깊이탐색?백트래킹? 약간 그런느낌으로
풀었는데 시간이 너무 많이 걸리는거.. 13 29 하면
거의 2초? 그래서 엥.. 내가 너무 비효율적으로 풀었나
싶어서 쭉 봤더니?? 그냥 mCn 조합 구하면 되는거였음
개열받았지만.. mCn 구하는 함수를 만들어서 풀었습니다
근데 또 맨처음에는 mCn을 m!/(n!*(m-n)!) 이런식으로
팩토리얼 함수를 만든다음에 일반식으로 푸니까
스케일이 너어어무커서 감당 할 수가 없길래..
다른방법 찾아보니까 C(n, r) = C(n-1, r-1) + C(n-1, r)
이런 관계식이 있다고 지피티가 알려줬다
그래서 그렇게 풀었더니 13 29 예시 넣으면 0.3초도 안 걸렸다
20230417
*/
