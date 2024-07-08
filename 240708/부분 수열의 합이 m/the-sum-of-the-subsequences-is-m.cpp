#include <iostream>

#define MAX 10001
using namespace std;


int n, m;
int arr[101];
int dp[MAX];

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    // init
    dp[0]=0;
    for(int i=1; i<=m; ++i){
        dp[i]=MAX;
    }

    // solution
    for(int i=0; i<n; ++i){
        for(int j=m; j>=0; --j){
            if(dp[j-arr[i]==MAX] || j-arr[i]<0) continue;
            dp[j]=min(dp[j], dp[j-arr[i]]+1);
        }
    }

    // output
    int answer=dp[m];
    if(answer==MAX) answer=-1;
    cout << answer << '\n';
    return 0;
}