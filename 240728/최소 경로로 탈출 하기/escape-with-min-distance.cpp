#include <iostream>
#include <queue>

using namespace std;
int n, m;
int arr[101][101];
int dist[101][101];

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

bool CanGo(int x, int y){
    if(!InRange(x, y)) return false;
    // 뱀이 있는 경우 || 방문했던 곳일 경우
    if(arr[x][y]==0||dist[x][y]>0) return false;
    return true;
}

void BFS(){
    // 상(-1,0)하(1,0)좌(0,-1)우(0,1)
    int dx[4] ={-1, 1, 0, 0};
    int dy[4] ={0, 0, -1, 1};

    int x=0, y=0, dir=0;
    queue<pair<int,int> > coord;
    coord.push({x, y});

    while(!coord.empty()){
        int x=coord.front().first, y=coord.front().second;
        coord.pop();
        for(int dir=0; dir<4; ++dir){
            int nx=x+dx[dir], ny=y+dy[dir];
            if(CanGo(nx, ny)){
                dist[nx][ny]=dist[x][y]+1;
                coord.push({nx, ny});
            }
        }
    }
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> arr[i][j];
        }
    }

    // solution
    BFS();

    // output
    int answer=(dist[n-1][m-1]>0) ? dist[n-1][m-1]:-1;
    cout << answer << '\n';
    return 0;
}