#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int answer=-1;
int arr[21][21];

int CheckRectangle(int x1, int y1, int x2, int y2){
    int cnt=0;
    for(int i=x1; i<=x2; i++){
        for(int j=y1; j<=y2; j++){
            if(arr[i][j]<=0) return -1;
            cnt++;
        }
    }
    return cnt;
}

void PointToStart(){
    // (i,j)점에서 width, height 사각형 만들기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            for(int width=0; width<m; width++){
                for(int height=0; height<n; height++){
                    if(j+width>m || i+height>n) continue;
                    answer = max(answer, CheckRectangle(i, j, i+height, j+width));
                }
            }
            
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    PointToStart();
    cout << answer<<'\n';
    return 0;
}