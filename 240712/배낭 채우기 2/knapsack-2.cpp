#include <iostream>
using namespace std;

int n, m;
int jewellery[101][2];// {{무게, 가치}, }
int dp[10001]; // dp[i]: 무게가 i일 때 최대 가치

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> jewellery[i][0] >> jewellery[i][1];
    }
    
    // solution
    //동일한 보석을 여러 개 고르는 것 가능
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int j=1; j<=m; j++){
            if(j-jewellery[i][0]<0) continue;
            dp[j]=max(dp[j], dp[j-jewellery[i][0]]+jewellery[i][1]);
        }
    }
    
    // output
    int answer=0;
    for(int i=0; i<=m; ++i){
        answer = max(answer, dp[i]);
    }
    cout << answer << '\n';

    return 0;
}