#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 50001;
int n, k;
int points[MAX_N];

bool IsPossible(int range){
    int numOfInstalled=0, lastPos=-1;
    for(int i=0; i<n; ){
        if(numOfInstalled >= k) return false;

        // pos 위치에 폭탄 위치
        numOfInstalled++;
        lastPos=points[i]+range;

        // 그 다음 폭탄의 위치
        while(i<n && points[i]<=lastPos+range){
            i++;
        }
    }
    return true;
}

int main() {
    // input
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> points[i];
    }
    
    sort(points, points+n);

    // solution: 이진 탐색으로 범위 찾기
    int left=0, right =1e9, answer=right;
    while(left<=right){
        int mid = (left+right)/2;
        if(IsPossible(mid)){
            right=mid-1;
            answer=mid;
        }
        else left = mid+1;
    }
    
    // output
    cout << answer << '\n';

    return 0;
}