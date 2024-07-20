#include <iostream>
using namespace std;

int n;
int soccer[1001];
int baseball[1001];
// 축구팀은 11명, 야구팀은 9명으로 구성
// dp[i][j][k]: i번째까지 고려, 축구팀 j명, 야구팀 k명 
int dp[1001][12][10];

void Init(){
    for(int i=1; i<n; ++i){
        for(int j=0; j<12; ++j){
            for(int k=0; k<10; ++k){
                dp[i][j][k] =-1;
            }
        }
    }
    dp[0][0][0] = 0;  // 아무도 선택하지 않은 상태
}

int main() {
    // input
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> soccer[i] >> baseball[i];
    }
    
    // init
    Init();

    // solution
    for(int i=1; i<=n; ++i){
        for(int j=0; j<=11; ++j){
            for(int k=0; k<=9; ++k){
                // 현재 학생을 뽑지 않는 경우
                if(dp[i-1][j][k]!=-1) dp[i][j][k]= max(dp[i][j][k], dp[i-1][j][k]);
                // 현재 학생을 축구팀에 넣는 경우
                if(j>=1 && dp[i-1][j-1][k]!=-1) dp[i][j][k]= max(dp[i][j][k], dp[i-1][j-1][k]+soccer[i]);
                // 농구팀에 넣는 경우
                if(k>=1 &&dp[i-1][j][k-1]!=-1) dp[i][j][k]= max(dp[i][j][k], dp[i-1][j][k-1]+baseball[i]);
            }
        }
    }

    // output
    cout << dp[n][11][9] << '\n';
    return 0;
}