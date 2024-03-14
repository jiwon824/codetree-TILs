#include <iostream>

using namespace std;
int main() {
    // 자연수이며 최대 자리수가 1000 자리인, 이진수로 표현된 숫자 N이 공백 없이 주어집니다.
    string n;
    cin >>n;
    string a=n+"0000", b="0000"+n, answer="";
    int carry =0;
    for(int i=a.length()-1;i>=0;i--){
        int tmp =(a[i]-'0')+(b[i]-'0')+carry;
        switch(tmp){
            case 0:
                answer = '0'+answer;
                carry=0;
                break;
            case 1:
                answer = '1'+answer;
                carry = 0;
                break;
            case 2:
                answer='0'+answer;
                carry=1;
                break;
            case 3:
                answer='1'+answer;
                carry =1;
                break;
            default:
                break;
        }
    }
    if (carry==1) answer='1'+answer;
    
    cout << answer;
    return 0;
}