#include <iostream>
using namespace std;

int n, m;
int clothesInfo[201][3];

// 총 만족도는 M개의 날 중 각각의 인접한 날짜에 입은 옷의 화려함의 차이의 합
// dp[i][j]: i번째 날에 j번째 옷을 입는 경우 화려함의 차이의 합
int dp[201][201];

void Init(){
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            dp[i][j]=-1;
        }
    }
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        // 순서대로 start, end, value
        cin >> clothesInfo[i][0] >> clothesInfo[i][1] >> clothesInfo[i][2];
    }

    // init
    Init();

    // solution
    // 초기 설정(첫날은 인접한 옷이 없으므로 0으로 설정해줌)
    for(int j=0; j<n; ++j){
        dp[1][j]=0;
    }

    // i: 날짜, j: 오늘 입은 옷, k: 전날 입은 옷
    for(int i=2; i<=m; ++i){
        for(int j=0; j<n; ++j){
            // 옷을 입을 수 있는 날이 아니라면 건너뜀
            if(i<clothesInfo[j][0] || clothesInfo[j][1]<i) continue;
            for(int k=0; k<n; ++k){
                // 전날 입을 수 있는 옷이 아니라면 건너뜀
                if(i-1<clothesInfo[k][0] || clothesInfo[k][1]<i-1) continue;

                // 불가능한 상태(-1)가 아니라면 dp 갱신
                if(dp[i-1][k]!=-1){
                    int score = abs(clothesInfo[j][2]-clothesInfo[k][2]);
                    dp[i][j]=max(dp[i][j], dp[i-1][k]+score);
                }
            }
        }
    }

    // output
    int answer =0;
    for(int j=0; j<=n; ++j){
        answer = max(answer, dp[m][j]);
    }
    cout << answer <<'\n';
    return 0;
}