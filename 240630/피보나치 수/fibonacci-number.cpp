#include <iostream>

using namespace std;

int dp[50];

int main() {
    int n;
    cin >> n;

    dp[0]=1;
    dp[1]=1;
    for(int i=2; i<n; i++){
        dp[i]=dp[i-2]+dp[i-1];
    }
    
    cout << dp[n-1] << '\n';

    return 0;
}