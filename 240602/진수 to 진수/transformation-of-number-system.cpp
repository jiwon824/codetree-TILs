#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// a진수 n을 b진수로 바꿔서 반환하는 함수
vector<int> Conversion(int a, int b, int n){
    // a진수를 10진수로 바꾸기
    string aNum = to_string(n);
    int decimal=0;
    for(int i=aNum.length()-1;i>=0; i--){
        int lhs = aNum[i]-'0';
        int rhs = pow(a, aNum.length()-1-i);
        decimal += lhs * rhs;
    }

    // 10진수를 b진수로 바꾸기
    vector<int> bNum;
    while(decimal){
        bNum.push_back(decimal%b);
        decimal/=b;
    }

    return bNum;
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    
    vector<int> answer = Conversion(a, b, n);

    // 거꾸로 출력해야 함(진수도 거꾸로 읽으니까)
    for(int i=answer.size()-1; i>=0; i--){
        cout << answer[i];
    }

    return 0;
}