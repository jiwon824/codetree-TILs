#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 이진수로 표현되는 N이 주어지면 십진수로 바꿔 17배를 하고 다시 이진수로 나타내어 출력
int main() {
    string n;
    cin >> n;
    vector<int> binary;
    // 10진수로 변환, 17배
    int num = 0;
    for(int i = 0; i < n.length(); i++)
        num = num * 2 + (n[i]-'0');
    num *=17;
    // 2진수 변환
    while (num){
        int disit = num%2;
        binary.push_back(disit);
        num/=2;
    }
    
    reverse(binary.begin(), binary.end());
    for(auto e: binary){
        cout << e;
    }
    return 0;
}