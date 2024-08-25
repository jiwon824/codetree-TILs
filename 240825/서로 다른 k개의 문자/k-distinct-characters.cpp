#include <iostream>
#include <unordered_map>
using namespace std;

string str;
int k;
unordered_map<char, int> um;

bool CanInsert(char c){
    // 1. 이미 um에 있는 문자인 경우
    if(um.find(c)!=um.end() && um.size()<=k) return true;
    // 2. 새로운 문자인 경우
    if(um.find(c)==um.end() && um.size()<k) return true;
    return false;
}
int main() {
    cin >> str >> k;
    int n=str.length();

    int r=0, answer=0;
    for(int l=0; l<n; ++l){
        while(r<n && CanInsert(str[r])){
            um[str[r]]++;
            r++;
        }
        
        if(r<l) break;
        answer = max(answer, r-l);

        if(um[str[l]]==1) um.erase(str[l]);
        else um[str[l]]--;
    }
    cout << answer << '\n';
    return 0;
}