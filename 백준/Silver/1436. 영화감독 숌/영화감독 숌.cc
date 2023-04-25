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