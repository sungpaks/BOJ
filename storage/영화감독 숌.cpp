#include <iostream>
#include <ctime>
using namespace std;

int search(int n);

int main(){
    int n;
    cin >> n;
    cout << search(n) << endl;
}
int search(int n)
{
    int i = 0;
    int result = 665;
    while(i < n)
    {
        result++;
        int divider = 1;
        while ((result / divider) > 100)
        {
            if ((result / divider) % 10 == 6)
            {
                if ((result / divider / 10) % 10 == 6)
                {
                    if ((result / divider / 100) % 10 == 6)
                    {
                        i++;
                        break;
                    }
                }
            }
            divider *= 10;
        }
    }
    return result;
}
/*
모냥새가 좀 부끄럽긴하지만..
저 고졸이니까 봐주세요 ^^
*/

/*
귀찮으니까 그냥 돌면서 확인하기로함..
브루트포스니까 이 방법으로 하라는거지 않을까?
다른 방법이 있을지는 잘 몰겠지만
*/