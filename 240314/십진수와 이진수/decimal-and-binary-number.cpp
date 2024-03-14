#include <iostream>

using namespace std;
int main() {
    string n;
    cin >>n;
    //10진수로 변경하여 17배 해주기
    int decimal=0;
    for(auto e:n) decimal= decimal<<1|e-48;
    decimal*=17;
    
    string answer="";
    // n(을 2진수로 변경하여 출력하기
    while(decimal){
        answer = char(decimal%2+48)+answer;
        decimal>>=1;
    }
    cout << answer;

    return 0;
}