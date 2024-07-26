#include <iostream>
using namespace std;

string s, t;
int dp[1001][1001];

void Init(){
    dp[0][0]=0;
    for(int i=1; i<=s.length(); ++i){
        dp[i][0]=i;
    }
    for(int j=1; j<=t.length(); ++j){
        dp[0][j]=j;
    }
}

int main() {
    // input
    cin >> s >> t;
    int n=s.length(), m=t.length();

    // init
    Init();

    // solution
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
        }
    }

    // output
    cout << dp[n][m] << '\n';

    return 0;
}