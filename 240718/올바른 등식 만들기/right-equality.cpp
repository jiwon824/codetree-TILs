#include <iostream>
#include <vector>
#define OFFSET 20
using namespace std;

int n, m;

// 합이 m이 되는 서로다른 가짓수
// 더하거나 빼는 도중 -20~20 범위를 벗어나면 안 됨
int main() {
    // input
    cin >> n >> m;
    vector<int> num(n);
    // dp[i][j]: i번째 인덱스를 고려했을 때 합이 j가 되는 경우의 수
    vector<vector<long> > dp(n+1, vector<long>(41, 0));
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }
    
    // solution
    dp[0][OFFSET+num[0]] = 1;
    dp[0][OFFSET-num[0]] += 1; // 0일 경우 -0과 +0이 다른 경우의 수이기 때문에+=1
    for (int idx = 1; idx < n; ++idx) {
        for (int sum = -20; sum <= 20; ++sum) {
            int offsetNum=sum+OFFSET;
            if(0<=offsetNum-num[idx] && offsetNum-num[idx]<=40){
                dp[idx][offsetNum]+=dp[idx-1][offsetNum-num[idx]];
            }
            if(0<=offsetNum+num[idx] && offsetNum+num[idx]<=40){
                dp[idx][offsetNum]+=dp[idx-1][offsetNum+num[idx]];
            }
        }
    }

    // output
    cout << dp[n-1][m+OFFSET] <<'\n';
    return 0;
}