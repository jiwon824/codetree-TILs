#include <iostream>

using namespace std;

int Solution(int n){
    if(n==1) return 2;
    if(n==2) return 4;
    //세 번째부터는 앞의 두 수의 곱을 100으로 나눈 나머지
    return (Solution(n-1)*Solution(n-2))%100;
}
int main() {
    int n;
    cin >> n;
    cout << Solution(n);
    return 0;
}