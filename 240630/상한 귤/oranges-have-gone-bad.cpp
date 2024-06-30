#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, k;

// 0: 해당 칸에 아무것도 놓여있지 않음
// 1: 해당 칸에 귤이 놓여있음
// 2: 해당 칸에 상한 귤이 처음부터 놓여 있음
int arr[101][101];
int answer[101][101];
bool visited[101][101]={false, };

vector<pair<int,int> > rottenPos;

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

bool CanGo(int x, int y){
    // 범위를 벗어난 접근
    if(!InRange(x, y)) return false;
    // 방문한 적 있음 || 아무것도 없는 칸
    if(visited[x][y] || arr[x][y]==0) return false;
    return true;
}

void BFS(){
    // 상(-1,0) 하(1,0) 좌(0,-1) 우(0,1)
    int dx[4]={-1, 1, 0, 0};
    int dy[4]={0, 0, -1, 1};

    queue<tuple<int,int,int> >q;
    // 상한귤 좌표를 queue에 담기
    for(size_t i=0; i<rottenPos.size(); ++i){
        int x=rottenPos[i].first, y=rottenPos[i].second;
        q.push({x, y, 0});
        answer[x][y]=0;
        visited[x][y]=true;
    }

    while(!q.empty()){
        int x, y, t;
        tie(x, y, t)=q.front();
        q.pop();
        for(int dir=0; dir<4; ++dir){
            int nx=x+dx[dir], ny=y+dy[dir];
            if(CanGo(nx, ny)){
                q.push({nx, ny, t+1});
                answer[nx][ny]=t+1;
                visited[nx][ny]=true;
            }
        }
    }

    // arr[x][y]==0인 경우+방문하지 않은 칸(=끝까지 상하지 않는 귤) 처리
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            // 처음부터 비어있던 칸은 -1
            if(arr[i][j]==0) answer[i][j]=-1;
            else if(!visited[i][j]) answer[i][j]=-2;
        }
    }

}

int main() {
    // input
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> arr[i][j];
            // 상한 귤
            if(arr[i][j]==2) rottenPos.push_back({i, j});
        }
    }
    // solution
    BFS();

    // output
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << answer[i][j] << " ";
        }
        cout <<'\n';
    }
    return 0;
}