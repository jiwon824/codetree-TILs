#include <iostream>

using namespace std;

int n;
int dp[1001];

// 2 × n 크기의 사각형을 채우는 방법의 수를 10,007로 나눈 나머지
int main() {
    cin >> n;
    dp[0]=1;
    dp[1]=3;
    
    for(int i=2; i<n; ++i){
        dp[i]=(dp[i-2]*2+dp[i-1])%10007;
    }
    
    cout << dp[n-1] << '\n';
    
    return 0;
}