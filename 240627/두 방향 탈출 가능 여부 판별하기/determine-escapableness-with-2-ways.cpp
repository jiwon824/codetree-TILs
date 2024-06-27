#include <iostream>

using namespace std;

int n, m, answer;
int arr[101][101];// 각 행에 뱀이 없는 경우 1, 뱀이 있는 경우 0
bool visited[101][101];

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

bool CanGo(int x, int y){
    // 범위를 벗어남
    if(!InRange(x, y)) return false;
    // 뱀이 있음 || 이미 방문한 칸임
    if(arr[x][y]==0 || visited[x][y]) return false;
    return true;
}

void DFS(int x, int y){
    // 우(0,1) 하(1,0)
    int dx[2]={0, 1};
    int dy[2]={1, 0};

    for(int dir=0; dir<2; ++dir){
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        
        if(nx==n-1 && ny==m-1) answer=1;
        
        if(CanGo(nx, ny)){
            visited[nx][ny]=true;
            DFS(nx, ny);
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
    DFS(0, 0);

    // output
    cout << answer << '\n';
    
    return 0;
}