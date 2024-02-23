#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int>count;
    for(int i=0;i<tangerine.size();i++) {
        count[tangerine[i]]++;
    }
    priority_queue<int>pq;
    for(auto c : count) {
        pq.push(c.second);
    }
    while(!pq.empty() && k > 0){
        k -= pq.top();
        pq.pop();
        answer++;
    }
    return answer;
}