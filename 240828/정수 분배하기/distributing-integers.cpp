#include <iostream>
using namespace std;

const int MAX_N = 10000;
int n, m;

int arr[MAX_N];
bool IsPossible(int k){
    int cnt =0;
    for(int i=0; i<n; ++i){
        cnt+=arr[i]/k;
    }
    return cnt>=m;
}
int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    int left=1, right=100000;
    int ans=0;
    while(left<=right){
        int mid = (left+right)/2;
        if(IsPossible(mid)){
            left=mid+1;
            ans = max(ans, mid);
        }
        else right = mid-1;
    }
    cout << ans << '\n';
    return 0;
}