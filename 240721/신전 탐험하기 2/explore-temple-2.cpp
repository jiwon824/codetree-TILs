#include <iostream>
using namespace std;

int n;
int treasure[1001][3];

// dp[i][j][k]: i층에서 j방향 선택, 1층에서 k방향 선택했을 때 최대 보물 개수
int dp[1001][3][3];

void Init(){
    for(int i=0; i<=n; ++i){
        for(int j=0; j<3; ++j){
            for(int k=0; k<3; ++k){
                dp[i][j][k]=-1;
            }
        }
    }
}

// 1층부터 시작해서 n층까지 남우가 쫓겨나지 않고 가져갈 수 있는 보물의 최대 개수
int main() {
    // input
    cin >> n;
    for(int i=1; i<=n; ++i){
        // left, middle, right
        cin >> treasure[i][0] >> treasure[i][1] >> treasure[i][2];
    }

    // init
    Init();
    // 초기값
    for(int j=0; j<3; ++j){
        dp[1][j][j]=treasure[1][j];
    }

    // solution
    for(int i=2; i<=n; ++i){
        // j는 i층에서 들어갈 방, k는 i-1층에서 들어갔던 방
        for(int j=0; j<3; ++j){
            for (int k=0; k<3; ++k) {
                // i층과 i-1층의 방이 겹치면 안 됨
                if(j==k) continue;
                // j방을 선택하는 경우 이전 층에서는 (j+1)%3 || (j+2)%3 (j를 제외한 2개의 방을 의미) 선택 가능
                if(dp[i-1][(j+1)%3][k]!=-1)
                    dp[i][j][k]=max(dp[i][j][k], dp[i-1][(j+1)%3][k]+treasure[i][j]);
                if(dp[i-1][(j+2)%3][k]!=-1)
                    dp[i][j][k]=max(dp[i][j][k], dp[i-1][(j+2)%3][k]+treasure[i][j]);
            }
        }
    }
    
    // output
    int answer=0;
    for(int j=0; j<3; ++j){
        for(int k=0; k<3; ++k){
            // 첫 번째층에서 고른 방과 마지막 층에서 고른 방이 같으면 안 됨
            if(j==k) continue;
            answer = max(answer, dp[n][j][k]);
        }
    }
    cout << answer << '\n';
    return 0;
}