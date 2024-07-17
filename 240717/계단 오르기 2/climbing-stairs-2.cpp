#include <iostream>
using namespace std;

int n;
int arr[1001];
int dp[1001][4]; //dp[i][j]: i번째 계단까지 1계단 오른 횟수가 j일 때 얻은 동전의 수

void Init(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<=3; ++j){
            dp[i][j]=-1;
        }
    }
    dp[0][0]=0; // 계단을 오르지 않은 경우
}
// 계단을 오를 때 한 번에 1계단 혹은 2계단 위로만 올라갈 수 있다.
// 1계단 오르기는 최대 3번만 가능
// 2계단 위로 올라갈 경우 n층까지 1계단 남은 상황에서는 n층으로 올라갈 수 없음
int main() {
    //input
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> arr[i];
    }

    // init
    Init();

    // solution
    // i번째 계단을 마지막으로 밟았을 때 아래 조건이 같으면 동일한 상황
    // 1. 1계단 오를 수 있는 횟수
    // 2. 얻은 동전의 갯수 (얻은 동전의 갯수가 많을 수록 좋음)

    for(int i=0; i<=3; ++i){
        for(int j=1; j<=n; ++j){
            // 계단을 1칸 올랐을 때 1계단 오른 횟수가 i인 상태
            // dp[i-1][j-1] i-1번째 계단에서 1칸 오른 거니까 j-1
            if(i-1>=0 && dp[j-1][i-1]!=-1)
                dp[j][i]= max(dp[j][i], dp[j-1][i-1]+arr[j]);

            // 계단을 2칸 올랐을 때 1계단 오른 횟수가 j인 상태
            // i-2번째 계단에서 i계단으로 횟수를 소모하지 않고 올라옴
            if(j-2>=0 && dp[j-2][i]!=-1)
                dp[j][i]= max(dp[j][i], dp[j-2][i]+arr[j]);
        }
    }

    // output
    int answer=0;
    for(int i=1; i<=3; ++i){
        answer = max(answer, dp[n][i]);
    }
    cout << answer << '\n';
    return 0;
}