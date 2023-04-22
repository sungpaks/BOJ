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
5kg를 n/5만큼 들고 시작한다
n/5이 나누어 떨어지면 그대로 가면 되겠지만??
n/5이 나누어 떨어지지 않으면 정수라서 소숫점이 버려지므로
(int)n/5는 항상 (double)n/3보다 작거나 같음

이제.. 합이 n보다 크면? 5키로 하나 덜고,
합이 n보다 작으면?? 3키로 하나 들고
근데 kg3이 개많아지면?? -1
*/