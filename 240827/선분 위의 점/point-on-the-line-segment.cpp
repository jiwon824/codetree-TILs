#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N =100001;

int n, m;
int points[MAX_N];

int UpperBound(int target){
    int left=0, right=n-1;
    int min_idx=n;
    while(left<=right){
        int mid=(left+right)/2;
        if(points[mid]>target){
            right=mid-1;
            min_idx=min(min_idx, mid);
        }
        else left=mid+1;
    }
    return min_idx;
}
int LowerBound(int target){
    int left=0, right=n-1;
    int min_idx=n;
    while(left<=right){
        int mid=(left+right)/2;
        if(points[mid]>=target){
            right=mid-1;
            min_idx=min(min_idx, mid);
        }
        else left=mid+1;
    }
    return min_idx;
}

int NumberOfPoints(int start, int end){
    return UpperBound(end)-LowerBound(start);
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> points[i];
    }

    sort(points, points+n);

    // m개의 질의
    while(m--){
        int s, e;
        cin >> s >> e;
        cout << NumberOfPoints(s, e) << '\n';
    }
    return 0;
}