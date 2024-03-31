#include <iostream>

using namespace std;

int Solution(int n){
    if(n==1) return 0;
    if (n%2==0) return Solution(n/2)+1;
    else return Solution(n*3+1)+1;
}
int main() {
    int n;
    cin >> n;
    cout << Solution(n);
    return 0;
}