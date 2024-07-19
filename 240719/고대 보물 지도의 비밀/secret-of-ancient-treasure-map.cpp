#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, k;

int main() {
    // input
    cin >> n >> k;
    vector<int> num(n+1, 0);
    // 1부터 시작함
    for(int i=1; i<=n; ++i){
        cin >> num[i];
    }

    // solution
    // dp[i][j]: i번째 인덱스까지 고려, 음수가 j개 포함된 경우
    // dp[i][j]: i번째 인덱스까지 고려했을 때 음수가 j개 포함된 최대 연속 부분 합
    vector<vector<int> > dp(n+1, vector<int>(k+1, -10001));

    // 초기 상태
    for(int j=0; j<=k; ++j) dp[0][j]=0;

    // 상태 전이
    int answer=INT_MIN;
    for(int i=1; i<=n; ++i){
        for(int j=0; j<=k; ++j){
            //num[i]>0: 이전 상태에 현재 숫자를 더하거나, 새로운 연속 구간을 시작
            if(num[i]>=0) dp[i][j] = max(dp[i-1][j]+num[i], num[i]);
            //num[i]<0: 이전 상태에 현재 숫자를 더하거나 (j를 1 증가), 새로운 연속 구간을 시작
            else {
                if(j>0) dp[i][j] = max(dp[i-1][j-1]+num[i], num[i]);
            }
            answer=max(answer, dp[i][j]);
        }
    }
    
    // output
    cout << answer <<'\n';

    return 0;
}