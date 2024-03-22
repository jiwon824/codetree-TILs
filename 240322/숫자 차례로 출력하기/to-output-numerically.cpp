#include <iostream>

using namespace std;
void Forward(int n){
    if (n==0) return;
    Forward(n-1);
    cout << n << " ";
}
void Backward(int n){
    if (n==0) return;
    cout << n << " ";
    Backward(n-1);
}
int main() {
    int n;
    cin >> n;
    Forward(n);
    cout << "\n";
    Backward(n);
    return 0;
}