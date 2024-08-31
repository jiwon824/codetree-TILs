#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 101;

int n, half;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N]={false, };

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

// 색칠된 칸의 개수 반환
int Bfs(int startX, int startY, int d){
    // 상(-1,0) 하(1,0) 좌(0,-1) 우(0,1)
    int dx[4] ={-1, 1, 0, 0};
    int dy[4] ={0, 0, -1, 1};

    queue<pair<int,int>> q;
    
    q.push({startX, startY});
    visited[startX][startY]=true;
    int cnt=1;

    while(!q.empty()){
        int x = q.front().first, y=q.front().second;
        q.pop();
        for(int dir=0; dir<4; ++dir){
            int nx = x +dx[dir];
            int ny = y +dy[dir];
            // (배열 범위 && 방문x && 차이가 d이하)
            if(InRange(nx, ny) && !visited[nx][ny] && abs(arr[x][y]-arr[nx][ny])<=d){
                q.push({nx, ny});
                visited[nx][ny]=true;
                cnt++;
            }
        }
    }
    return cnt;
}

// 색칠된 칸이 전체 칸의 반 이상이라면 true 아니면 false 반환
bool IsPossible(int d){
    fill(&visited[0][0], &visited[0][0] + sizeof(visited), false);
    // 시작 위치 정하기
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            // 인접한 칸으로 이동하여 색칠하기
            if(!visited[i][j]){
                int cnt = Bfs(i, j, d);
                if(cnt>=half) return true;
            }
        }
    }
    return false;
}

int main() {
    // 입출력 최적화
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // input
    cin >> n;
    half=(n*n+1)/2; // 전체 칸 수가 홀수라면 전체 칸의 반은 반올림
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> arr[i][j];
        }
    }

    //  1. d를 이진 탐색으로 정하기
    // 칸 사이에 최대로 차이가 날 수 있는 범위는 0~1,000,000
    int left=0, right=1000000, answer=right;
    while(left<=right){
        int mid = (left+right)/2;
        // 2. 전체 칸의 반 이상을 채우는 것이 가능한지 판단(IsPossible(int d))
        // 결과에 따라 d의 크기를 키우거나(false), 줄이기(true)
        if(IsPossible(mid)){
            right=mid-1;
            answer=mid;
        }
        else left = mid+1;
    }

    cout << answer << '\n';
    return 0;
}