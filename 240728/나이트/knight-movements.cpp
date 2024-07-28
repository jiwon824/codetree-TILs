#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[101][101];
int dist[101][101];
bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

bool CanGo(int x, int y){
    if(!InRange(x, y) || dist[x][y]>0) return false;
    return true;
}

void BFS(int x, int y){
    // 8방향 움직임
    int dx[8]={-2, -2, -1, 1, 2, 2, 1, -1};
    int dy[8]={-1, 1, 2, 2, 1, -1, -2, -2};

    queue<pair<int,int>> coord;
    coord.push({x, y});
    dist[x][y]=1;

    while(!coord.empty()){
        int currX=coord.front().first, currY=coord.front().second;
        coord.pop();

        for(int dir=0; dir<8; ++dir){
            int nx=currX+dx[dir], ny=currY+dy[dir];
            if(CanGo(nx, ny)){
                coord.push({nx, ny});
                dist[nx][ny]=dist[currX][currY]+1;
            }
        }
    }
    
}

int main() {
    // input
    cin >> n;
    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;
    
    // solution
    BFS(startX-1, startY-1);

    // output
    int answer=(dist[endX-1][endY-1]-1>0) ? dist[endX-1][endY-1]-1:-1;
    cout << answer <<'\n';
    return 0;
}