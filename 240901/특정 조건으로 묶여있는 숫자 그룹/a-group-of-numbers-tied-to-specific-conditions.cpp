#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 50001;

int n, k;
int arr[MAX_N];

int Solution(){
    int max_cnt=0;
    // i에서 시작할 때 group1과 group2
    for(int i=0; i<n; ++i){
        // group1 [i, right]
        int right=i;
        while(right<n && arr[right]-arr[i]<=k){
            right++;
        }
        int group1 = right-i;

        // group2 [left, right] left<=right<n
        int group2=0;
        for(int left=right; left<n; ++left){
            while(right<n && arr[right]-arr[left]<=k){
                right++;
            }
            group2 = max(group2, right-left);
        }
        max_cnt = max(max_cnt, group1+group2);
    }
    return max_cnt;
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