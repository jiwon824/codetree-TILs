#include <iostream>

using namespace std;

// 하(1, 0) 우(0, 1) 상(-1, 0) 좌(0, -1)
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
int** map;
int main() {
    int n, m;
    cin >> n >> m;
    //n*m 배열 생성
    map=new int*[n];
    for(int i=0;i<n;i++){
        map[i]=new int[m];
    }

    //채우기
    int x=0, y=0, dir=0, cnt=1;
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            map[x][y]=cnt;
            int nx = x+dx[dir];
            int ny = y+dy[dir];
            // map을 벗어나는 범위이거나 이미 방문했던 곳이면 방향 및 nx, ny 재설정
            if(nx<0 || ny<0 || nx>=n || ny>=m || map[nx][ny]>0){
                dir=(dir+1)%4;
                nx = x+dx[dir];
                ny = y+dy[dir];
            }
            x=nx;
            y=ny;
            cnt++;
        }
    }

    // 출력
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout << map[i][j] << " ";
        }
        cout <<"\n";
    }

    return 0;
}