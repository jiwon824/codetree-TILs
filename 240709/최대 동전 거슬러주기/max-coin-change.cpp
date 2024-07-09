#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int coin[101];
int dp[10001];

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> coin[i];
    }
    // init
    for(int i=0; i<=m; i++){
        dp[i]=INT_MIN;
    }

    // solution
    dp[0]=0;

    for(int i=1; i<=m; ++i){
        for(int j=0; j<n; ++j){
            if (i-coin[j]<0 || dp[i-coin[j]]==INT_MIN) continue;
            dp[i]= max(dp[i], dp[i-coin[j]]+1);
        }
    }

    // output
    int answer = dp[m];
    if(answer==INT_MIN) answer=-1;
    cout << answer << '\n';
    return 0;
}