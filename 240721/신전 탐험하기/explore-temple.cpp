#include <iostream>

using namespace std;

int n;
int treasure[1001][3];

// dp[i][j]: i번째 층에 j방에 들어갔을 때 최대 보물 개수(누적)
int dp[1001][3];

void Init(){
    for(int i=0; i<=n; ++i){
        for(int j=0; j<3; ++j){
            dp[i][j]=-1;
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

    // solution
    dp[0][0]=0, dp[0][1]=0, dp[0][2]=0;
    for(int i=1; i<=n; ++i){
        for(int j=0; j<3; ++j){
            for(int k=0; k<3; ++k){
                if(j==k) continue; // 이전 층이랑 같은 방에 들어가면 쫓겨남
                if(dp[i-1][k]==-1) continue; // 불가능한 경우
                dp[i][j]=max(dp[i][j], dp[i-1][k]+treasure[i][j]);
            }
        }
    }

    // output
    int answer=max(dp[n][0], max(dp[n][1], dp[n][2]));
    cout << answer << '\n';
    return 0;
}