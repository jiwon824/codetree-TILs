#include <iostream>

using namespace std;
int Sum(int n){
    if (n<10) return n;
    return Sum(n/10)+ (n%10);
}
int main() {
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    int parameter = num1*num2*num3;
    cout << Sum(parameter);
    return 0;
}