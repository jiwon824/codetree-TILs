#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

int main() {
    // input
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    // solution
    for(int i=1; i<n; ++i){
        for(int j=0; j<i; ++j){
            if((j+arr[j])-i>=0){
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
    }

    // output
    int answer=0;
    for(int i=1; i<n; ++i){
        if(dp[i]==0) break;
        answer = max(answer, dp[i]);
    }
    cout << answer <<'\n';

    return 0;
}