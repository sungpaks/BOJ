#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;


string* parseWord(string str) {
    string *result = new string[3];
    int i = 0;
    while(str[i] != ' ') {
        result[0] += str[i++];
    }
    i++;
    while(str[i] && str[i] != ' ') {
        result[1] += str[i++];
    }
    if (!str[i]) return result;
    i++;
    while(str[i]) {
        result[2] += str[i++];
    }
    
    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string>users;
    for(string r : record) {
        string* word = parseWord(r);
        if (word[0] == "Enter") {
            answer.push_back(word[1] + "/님이 들어왔습니다.");
            users[word[1]] = word[2];
        }
        else if (word[0] == "Leave") {
            answer.push_back(word[1] + "/님이 나갔습니다.");
        }
        else if (word[0] == "Change") {
            users[word[1]] = word[2];
        }
        //delete(word);
    }
    for(int i = 0; i<answer.size();i++) {
        string uid;
        int j = 0;
        while(answer[i][j] != '/') {
            uid += answer[i][j++];
        }
        answer[i] = users[uid] + answer[i].substr(j+1);
    }
    return answer;
}