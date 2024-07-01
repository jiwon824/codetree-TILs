#include <iostream>

using namespace std;

int dp[1001];

int main() {
    int n;
    cin >> n;
    
    dp[1]=1; // 2층 높이 계단
    dp[2]=1; // 3층 높이 계단
    
    for(int i=3; i<n; ++i){
        dp[i]=(dp[i-2]+dp[i-3])%10007;
    }

    cout << dp[n-1]<<'\n';
    return 0;
}