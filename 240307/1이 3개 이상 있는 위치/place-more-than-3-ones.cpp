#include <iostream>

using namespace std;

//상(0, 1) 하(0, -1) 좌(-1, 0) 우(1, 0)
int dx[4] ={0, 0, -1, 1}, dy[4] ={1, -1, 0, 0};

int main() {
    int n;
    cin >> n;
    // 이차원배열 동적할당하기
    int** map = new int*[n];
    for(int i =0; i<n;i++){
        map[i] = new int[n];
    }

    // map 입력받기
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            cin >> map[i][j];
        }
    }

    int cnt=0, ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x=i, y=j;
            for(int k=0; k<4;k++){
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                if(map[nx][ny]==1) cnt++;
            }
            if(cnt>=3) ans++;
            cnt=0;
        }
    }

    cout << ans;
    return 0;
}