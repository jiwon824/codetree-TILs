#include <iostream>

using namespace std;

int num[3]={1, 2, 5};
int dp[1001];

int main() {
    int n;
    cin >> n;
    dp[0]=1;
    for(int i=1; i<=n; ++i){
        for(int j=0; j<3; j++){
            if(i-num[j]<0) continue;
            dp[i]=(dp[i]+dp[i-num[j]])%10007;
        }
    }
    cout << dp[n] <<'\n';
    return 0;
}