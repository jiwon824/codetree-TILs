#include <iostream>

using namespace std;
int n, m;
int arr[51][51];
int dp[51][51];

void FillDP(int x, int y){
     for(int i=0; i<x; ++i){
        for(int j=0; j<y; ++j){
            if(arr[x][y]>arr[0][0] && arr[i][j]<arr[x][y]){
                dp[x][y]=max(dp[x][y], dp[i][j]+1);
            }
        }
    }
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> arr[i][j];
        }
    }
    
    // solution
    dp[0][0]=1;
    for(int i=1; i<n; ++i){
        for(int j=1; j<m; ++j){
            FillDP(i, j);
        }
    }

    // output
    int answer =0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            answer=max(answer, dp[i][j]);
        }
    }
    cout << answer << '\n';
    return 0;
}