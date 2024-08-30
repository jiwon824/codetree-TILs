#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_M = 100000;

int n, m;
int t[MAX_M];

bool IsPossible(long long time){
    int cnt =0;// 물건의 개수
    for(int i=0; i<m; ++i){
        cnt+=time/t[i];
        if(cnt>=n) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        cin >> t[i];
    }

    sort(t,t+m);
    
    long long left=1, right=t[m-1]*(long long)n, answer=t[m-1]*(long long)n;
    while(left<=right){
        long long mid = (left+right)/2;
        if(IsPossible(mid)){
            right=mid-1;
            answer = mid;
        }
        else left=mid+1;
    }

    cout << answer << '\n';
    return 0;
}