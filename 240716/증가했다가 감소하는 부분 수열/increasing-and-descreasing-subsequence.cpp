#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp_inc[1001]; // dp_inc[i]: i번째 원소로 끝나는 증가하는 부분 수열의 최대 길이
int dp_dec[1001]; // dp_dec[i]: i번째 원소로 시작하는 감소하는 부분 수열의 최대 길이

int main() {
    // input
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    
    // init
    for(int i = 0; i < n; ++i){
        dp_inc[i] = 1;
        dp_dec[i] = 1;
    }
    
    // 1. dp_inc 계산
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(arr[j] < arr[i]) {
                dp_inc[i] = max(dp_inc[i], dp_inc[j] + 1);
            }
        }
    }
    
    // 2. dp_dec 계산
    for(int i = n-1; i >= 0; --i){
        for(int j = n-1; j > i; --j){
            if(arr[i] > arr[j]) {
                dp_dec[i] = max(dp_dec[i], dp_dec[j] + 1);
            }
        }
    }
    
    // output
    int answer = 0;
    for(int i = 0; i < n; ++i){
        answer = max(answer, dp_inc[i] + dp_dec[i] - 1);
    }
    cout << answer << '\n';
    
    return 0;
}