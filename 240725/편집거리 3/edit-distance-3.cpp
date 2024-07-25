#include <iostream>
using namespace std;

string a, b;
int dp[1001][1001];

int main() {
    // input
    cin >> a >> b;
    int n=a.length(), m=b.length();

    // solution
    // 1. 초기 설정
    for(int i=0; i<=n; ++i){
        dp[i][0]=i;
    }
    for(int j=0; j<=m; ++j){
        dp[0][j]=j;
    }
    // 2. 상태 전이
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            // a[i]와 b[j]가 같은 경우
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
            else{
                // 다른 경우
                dp[i][j]=min(dp[i-1][j], dp[i][j-1])+1;
            }
        }
    }

    // output
    cout << dp[n][m] << '\n';
    return 0;
}