#include <iostream>

using namespace std;

int n, m;
int coin[101];
int dp[10001];

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> coin[i];
    }

    //init
    dp[0]=0;
    for(int i=1; i<=m; ++i){
        dp[i]=20000;
    }

    // solution
    for(int i=1; i<=m; ++i){
        for(int j=0; j<n; ++j){
            if(i-coin[j]<0) continue;
            dp[i]=min(dp[i], dp[i-coin[j]]+1);
        }
    }

    for(int i=0; i<=m; i++){
        if(dp[i]>=20000) dp[i]=-1;
    }

    // output
    cout << dp[m] << '\n';
    
    return 0;
}