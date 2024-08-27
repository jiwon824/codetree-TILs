#include <iostream>
using namespace std;

const int MAX_N = 100001;
int n, m;
int sorted_num[MAX_N];

int UpperBound(int target){
    int left=0, right=n-1;
    int min_idx=n;
    while(left<=right){
        int mid=(left+right)/2;
        if(sorted_num[mid]>target){
            right=mid-1;
            min_idx=min(min_idx, mid);
        }
        else left=mid+1;
    }
    return min_idx+1;
}
int LowerBound(int target){
    int left=0, right=n-1;
    int min_idx=n;
    while(left<=right){
        int mid=(left+right)/2;
        if(sorted_num[mid]>=target){
            right=mid-1;
            min_idx=min(min_idx, mid);
        }
        else left=mid+1;
    }
    return min_idx+1;
}

int FirstAppear(int target){
    if(UpperBound(target)-LowerBound(target)==0) return -1;
    else return LowerBound(target);
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        // 오름차순으로 정렬되어있는 n개의 숫자
        cin >> sorted_num[i];
    }

    // m개의 질의
    while(m--){
        int target;
        cin >> target;
        cout << FirstAppear(target) << '\n';
    }
    return 0;
}