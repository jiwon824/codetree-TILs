#include <iostream>

using namespace std;
void PrintGCD(int n, int m){
    while(n*m != 0){
        if(n>m) n=n%m;
        else m=m%n;
    }
    cout << n+m;
}
int main() {
    int n, m;
    cin >> n >>m;
    PrintGCD(n, m);
    return 0;
}