#include <iostream>

using namespace std;
int Solution(int n){
    if (n==1) return 1;
    if (n==2) return 2;
    return n + Solution(n-2);
}
int main() {
    int n;
    cin >> n;
    cout << Solution(n);
    return 0;
}