#include <iostream>
using namespace std;

int n;
int arr[101];
int dp[101];

int main() {
    // input
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> arr[i];
    }

    // init

    // solution
    // dp[i]= i길이일 때 최대 수익
    dp[0]=0;
    for(int i=1; i<=n; ++i){
        for(int j=1;j<=n;++j){
            if(j-i<0) continue;
            dp[j]=max(dp[j], dp[j-i]+arr[i]);
        }
    }

    //output
    cout << dp[n] << '\n';
    return 0;
}