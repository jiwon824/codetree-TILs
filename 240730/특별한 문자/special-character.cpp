#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


int main() {
    // 문자열 입력
    string str;
    cin >> str;

    // key:문자 value: 해당 문자가 등장한 횟수
    unordered_map<char, int> um;
    for(int i=0; i<str.length(); ++i){
        um[str[i]]++;
    }
    
    // output
    for(int i=0; i<str.length(); ++i){
        if(um[str[i]]==1){
            cout << str[i] << '\n';
            break;
        }
    }
    return 0;
}