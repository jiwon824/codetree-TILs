#include <iostream>
using namespace std;

int n;
int arr[1001];
int dp_inc[1001]; // dp[i]: i번째가 마지막 원소라고 했을 때 증가하는 부분 수열의 길이
int dp_dec[1001]; // dp[i]: i번째가 시작 원소라고 했을 때 감소하는 부분 수열의 길이

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    // init
    for(int i=0; i<n; ++i){
        dp_inc[i]=1;
        dp_dec[i]=1;
    }

    // solution
    // 1. dp_inc 계산
    // 1 2 3 4 5
    for(int i=0; i<n; ++i){
        for(int j=0; j<i; ++j){
            if(arr[j]<arr[i]) dp_inc[i]=max(dp_inc[i], dp_inc[j]+1);
        }
    }

    // 2. dp_dec 계산
    // 5 4 3 2 1
    for(int i=0; i<n; ++i){
        int lastNum=arr[i];
        for(int j=i+1; j<n; ++j){
            if(arr[i]>arr[j] && lastNum>arr[j]) {
                dp_dec[i]=max(dp_dec[i], dp_dec[i]+1);
                lastNum=arr[j];
            }
        }
    }

    // output
    int answer=0;
    for(int i=0; i<n; ++i){
        int maxNum = max(dp_inc[i]+dp_dec[i]-1, max(dp_inc[i], dp_dec[i]));
        answer = max(answer, maxNum);
    }
    cout << answer << '\n';

    return 0;
}