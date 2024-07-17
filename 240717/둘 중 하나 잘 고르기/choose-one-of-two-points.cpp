#include <iostream>
using namespace std;

int n;
int red[201];
int blue[201];
int dp[201][101]; // dp[i][j]: i번째 인덱스까지 고려했을 때 red를 j개 선택했다면 그때의 최대합

void Init(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            dp[i][j]=-1;
        }
    }
    dp[0][0]= blue[0];
    dp[0][1]= red[0];
}

int main() {
    // input
    cin >> n;
    for(int i=0; i<2*n; ++i){
        cin >> red[i] >> blue[i];
    }

    // init
    Init();

    // solution
    for(int i=1; i<2*n; ++i){
        for(int j=0; j<=n; ++j){
            // max(i번째 red를 선택하는 경우, i번째 blue를 선택하는 경우)
            dp[i][j] = max(dp[i-1][j-1]+red[i], dp[i-1][j]+blue[i]);
        }
    }
    
    // output
    cout << dp[2*n-1][n] <<'\n';

    return 0;
}