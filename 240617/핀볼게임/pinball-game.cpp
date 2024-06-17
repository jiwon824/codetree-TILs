#include <iostream>
#include <algorithm>

#define DOWN 0
#define LEFT 1
#define UP 2
#define RIGHT 3

using namespace std;

int n, answer;
int board[101][101]; // 0: ' ', 1: '/', 2: '\'

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

// return: rotated direction
int Rotate(int wall, int dir){
    if(dir==DOWN){
        if(wall==1) return LEFT; // '/'
        return RIGHT; // '\'
    }
    if(dir==LEFT){
        if(wall==1) return DOWN; // '/'
        return UP; // '\'
    }
    if(dir==UP){
        if(wall==1) return RIGHT; // '/'
        return LEFT; // '\'
    }
    if(dir==RIGHT){
        if(wall==1) return UP; // '/'
        return DOWN; // '\'
    }

    return -1;
}

int StartGame(int x, int y, int dir){
    // 하(1,0) 좌(0,-1) 상(-1,0) 우(0,1)
    int dx[4]={1, 0, -1, 0};
    int dy[4]={0, -1, 0, 1};

    int time=1; // 구슬이 들어오는 시간 포함
    
    // 들어온 칸이 바로 회전칸인 경우
    if(board[x][y]!=0) dir=Rotate(board[x][y], dir);

    while(true){
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        if(!InRange(nx, ny)) break;

        if(board[nx][ny]==0){
            x=nx;
            y=ny;
        }
        else{
            // 이동 후 방향 전환
            x=nx;
            y=ny;
            dir=Rotate(board[x][y], dir);
        }
        time++;
    }

    return time+1; // 구슬이 나가는 시간 포함
}

void Progress(){
    // Pick Start Point & Dir
    // Down
    for(int col=0; col<n; ++col){
        answer=max(answer, StartGame(0, col, DOWN));
    }
    // Left
    for(int row=0; row<n; ++row){
        answer=max(answer, StartGame(row, n-1, LEFT));
    }
    // Up
    for(int col=n-1; col>=0; --col){
        answer=max(answer, StartGame(n-1, col, UP));
    }
    // Right
    for(int row=n-1; row>=0; --row){
        answer=max(answer, StartGame(row, 0, RIGHT));
    }
}

// 시작점을 적절하게 선택하여 격자 밖으로 나오는데까지 걸리는 시간이 최대가 되도록 하는 프로그램을 작성
int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> board[i][j];
        }
    }
    
    Progress();

    cout << answer << '\n';
    return 0;
}