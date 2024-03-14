#include <iostream>

using namespace std;
int main() {
    // 자연수이며 최대 자리수가 1000 자리인, 이진수로 표현된 숫자 N이 공백 없이 주어집니다.
    string n;
    cin >>n;
    string answer =n;
    answer= answer + "0000";
    n="0000"+n;
    int carry =0;
    for(int i=answer.length()-1;i>=0;i--){
        int tmp =(answer[i]-'0')+(n[i]-'0')+carry;
        switch(tmp){
            case 0:
                carry=0;
                break;
            case 1:
                answer[i] = '1';
                carry = 0;
                break;
            case 2:
                answer[i]='0';
                carry=1;
                break;
            case 3:
                answer[i]='1';
                carry =1;
                break;
            default:
                break;
        }
    }
    cout << answer;
    return 0;
}