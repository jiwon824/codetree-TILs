#include <iostream>

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
    dp[0][0]=arr[0][0];
    for(int i=1; i<n; ++i){
        dp[0][i] = min(dp[0][i-1], arr[0][i]);
    }
    for(int i=1; i<n; ++i){
        dp[i][0] = min(dp[i-1][0], arr[i][0]);
    }

    for(int i=1; i<n; ++i){
        for(int j=1; j<n; ++j){
            dp[i][j]= min(arr[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
    }

    // output
    /*
    // dp 값 확인
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    */
    cout << dp[n-1][n-1] << '\n';
    return 0;
}