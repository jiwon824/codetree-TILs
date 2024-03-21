#include <iostream>

using namespace std;
bool IsMagicNumber(int n){
    if(n%2==0){
        int number=0;
        while (n>0){
            number+= n%10;
            n/=10;
        }
        if(number%5==0) return true;
        else return false;
    }
    return false;
}
int main() {
    int n;
    cin >>n;
    if(IsMagicNumber(n)) cout << "Yes";
    else cout << "No";
    return 0;
}