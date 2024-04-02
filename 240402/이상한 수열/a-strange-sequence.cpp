#include <iostream>

using namespace std;
int Solution(int n){
    if (n==1) return 1;
    if (n==2) return 2;
    return Solution(n/3)+Solution(n-1);
}
int main() {
    int n;
    cin >> n;
    cout << Solution(n);
    return 0;
}