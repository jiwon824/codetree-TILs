#include <iostream>

using namespace std;

bool IsThreeSixNine(int n){
    while(n>0){
        if (n%10 == 3 || n%10 == 6 || n%10 == 9) return true;
        n/=10;
    }
    return false;
}
bool IsMagicNumber(int n){
    if(n%3==0 || IsThreeSixNine(n)) return true;
    return false;
}
int main() {
    int a, b;
    cin >>a>>b;
    int answer =0;
    for (int i=a;i<=b;i++){
        if(IsMagicNumber(i)) answer++;
    }
    cout << answer;
    return 0;
}