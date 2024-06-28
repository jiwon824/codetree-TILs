#include <iostream>
#include <queue>

using namespace std;

int n, m, answer;
int arr[101][101];
bool visited[101][101]={false, };

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

bool CanGo(int x, int y){
    if(!InRange(x, y)) return false;
    if(arr[x][y]==0||visited[x][y]) return false;
    return true;
}

void BFS(){
    // 상(-1,0) 하(1,0) 좌(0,-1) 우(0,1)
    int dx[4]={-1, 1, 0, 0};
    int dy[4]={0, 0, -1, 1};

    queue<pair<int, int> > q;
    q.push({0, 0});
    while(!q.empty()){
        int size = q.size();
        for(int qIdx=0; qIdx<size; ++qIdx){
            int x=q.front().first, y=q.front().second;
            q.pop();
            if(x==n-1 && y==m-1) {
                answer=1;
                return;
            }

            visited[x][y] = true;
            for(int dir=0; dir<4; ++dir){
                int nx=x+dx[dir], ny=y+dy[dir];
                if(CanGo(nx, ny)){
                    q.push({nx, ny});
                }
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

    //output
    cout << answer <<'\n';
    return 0;
}