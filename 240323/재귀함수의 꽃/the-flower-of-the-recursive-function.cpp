#include <iostream>

using namespace std;
void Rotate(int n){
    if(n==0) return;
    cout << n << " ";
    Rotate(n-1);
    cout << n << " ";
}
int main() {
    int n;
    cin >> n;
    Rotate(n);
    return 0;
}