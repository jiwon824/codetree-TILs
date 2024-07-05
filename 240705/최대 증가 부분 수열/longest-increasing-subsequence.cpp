#include <iostream>

using namespace std;

int n;
int arr[1001];
int dp[1001];

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    // solution
    dp[0]=1;
    for(int i=1; i<n; ++i){
        for(int j=0; j<i; ++j){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
    }
    

    // output
    int answer=1;
    for(int i=0; i<n; ++i){
        answer = max(answer, dp[i]);
    }

    cout << answer << '\n';
    return 0;
}