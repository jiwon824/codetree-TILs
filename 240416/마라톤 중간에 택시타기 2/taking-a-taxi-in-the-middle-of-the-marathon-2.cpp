#include <iostream>
#include <algorithm>
#include <cmath>

#define MAXINT 2147483647
using namespace std;

int point[2][101];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n;i++){
        cin >> point[0][i] >> point[1][i];
    }

    // 첫번째 체크포인트[0]와 마지막 체크포인트[n-1]는 지나야 한다.
    // 체크 포인트 하나를 건너뛰어서 최단거리 구하기
    // i번째 체크포인트를 건너뛸 경우 거리들을 구해서 mindist 갱신
    int min_dist = MAXINT;
    for(int i=1;i<n-1;i++){
        int dist =0;
        for(int j=0;j<n-1;j++){
            if(j==i) continue;
            else if(j+1==i){
                int x_dist = abs(point[0][j+2]-point[0][j]);
                int y_dist = abs(point[1][j+2]-point[1][j]);
                dist = dist+x_dist+y_dist;
            }
            else{
                int x_dist = abs(point[0][j+1]-point[0][j]);
                int y_dist = abs(point[1][j+1]-point[1][j]);
                dist = dist+x_dist+y_dist;
            }

        }
        min_dist = min(min_dist, dist);
    }
    cout << min_dist;
    return 0;
}