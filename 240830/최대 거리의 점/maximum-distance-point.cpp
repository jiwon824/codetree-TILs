#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 200000;

int n, m;
int points[MAX_N];

// min_dist 이상의 거리로 m개의 물건을 배치할 수 있으면 true, 아니면 false
bool IsPossible(int min_dist) {
    int cnt=1;
    int last_pos=points[0];  // 마지막으로 물건을 놓은 위치

    for (int i=1; i<n; i++) {
        if (points[i]-last_pos >= min_dist) {
            // 현재 위치에 물건을 놓을 수 있음
            cnt++;
            last_pos=points[i];
            if (cnt>=m) return true;
        }
    }
    // m개의 물건을 배치하지 못했으면 false 반환
    return false;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> points[i];
    }   

    // 이분 탐색을 위해 정렬
    sort(points, points+n);

    int left=points[0], right=points[n-1], answer=0;
    while(left<=right){
        int mid = (left+right)/2;
        if(IsPossible(mid)){
            left=mid+1;
            answer=max(answer, mid);
        }
        else{
            right=mid-1;
        }
    }
    cout << answer << '\n';
    return 0;
}