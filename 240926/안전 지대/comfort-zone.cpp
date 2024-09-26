#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 51;
const int MAX_M = 51;

int n, m, maxHeight;
int waterLevel, safeZone; // ans

int house[MAX_N][MAX_M]; // arr
bool visited[MAX_N][MAX_M];

// Func
bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

bool CanGo(int x, int y, int l){
    // 범위가 아니면 못 감
    if(!InRange(x, y)) return false;

    // 방문한 지역 || 침수 지역은 못 감
    if(visited[x][y] || house[x][y]<=l) return false;

    return true;
}

// Find NumOfSafeZone
void DFS(int x, int y, int l){
    // 상하좌우
    int dx[4]= {-1, 1, 0, 0};
    int dy[4]= {0, 0, -1, 1};

    for(int dir=0; dir<4; ++dir){
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        if(CanGo(nx, ny, l)){
            visited[nx][ny]=true;
            DFS(nx, ny, l);
        }
    }
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> house[i][j];
            maxHeight = max(maxHeight, house[i][j]);
        }
    }

    // DFS
    for(int k=1; k<=maxHeight; ++k){
        int cnt=0;
        memset(visited, false, sizeof(visited));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(visited[i][j] || house[i][j]<=k) continue;
                DFS(i, j, k);
                cnt++;
            }
        }

        // 안전영역이 최대가 되도록 갱신
        if(cnt>safeZone){
            waterLevel=k;
            safeZone=cnt;
        }
    }
    
    // output k, safeZone
    cout << waterLevel << " "<< safeZone <<'\n';
    return 0;
}