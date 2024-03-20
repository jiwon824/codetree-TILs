#include <iostream>

using namespace std;
int GCD (int n, int m){
    while (n*m!=0){
        if(n>m) n=n%m;
        else m=m%n;
    }
    return n+m;
}
void PrintLCM(int n, int m){
    cout << n*m/GCD(n, m);
}
int main() {
    int n, m;
    cin >>n>>m;
    PrintLCM(n, m);
    return 0;
}