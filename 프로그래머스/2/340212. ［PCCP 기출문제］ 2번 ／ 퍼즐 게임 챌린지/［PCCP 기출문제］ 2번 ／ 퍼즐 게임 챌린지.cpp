#include <string>
#include <vector>

using namespace std;

long long getPuzzleTime(int level, vector<int> diffs, vector<int> times) {
    long long time = times[0]; //처음엔 무조건 diff 1이니까 풀 수 있음.
    for(int i=1;i<times.size();i++) {
        if (diffs[i] <= level) time += times[i];
        else time += (long long)(times[i] + times[i-1]) * (long long)(diffs[i] - level) + (long long)times[i];
    }
    return time;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int right = 100000;
    int left = 1;
    int mid = (right+left)/2;
    while(left <= right) {
        long long curTime = getPuzzleTime(mid, diffs, times);
        if (curTime <= limit) {
            //limit 내인가? right를 더 줄여보자.
            right = mid-1;
        }
        else {
            //limit 넘겼나? left를 줄여보자.
            left = mid + 1;
        }
        mid = (right+left)/2;
    }
    
    return left;
}

// diff <= level이면, 틀리지 않으니 time_cur만큼만
// diff > level이면, diff-level번 틀리므로, (time_cur + time_prev)*(diff-level) + time_cur 만큼
//limit 내에 퍼즐을 모두 해결할 수 있는 level의 최솟값을 구해라.
// 숙련도는 무조건 양의정수, 맨 처음 diff는 무조건 1이므로, 이전퍼즐을 몰라도 됨
