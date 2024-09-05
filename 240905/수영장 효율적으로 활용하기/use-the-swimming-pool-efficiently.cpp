#include <iostream>
using namespace std;

const int MAX_N =100001;
const int MAX_T =1440;

int n, m;
int ti[MAX_N];

bool IsPossible(int laneTime){
    int idx=0, cnt=1;
    while(idx<n){
        // ti[idx]가 최대시간(laneTime)보다 크면 laneTime 안에 해결 불가능
        if(ti[idx]>laneTime) return false;
        // 레인을 m개보다 많이 사용할 수 없음
        if(cnt>m) return false;

        int sum=0;
        while(sum+ti[idx]<=laneTime){
            sum+=ti[idx];
            idx++;
        }
        cnt++;
    }
    
    return true;
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> ti[i];
    }    

    // solution: 수영장 이용시간의 합을 이진 탐색으로 찾음
    // 수영장 최대 이용시간이 mid일 경우 가능 여부
    int left=0, right=m*MAX_T, answer=right;
    while(left<=right){
        int mid = (left+right)/2;
        if(IsPossible(mid)){
            answer=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    
    // output
    cout << answer << '\n';
    return 0;
}