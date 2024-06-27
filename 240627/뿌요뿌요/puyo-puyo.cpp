#include <iostream>

using namespace std;

int n, size=1, numOfExplodingBlock, maxBlockSize;
int board[101][101];
bool visited[101][101]={false, };

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

bool CanGo(int nx, int ny, int num){
    //cout << nx << " "  << ny <<'\n';
    // 범위를 벗어남
    if(!InRange(nx, ny)) return false;
    // 이미 방문했던 경우 || 다른 숫자
    if(visited[nx][ny] || board[nx][ny]!=num) return false;
    return true;
}

void DFS(int x, int y){
    // 상(-1,0) 하(1,0) 좌(0,-1) 우(0,1)
    int dx[4]={-1, 1, 0, 0};
    int dy[4]={0, 0, -1, 1};

    for(int dir=0; dir<4; ++dir){
        int nx=x+dx[dir], ny=y+dy[dir];

        if(CanGo(nx, ny, board[x][y])){
            visited[nx][ny]=true;
            size++;
            DFS(nx, ny);
        }
    }

}
int main() {
    // input
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; ++j){
            if(visited[i][j]) continue;

            size=1;
            visited[i][j]=true;
            DFS(i, j);

            maxBlockSize = max(maxBlockSize, size);
            if(size>=4) numOfExplodingBlock++;
        }
    }

    cout << numOfExplodingBlock << " " << maxBlockSize <<'\n';
    return 0;
}