#include <iostream>
using namespace std;

const int MAX_N = 100001;
int n, m;
int sorted_num[MAX_N];

int LowerBound(int target) {
    int left=0, right=n-1;
    int min_idx=n;
    while(left<=right){
        int mid = (left+right)/2;
        if(sorted_num[mid]>=target){
            right=mid-1;
            min_idx=min(min_idx, mid);
        }
        else left=mid+1;
    }
    return min_idx;
}

int UpperBound(int target) {
    int left=0, right=n-1;
    int min_idx=n;
    while(left<=right){
        int mid = (left+right)/2;
        if(sorted_num[mid]>target){
            right=mid-1;
            min_idx=min(min_idx, mid);
        }
        else left=mid+1;
    }
    return min_idx;
}

int NumberOfTarget(int target){
    return UpperBound(target)-LowerBound(target);
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        // n개의 숫자는 오름차순으로 정렬되어 주어지며, 동일한 숫자가 여러 번 주어질 수 있다.
        cin >> sorted_num[i];
    }

    for(int i=0; i<m; ++i){
        int target;
        cin >> target;
        cout << NumberOfTarget(target) << '\n';
    }

    return 0;
}