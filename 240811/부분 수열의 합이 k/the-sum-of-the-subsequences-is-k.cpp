#include <iostream>
#define MAX_N 1001
using namespace std;

int num[MAX_N];
long long prefix_sum[MAX_N];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }

    // prefix_sum 구하기
    prefix_sum[0]=num[0];
    for(int i=1; i<n; ++i){
        prefix_sum[i] = prefix_sum[i-1]+num[i];
    }

    int answer=0;
    for(int i=0; i<n; ++i){
        if(prefix_sum[i]==k){
            answer++;
            continue;
        }
        else if(prefix_sum[i]<k) continue;
        for(int j=0; j<i; ++j){
            if(prefix_sum[i]-prefix_sum[j]==k) answer++;
        }
    }

    cout << answer <<'\n';
    return 0;
}