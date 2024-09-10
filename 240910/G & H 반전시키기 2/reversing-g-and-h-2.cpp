#include <iostream>
using namespace std;

int n;
string initStr, targetStr;

void Change(int idx){
    for(int i=0; i<=idx;++i){
        if(initStr[i]=='G') initStr[i]='H';
        else initStr[i]='G';
    }
}

int main() {
    cin >> n;
    cin >> initStr >> targetStr;
    
    int answer=0;
    for(int i=n-1; i>=0; --i){
        if(initStr[i]!=targetStr[i]){
            Change(i);
            answer++;
        }
    }    
    cout << answer << '\n';
    return 0;
}