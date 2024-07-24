#include <iostream>
using namespace std;

string a, b;
// dp[i][j]: 문자a i번째와 문자b j번째까지 비교했을 때 최대 공통 부분 수열의 길이
int dp[1001][1001];

int main() {
    // input
    cin >> a >> b;

    // solution
    for(int i=1; i<=a.length(); ++i){
        for(int j=1; j<=b.length(); ++j){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // output
    cout << dp[a.length()][b.length()] << '\n';
    return 0;
}