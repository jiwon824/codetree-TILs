#include <iostream>
using namespace std;

const int MAX_N = 100001;

int dp[MAX_N];

int main() {
    int n;
    cin >> n;

    fill_n(dp, n+1, 2e9);
    
    dp[2]=1;
    dp[5]=1;
    for(int i=0; i<=n; ++i){
        if(i>=2 && dp[i-2]!=-1) dp[i]=min(dp[i], dp[i-2]+1);
        if(i>=5 && dp[i-5]!=-1) dp[i]=min(dp[i], dp[i-5]+1);
    }
    
    if(dp[n]==2e9) cout << -1 << '\n';
    else cout << dp[n] << '\n';

    return 0;
}