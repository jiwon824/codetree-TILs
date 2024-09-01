#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 50001;

int n, k;
int arr[MAX_N];

int Solution(){
    // 그룹에 속하는 숫자의 개수
    int group1=0, group2=0;
    // 1. group1이 최대 일 경우 구하기
    int left=0, right=0;
    // 최대인 구간의 idx 정렬되어 있으므로 first에 최소값 second에 최대값이 들어감
    pair<int, int> max_range = {0, 0};
    
    for (left = 0; left < n; ++left) {
        while (right < n && arr[right] - arr[left] <= k) {
            right++;
        }
        if (right - left > group1) {
            group1 = right - left;
            max_range = {left, right - 1};
        }
    }

    // 2. group2가 최대 일 경우 구하기
    // 2-1. max_range.first 이전에서 찾기
    right = 0;
    for (left = 0; left < max_range.first; ++left) {
        while (right < max_range.first && arr[right] - arr[left] <= k) {
            right++;
        }
        group2 = max(group2, right - left);
    }
    
    // 2-2. max_range.second 이후에서 찾기
    right = max_range.second + 1;
    for (left = max_range.second + 1; left < n; ++left) {
        while (right<n && arr[right]-arr[left]<=k) {
            right++;
        }
        group2 = max(group2, right - left);
    }

    return group1+group2;
}

int main() {
    // input
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }   

    sort(arr, arr+n);

    cout << Solution() << '\n';
    return 0;
}