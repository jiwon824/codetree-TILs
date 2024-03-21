#include <iostream>

using namespace std;
bool IsPrimeNum(int n){
    for(int i=2;i<n/2;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main() {
    int a, b;
    cin >> a >> b;
    int answer=0;
    for(int i=a; i<=b;i++){
        if(IsPrimeNum(i)) answer += i;
    }
    cout << answer;
    return 0;
}