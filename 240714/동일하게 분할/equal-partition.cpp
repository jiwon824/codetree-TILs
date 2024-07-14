#include <iostream>
using namespace std;

int n, sum;
int arr[101];
int dp[100001]; // dp[i]

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
        sum += arr[i];
    }

    // init
    for(int i=1; i<=100001; ++i){
        dp[i]=-1;
    }

    // solution
    for(int i=0; i<n; ++i){
        for(int j=sum; j>=0; --j){
            if(j-arr[i]<0 || dp[j-arr[i]]==-1) continue;
            dp[j] = max(dp[j], dp[j-arr[i]]+arr[i]);
        }
    }
    
    //output
    string answer = sum-dp[sum/2]==sum/2 ? "Yes" : "No";
    cout << answer << '\n';
    return 0;
}