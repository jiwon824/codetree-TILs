#include <iostream>
#include <climits>

using namespace std;

int n;
int arr[100001];
int dp[100001]; //dp[i] i가 연속 부분수열의 마지막 원소일 때 최대합

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    // init
    dp[0]=arr[0];
    for(int i=1; i<n; ++i){
        dp[i]= INT_MIN;
    }

    // solution
    for(int i=1; i<n; ++i){
        dp[i]=max(dp[i-1]+arr[i], arr[i]);
    }

    // output
    int answer=INT_MIN;
    for(int i=0; i<n; ++i){
        answer = max(answer, dp[i]);
    }
    cout << answer << '\n';
    
    return 0;
}