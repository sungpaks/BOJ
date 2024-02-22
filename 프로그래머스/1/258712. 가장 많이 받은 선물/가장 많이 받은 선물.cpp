#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

int gifts_exchanged[51][51];
int nextMonth[51];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    // 이름 -> 인덱스 해시맵
    map<string, int>nameToIndex;
    for(int i=0;i<friends.size();i++) nameToIndex[friends[i]] = i;
    
    //선물 주고받은 테이블 생성
    for(int i=0;i<gifts.size();i++) {
        string given, taken;
        stringstream ss(gifts[i]);
        ss >> given >> taken;
        gifts_exchanged[nameToIndex[given]][nameToIndex[taken]]++;
    }
    
    // 선물 지수 구하기
    int gifts_factor[51] = {0,};
    for(int i=0;i<friends.size();i++) {
        for(int j=0;j<friends.size();j++) {
            gifts_factor[i] += gifts_exchanged[i][j];
            gifts_factor[j] -= gifts_exchanged[i][j];
        }
    }
    
    //모든 친구들에 대한 다음달 선물 예상 갯수 계산
    for(int i=0;i<friends.size();i++) {
        for(int j=0;j<friends.size();j++) {
            if (i == j) continue;
            if (gifts_exchanged[i][j] == 
                gifts_exchanged[j][i]) {
                if (gifts_factor[i] > gifts_factor[j]) nextMonth[i]++;
                //else if (gifts_factor[i] < gifts_factor[j]) nextMonth[j]++;
            }
            // i->j 준 선물이 j->i 준 선물보다 큰 경우 : i가 받을 차례
            else if (gifts_exchanged[i][j] > 
                gifts_exchanged[j][i]) nextMonth[i]++;
            //else nextMonth[j]++;
        }
    }
    for(int i=0;i<friends.size();i++) {
        if (answer < nextMonth[i]) answer = nextMonth[i];
    }
    
    return answer;
}