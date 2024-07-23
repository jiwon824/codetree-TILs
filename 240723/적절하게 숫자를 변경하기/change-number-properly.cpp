#include <iostream>
using namespace std;

int n, m;
int arr[501];

// dp[i][j][k]: i까지 살펴봤을 때 인접한 두 숫자가 다른 횟수가j, 마지막 숫자가 k인 비슷한 수열의 유사도 
// (1<=k<=4)
int dp[501][101][5];

void Init(){
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=m; ++j){
            for(int k=1; k<=4; ++k){
                dp[i][j][k]=-1;
            }
        }
    }
}

int main() {
    // input
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        cin >> arr[i];
    }
    
    // init
    Init();

    // solution
    // 1. 초기 설정
    for(int k=0; k<=9; ++k){
        if(arr[1]==k) dp[1][0][k]= 1;
        else dp[1][0][k]= 0;
    }
    // 2. 상태 전이
    for(int i=2; i<=n; ++i){
        for(int j=0; j<=m; ++j){
            for(int k=1; k<=4; ++k){
                // arr[i]랑 같은 경우 = 유사도+1
                if(arr[i]==k){

                    // i-1이랑 숫자가 같은 경우
                    if(dp[i-1][j][k]!=-1) dp[i][j][k]= max(dp[i][j][k], dp[i-1][j][k]+1);
                    
                    // i-1이랑 숫자가 다른 경우
                    if(j>0){
                        for(int prev=1; prev<=4; ++prev){
                            if(k==prev || dp[i-1][j-1][prev] == -1) continue;
                            dp[i][j][k]= max(dp[i][j][k], dp[i-1][j-1][prev]+1);
                        }
                    }
                }
                else{
                    if(dp[i-1][j][k]!=-1) dp[i][j][k]= max(dp[i][j][k], dp[i-1][j][k]);
                }
            }
        }
    }

    // output
    int answer=0;
    for(int j=0; j<=m; ++j){
        for(int k=1; k<=4; ++k){
            answer=max(answer, dp[n][j][k]);
        }
    }
    cout << answer << '\n';
    return 0;
}