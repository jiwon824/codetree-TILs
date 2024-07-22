#include <iostream>
#define MOD 1000000007
using namespace std;

int n;
int dp[1001][10];// dp[i][j]: 길이가 i고 j로 끝나는 계단 수

int main() {
    // input
    cin >> n;

    // 초기 상태(0으로 시작하는 모든 문자열은 수로 보지 않기 때문에 1부터 초기화)
    for(int j=1; j<=9; ++j){
        dp[1][j]=1;
    }
    
    // solution
    for(int i=2; i<=n; ++i){
        for(int j=0; j<=9; ++j){
            if(j==0) dp[i][j]=dp[i-1][j+1]%MOD;
            else if(j==9) dp[i][j]=dp[i-1][j-1]%MOD;
            else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%MOD;
        }
    }

    // output
    int answer=0;
    for(int j=0; j<=9; ++j){
        answer= (answer+dp[n][j])%MOD;
    }
    cout << answer <<'\n';
    return 0;
}