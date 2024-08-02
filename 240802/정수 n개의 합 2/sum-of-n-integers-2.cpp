#include <iostream>
using namespace std;

int n, k;
int arr[100001];
int prefix_sum[100001];

int main() {
    // input
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    // solution
    // prefix_sum 채우기
    prefix_sum[0]=arr[0];
    for(int i=1; i<n; ++i){
        prefix_sum[i]=prefix_sum[i-1]+arr[i];
    }

    // 0 1 2 3 4 5 6 7 8
    // 2-0, 3-1, 4-2, 5-3, ...
    int answer=prefix_sum[k-1];
    for(int i=k; i<n; ++i){
        answer= max(answer, prefix_sum[i]-prefix_sum[i-k]);
    }
    cout << answer << '\n';
    return 0;
}