#include <iostream>

using namespace std;

int MySqrt(int a, int b){
    int answer = 1;
    while(b--){
        answer = answer*a;
    }
    return answer;
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << MySqrt(a, b);
    return 0;
}