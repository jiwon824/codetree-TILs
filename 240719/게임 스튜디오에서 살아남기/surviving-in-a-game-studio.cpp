#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int n;
// dp[i][j][k]: i: 현재까지 고려한 날짜 (0 ~ n), j: 연속된 B의 개수 (0, 1, 2), k: 총 T의 개수 (0, 1, 2)
int dp[1001][3][3];

int main() {
    // input
    cin >> n;

    // solution
    dp[0][0][0] = 1; // 아무것도 선택하지 않은 상태
    for(int i=0; i<n; ++i){
        for(int j=0; j<3; ++j){
            for(int k=0; k<3; ++k){
                // i번째 문자가 G인 경우: 연속 B 카운트가 초기화(0), T 카운트는 유지
                dp[i+1][0][k] = (dp[i+1][0][k]+dp[i][j][k])%MOD;
                // i번째 문자가 B인 경우: 연속 B 카운트가 1 증가
                // 2개 미만이어야 연속 B개수가 3개를 넘지 않음
                if (j < 2) dp[i+1][j+1][k] = (dp[i+1][j+1][k]+dp[i][j][k])%MOD;
                // i번째 문자가 T인 경우: 연속 B 카운트가 0이 되고, T 카운트가 1 증가
                // 2개 미만이어야 T의 개수가 3개를 넘지 않음
                if (k < 2) dp[i+1][0][k+1] = (dp[i+1][0][k+1]+dp[i][j][k])%MOD;
            }
        }
    }

    // output
    // n일째의 연속B<3, T<3 개수
    int answer=0;
    for(int j=0; j<3; ++j){
        for(int k=0; k<3; ++k){
            answer = (answer+dp[n][j][k])%MOD;
        }
    }
    cout << answer << '\n';
    return 0;
}