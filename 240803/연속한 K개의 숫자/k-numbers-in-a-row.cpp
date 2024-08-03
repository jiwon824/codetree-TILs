#include <iostream>

using namespace std;

int arr[100001];
int prefix_sum[100001];

int main() {
    // input
    int n, k, b;
    cin >> n >> k >> b;

    for(int i=0; i<b; ++i){
        int num;
        cin >> num;
        arr[num]=1;
    }

    // solution
    for(int i=1; i<=n; ++i){
        prefix_sum[i]=prefix_sum[i-1]+arr[i];
    }
    int answer=100001;
    for(int i=k; i<=n; ++i){
        answer= min(answer, prefix_sum[i]-prefix_sum[i-k]);
    }
    
    // output
    cout << answer << '\n';
    return 0;
}