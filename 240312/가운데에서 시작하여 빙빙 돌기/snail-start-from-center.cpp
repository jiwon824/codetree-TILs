#include <iostream>

using namespace std;

//좌(0, -1) 상(-1, 0) 우(0, 1) 하(1, 0)
int dx[4]={0, -1, 0, 1}, dy[4]={-1, 0, 1, 0};
int** map;
int main() {
    int n;
    cin >> n;
    
    map =new int*[n];
    for(int i=0; i<n;i++){
        map[i]=new int[n];
    }

    //map 채우기
    // 가운데에서 반시계로 도는 것과 (n-1, n-1)에서 n*n부터 1씩 줄여가면서 시계방향으로 채우는 게 같을 것 같다.
    int x=n-1, y=n-1, dir=0, cnt=n*n;
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            map[x][y]=cnt;

            int nx = x+dx[dir];
            int ny = y+dy[dir];
            if (nx<0 || ny<0 || nx>=n || ny>=n || map[nx][ny]>0){
                dir=(dir+1)%4;
                nx = x+dx[dir];
                ny = y+dy[dir];
            }
            x=nx;
            y=ny;
            cnt--;
        }
    }

    //
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << map[i][j] << " ";
        }
        cout <<"\n";
    }
    return 0;
}