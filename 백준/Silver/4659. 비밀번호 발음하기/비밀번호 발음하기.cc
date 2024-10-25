#include <iostream>
#include <string>

using namespace std;

int is_vowel(char p) {
if (p == 'a' || p == 'e' || p == 'i' || p == 'o' || p == 'u') {
            return 1;
        }
        return 0;
}

int has_vowels(string password) {
    for(auto p: password) {
        if (is_vowel(p)) {
            return 1;
        }
    }
    return 0;
}
int has_three_of_consonants_or_vowles(string password) {
    if (password.length() < 2) return 0;
    for(int i=2;i<password.length();i++) {
        if (is_vowel(password[i]) && is_vowel(password[i-1]) && is_vowel(password[i-2]))
        return 1;
        if (!is_vowel(password[i]) && !is_vowel(password[i-1]) && !is_vowel(password[i-2]))
        return 1;        
    }
    return 0;
}

int has_repititive_char(string password) {
    if (password.length() < 1) return 0;
    for(int i=1;i<password.length();i++) {
        if (password[i] == password[i-1]) {
            if (password[i] != 'e' && password[i] != 'o') return 1;
        }
    }
    return 0;
}

int main() {
    while(true) {
        string password;
        cin >> password;
        // 모음 포함하기
        //모음이나 자음 연속3개는 안됨
        //같은글자 두 개는 연속 안되는데 ee oo 허용
        if (password.compare("end") == 0) break;
        string result = (has_vowels(password) && !has_three_of_consonants_or_vowles(password) && !has_repititive_char(password)) ? "acceptable" : "not acceptable";
        cout << "<" << password << "> is " << result << "." << "\n";
    }
}