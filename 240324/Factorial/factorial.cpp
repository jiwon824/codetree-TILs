#include <iostream>

using namespace std;
int Factorial(int n){
    if(n<=1) return 1;
    if(n==2) return 2;
    if(n==3) return 6;
    return n * Factorial(n-1);
}
int main() {
    int n;
    cin >> n;
    cout << Factorial(n);
    return 0;
}