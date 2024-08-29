#include <iostream>
using namespace std;

long long n, k; // k는 최대 (10)^9
int main() {
    cin >> n >> k;

    long long left =1, right=n*n, answer=0;
    while(left<=right){
        long long mid=(left+right)/2;

        int cnt=0;
        for(int i=1; i<=n; ++i){
            cnt+=min(n, mid/i);
        }

        if(cnt>=k) {
            right=mid-1;
            answer=mid;
        }
        else left=mid+1;
    }
    cout << answer << '\n';
    return 0;
}