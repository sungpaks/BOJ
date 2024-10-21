#include <iostream>

using namespace std;

int cities[10001];
int n;

long long allocateBudget(int curBudget) {
    long long result = 0;
    for(int i=0;i<n;i++) {
        result += (cities[i] > curBudget ? curBudget : cities[i]);
    }
    return result;
}

int main() {
    long long budget;
    cin >> n;
    int max = 0;
    for(int i=0;i<n;i++) {
        cin >> cities[i];
        if (cities[i] > max) max = cities[i];
    }
    cin >> budget;

    int left = 0;
    int right = max;
    int mid = (budget+left)/2;
    while(left <= right) {
        long long allocated = allocateBudget(mid);
         if (allocated > budget) {
            //초과. right를 줄이기
            right = mid-1;
        }
        else {
            //left를 올려보기
            left = mid+1;
        }
        mid = (left + right)/2;
    }
    cout << right;
}