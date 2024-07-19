#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, k;

int main() {
    // input
    cin >> n >> k;
    vector<int> num(n);
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }

    // solution
    // dp[i][j]: i번째 인덱스까지 고려, 음수가 j개 포함
    // dp[i][j]: i번째 인덱스까지 고려했을 때 음수가 j개 포함된 최대 연속 부분 합
    vector<vector<int> > dp(n+1, vector<int>(k+1, INT_MIN));

    // 초기 상태
    if (num[0] < 0) dp[0][1] = num[0];
    else dp[0][0] = num[0];

    // 상태 전이
    for(int i=1; i<n; ++i){
        for(int j=0; j<=k; ++j){
            // num[i]으로 시작하는 경우
            dp[i][j] = max(dp[i][j], num[i]); 
            // num[i]가 음수면서 연속부분수열에 포함되는 경우
            if(num[i]<0 && j>0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+num[i]);
            // num[i]가 양수인 경우
            if(num[i]>=0) dp[i][j] = max(dp[i][j], dp[i-1][j]+num[i]);
            
        }
    }
    
    // output
    int answer=INT_MIN;
    for(int i=0; i<n; ++i){
        for(int j=0; j<=k; ++j){
            answer=max(answer, dp[i][j]);
        }
    }
    cout << answer <<'\n';
    return 0;
}