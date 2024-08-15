#include <iostream>
#define MAX_N 100000

using namespace std;

pair<int,int> checkPoint[MAX_N];
int lDist[MAX_N];
int rDist[MAX_N];

// 개발자 A가 체크포인트 한 개를 건너 뛰어서 마라톤을 완주하려고 할 때, 최소 거리를 구하는 프로그램
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> checkPoint[i].first >> checkPoint[i].second;
    }
    
    // L 배열 채우기
    lDist[0]=0;
    for(int i=1; i<n; ++i){
        int x1=checkPoint[i-1].first, y1=checkPoint[i-1].second;
        int x2=checkPoint[i].first, y2=checkPoint[i].second;
        int dist = abs(x2-x1)+abs(y2-y1);
        lDist[i] = lDist[i-1] + dist;
    }

    // R 배열 채우기
    rDist[n-1]=0;
    for(int i=n-2; i>=0; --i){
        int x1=checkPoint[i].first, y1=checkPoint[i].second;
        int x2=checkPoint[i+1].first, y2=checkPoint[i+1].second;
        int dist = abs(x2-x1)+abs(y2-y1);
        rDist[i] = rDist[i+1] + dist;
    }
    /*
    for(int i=0; i<n; ++i){
        cout << lDist[i] << " ";
    }
    cout << '\n';
    for(int i=0; i<n; ++i){
        cout << rDist[i] << " ";
    }
    */

    // 최소거리 구하기
    int minDist=2e9;
    for(int i=1; i<n-1; ++i){
        int x1=checkPoint[i-1].first, y1=checkPoint[i-1].second;
        int x2=checkPoint[i+1].first, y2=checkPoint[i+1].second;
        int dist = lDist[i-1]+rDist[i+1]+abs(x2-x1)+abs(y2-y1);
        minDist=min(minDist, dist);
    }
    cout << minDist;
    return 0;
}