#include <iostream>
using namespace std;

const int MAX_N = 101;

int n;
int arr[MAX_N][MAX_N];


bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

void Reversing(int x, int y){
    // 상하좌우
    int dx[4]={-1, 1, 0, 0};
    int dy[4]={0, 0, -1, 1};

    // 현재 칸 반전
    arr[x][y]^=1;

    // 상하좌우 반전
    for(int dir=0; dir<4; ++dir){
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        // 격자 내 범위라면 반전
        if(InRange(nx, ny)){
            arr[nx][ny]^=1;
        }
    }
}

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> arr[i][j];
        }
    }
    
    // 첫 번째 행은 못 누름(i=1부터 시작)
    int answer=0;
    for(int i=1; i<n; ++i){
        for(int j=0; j<n; ++j){
            // 위칸이 0이라면 무조건 눌러야함(위칸은 1로 만들 기회가 지금 뿐)
            if(arr[i-1][j]==0){
                Reversing(i, j);
                answer++;
            }
        }
    }

    bool impossible=false;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(arr[i][j]==0){
                impossible=true;
                break;
            }
        }
        if(impossible) break;
    }
    if(impossible) cout << -1 <<'\n';
    else cout << answer << '\n';
    return 0;
}