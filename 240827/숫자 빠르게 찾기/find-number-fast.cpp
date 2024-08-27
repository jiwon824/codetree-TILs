#include <iostream>
using namespace std;

const int MAX_N = 100000;

int n, m;
int sorted_num[MAX_N];

int FindIdx(int target){
    int l=0, r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(sorted_num[mid]==target) return mid+1;
        if(sorted_num[mid]<target) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        // n개의 숫자는 오름차순으로 정렬되어 주어지며, 주어지는 모든 숫자는 서로 다름
        cin >> sorted_num[i];
    }

    for(int i=0; i<m; ++i){
        int target;
        cin >> target;

        cout << FindIdx(target) << '\n';
    }

    return 0;
}