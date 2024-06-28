#include <iostream>
#include <queue>

using namespace std;

int n, k;
int arr[101][101]; //0은 이동할 수 있는 곳, 1은 이동할 수 없는 곳

queue<pair<int,int> > q;
bool visited[101][101]={false, };

int GetVisitedNum(){
    int answer=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(visited[i][j]) answer++;
        }
    }
    return answer;
}

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

bool CanGo(int x, int y){
    if(!InRange(x, y)) return false;
    if(arr[x][y]==1 || visited[x][y]) return false;
    return true;
}

void BFS(){
    // 상(-1,0) 하(1,0) 좌(0,-1) 우(0,1) 
    int dx[4]={-1, 1, 0, 0};
    int dy[4]={0, 0, -1, 1};
    
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop();
        
        for(int dir=0; dir<4; dir++){
            int nx=x+dx[dir], ny=y+dy[dir];
            if(CanGo(nx, ny)){
                visited[nx][ny]=true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    // input
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<k; ++i){
        int r, c;
        cin >> r >> c;
        visited[r-1][c-1] = true;
        q.push({r-1, c-1});
    }

    // solution
    BFS();

    // output
    cout << GetVisitedNum() << '\n';

    return 0;
}