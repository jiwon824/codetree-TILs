#include <iostream>

using namespace std;

int n, m;
int arr[101][2];
int dp[10001];

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> arr[i][0] >> arr[i][1];
    }
    
    // init
    for(int i=0; i<=m; ++i){
        dp[i] = -1;
    }

    // solution
    // 하나씩만 골라야 하기 때문에 거꾸로 for문을 돌아야 함
    // dp[무게]= 해당 무게에서 얻을 수 있는 최대 가치
    dp[0]=0;
    for(int i=0; i<n; ++i){
        for(int j=m; j>=0; --j){
            if(j-arr[i][0]<0 || dp[j-arr[i][0]]==-1) continue;
            dp[j]= max(dp[j], dp[j-arr[i][0]]+arr[i][1]);
        }
    }

    //output
    int answer=0;
    for(int i=0; i<=m; ++i){
        answer=max(answer, dp[i]);
    }
    cout << answer <<'\n';
    return 0;
}