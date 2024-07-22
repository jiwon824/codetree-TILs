#include <iostream>
using namespace std;

int n, m;
string crystalPos="";
// dp[i][j][k]: i번째까지 고려, j번 이동하고 현재 위치가 k일 때 수집할 수 있는 최대 수정 
int dp[1001][21][2];

void Init(){
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=m; ++j){
            for(int k=0; k<2; ++k){
                dp[i][j][k] = -1;
            }
        }
    }
}

int main() {
    // input
    cin >> n >> m;
    cin >>crystalPos;

    // init
    Init();

    // 초기상태 (초기에 왼쪽 샘터 앞에 서있음)
    if(crystalPos[0] == 'L') {
        dp[1][0][0] = 1; // 왼쪽에서 수정 수집
        dp[1][1][1] = 0; // 오른쪽으로 이동한 상태
    } else {
        dp[1][0][0] = 0; // 왼쪽에 그대로 있는 상태
        dp[1][1][1] = 1; // 오른쪽에서 수정 수집
    }

    // solution
    for(int i=1; i<n; ++i){
        for(int j=0; j<=m; ++j){
            for(int k=0; k<2; ++k){
                if(dp[i][j][k] == -1) continue;
                
                int nextPos= (crystalPos[i]=='L') ? 0:1;

                // 이동x
                if(nextPos==k){
                    // 수정을 먹음
                    dp[i+1][j][k]=max(dp[i+1][j][k], dp[i][j][k]+1);
                }
                else{
                    // 위치가 달라서 수정 못 먹음
                    dp[i+1][j][k]=max(dp[i+1][j][k], dp[i][j][k]);
                }

                // 이동해서 수정 먹기
                if(j+1<=m){
                    dp[i+1][j+1][nextPos]=max(dp[i+1][j+1][nextPos], dp[i][j][k]+1);
                }
            }
        }
    }

    // output
    int answer=0;
    for(int j=0; j<=m; ++j){
        for(int k=0; k<2; ++k){
            answer = max(answer, dp[n][j][k]);
        }
    }
    cout << answer <<'\n';

    return 0;
}