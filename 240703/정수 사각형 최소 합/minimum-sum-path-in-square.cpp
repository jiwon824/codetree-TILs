#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[101][101];
int dp[101][101];

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> arr[i][j];
        }
    }

    // solution
    dp[0][n-1]=arr[0][n-1];
    // 가장 윗줄은 왼쪽으로만 갈 수 있음
    for(int i=n-2; i>=0; --i){
        dp[0][i]=dp[0][i+1]+arr[0][i];
    }
    // 오른쪽 줄은 아래로만 갈 수 있음
    for(int i=1; i<n; ++i){
        dp[i][n-1]=dp[i-1][n-1]+arr[i][n-1];
    }
    for(int i=1; i<n; ++i){
        for(int j=n-2; j>=0; --j){
            dp[i][j]=min(dp[i-1][j]+arr[i][j], dp[i][j+1]+arr[i][j]);
        }
    }

    // output
    cout << dp[n-1][0] << '\n';
    
    return 0;
}