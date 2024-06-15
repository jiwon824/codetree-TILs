#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n, m, r, c;
int arr[101][101];

void PlaceBombs(){
    //좌(0,-1) 상(-1,0) 우(0,1) 하(1,0)
    int dx[4]={0, -1, 0, 1};
    int dy[4]={-1, 0, 1, 0};

    queue <pair<int, int> > bombs;
    bombs.push({r, c}); // 0초에는 (r,c)에만 폭탄이 있음
    arr[r][c]=1;
    
    for(int time=1; time<=m; ++time){
        int size=bombs.size();
        for(int qSize=0; qSize<size; ++qSize){
            int x = bombs.front().first;
            int y = bombs.front().second;
            bombs.pop();

            for(int dir=0; dir<4; ++dir){
                int nx= x+(dx[dir]*pow(2, time-1));
                int ny= y+(dy[dir]*pow(2, time-1));
                // 범위를 벗어나거나 이미 방문했던 곳이라면 continue
                if(nx<0 || nx>=n || ny<0 || ny>=n || arr[nx][ny]==1) continue;
                bombs.push({nx, ny});
                arr[nx][ny]=1;
            }
            bombs.push({x, y});
        }
    }
    
}

int main() {
    cin >> n >> m >> r >>c ;
    r-=1;
    c-=1;
    PlaceBombs();

    int answer=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(arr[i][j]==1) answer++;
        }
    }
    cout << answer;
    return 0;
}