#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 10진수인 정수 n을 b진수로 변경하여 출력하는 프로그램
int main() {
    //  b로 주어지는 진수는 4, 8 (2가지)
    int n, b;
    cin >> n >> b;
    vector<int> answer;
    while(n){
        int disit = n%b;
        answer.push_back(disit);
        n/=b;
    }
    reverse(answer.begin(), answer.end());
    
    for(auto e : answer){
        cout << e;
    }
    return 0;
}