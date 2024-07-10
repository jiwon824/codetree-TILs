#include <iostream>
using namespace std;

int n, m;
int arr[101];
int dp[10001];

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    
    //init
    for(int i=0; i<=m; ++i){
        dp[i] = -1;
    }

    // solution
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int j=m; j>=0; --j){
            if(j-arr[i]<0 || dp[j-arr[i]]==-1) continue; 
            dp[j]=max(dp[j], dp[j-arr[i]]+1);
        }
    }
    
    // output
    string answer = (dp[m]>0) ? "Yes" : "No";
    cout << answer <<'\n';
    return 0;
}