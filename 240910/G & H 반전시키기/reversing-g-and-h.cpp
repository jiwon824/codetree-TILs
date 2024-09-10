#include <iostream>
using namespace std;

int n;
string initStr, targetStr;

int main() {
    cin >> n >> initStr >> targetStr;

    // 목표 str과 다른 문자 그룹의 수(answer)
    int checkIdx=0, answer=0;
    while(checkIdx<n){
        // 다르면 
        if(initStr[checkIdx]!=targetStr[checkIdx]){
            while(checkIdx+1<n && initStr[checkIdx]!=targetStr[checkIdx]){
                checkIdx++;
            }
            answer++;
        }
        checkIdx++;
    }
    cout << answer << '\n';
    return 0;
}