#include <iostream>
using namespace std;

int n, m;
int treasure[1001][101]; // treasure[n][m]

// dp[i][j]: i번째 층까지 고려, 마지방으로 고른 방이 j일 때 보물의 최대 개수
int dp[1001][101];

void Init(){
    for(int i=0; i<=n; ++i){
        for(int j=0; j<m; ++j){
            dp[i][j]=-1;
        }
    }
}

int main() {
    // input
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        for(int j=0; j<m; ++j){
            cin >> treasure[i][j];
        }
    }

    // init
    Init();

    // solution
    // 1. 초기 상태
    for(int j=0; j<m; ++j){
        dp[1][j]=treasure[1][j];
    }

    // 2. 상태 전이
    // i층에서 j방에, i-1층에서 k방에 들어가는 경우
    for(int i=2; i<=n; ++i){
        for(int j=0; j<m; ++j){
            for(int k=0; k<m; ++k){
                // i-1층에서 들어갔던 방과 같은 방은 불가능
                if(j==k || dp[i-1][k]==-1) continue;
                dp[i][j]= max(dp[i][j], dp[i-1][k]+treasure[i][j]);
            }
        }
    }

    // output
    int answer=0;
    for(int j=0; j<m; ++j){
        answer = max(answer, dp[n][j]);
    }
    cout << answer <<'\n';
    return 0;
}