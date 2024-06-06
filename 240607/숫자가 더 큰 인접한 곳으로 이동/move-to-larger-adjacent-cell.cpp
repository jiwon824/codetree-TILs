#include <iostream>

using namespace std;

int n;
int arr[101][101];

void Move(int r, int c){
    //상(-1,0)하(1,0)좌(0,-1)우(0,1) 방향 순서대로 우선순위
    int dx[4]={-1, 1, 0, 0};
    int dy[4]={0, 0, -1, 1};

    int x=r, y=c;
    while(true){
        cout << arr[x][y] << " ";

        int maxNum=arr[x][y];
        bool isUpdated=false;

        for(int dir=0; dir<4; dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];

            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(arr[nx][ny]>maxNum){
                isUpdated=true;
                maxNum=arr[nx][ny];
                x=nx;
                y=ny;
                break;
            }
        }
        if(!isUpdated) break;
    }
    
}
int main() {
    int r, c;
    cin >> n >> r >> c;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    Move(r-1, c-1);

    return 0;
}