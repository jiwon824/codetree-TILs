#include <iostream>

using namespace std;
int main() {
    int a=5, b=6, c=7;
    int tmp;
    tmp=a; //5
    a=c; //7
    c=b; // 6
    b=tmp; //5
    cout << a <<"\n" <<b <<"\n" <<c <<"\n";
    return 0;
}