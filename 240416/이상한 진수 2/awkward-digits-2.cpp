#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string n;
    cin >> n;

    // 0이 있다면 가장 왼쪽에 있는 0을 1로 바꾼다.
    // 0이 없다면 가장 오른쪽에 있는 1을 0으로 바꾼다.
        // 1010 ->1110
        // 1000 ->1100
        // 1111 ->1110
    bool exist_zero =false;
    for(int i=0; i<n.length();i++){
        if(n[i] =='0') {
            exist_zero =true;
            n[i]='1';
            break;
        }
    }
    if(!exist_zero) n[n.length()-1]='0';

    //2진수를 10진수로 바꿔서 출력한다.
    int answer=0;
    for(int i=n.length()-1; i>=0; i--){
        answer = answer+ (n[i]-'0') * pow(2, n.length()-1-i);
        //cout << n.length()-1-i <<'\n';
    }
    cout << answer;
    return 0;
}