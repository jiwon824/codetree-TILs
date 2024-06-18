#include <iostream>

using namespace std;

int n, m, t;
int arr[21][21];
int cntTable[21][21];

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

void RemoveBall(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(cntTable[i][j]>1) cntTable[i][j]=0;
        }
    }
}

void Move(int x, int y){
    // 상(-1,0)하(1,0)좌(0,-1)우(0,1) 방향 순서대로 우선순위
    int dx[4]={-1, 1, 0, 0};
    int dy[4]={0, 0, -1, 1};

    cntTable[x][y]=0;

    // 4방향 검사
    int maxX=x+dx[0], maxY=y+dy[0];
    for(int dir=1; dir<4; ++dir){
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        if(!InRange(nx, ny)) continue;

        if(arr[maxX][maxY]<arr[nx][ny]){
            maxX=nx;
            maxY=ny;
        }
    }

    // 4방향 중 가장 높은 곳으로 구슬 이동
    cntTable[maxX][maxY]++;
}

int Progress(){
    // t초 동안 반복
    for(int i=0; i<t; ++i){
        // (i, j)칸을 살펴보면서 구슬이 있다면 이동시킴
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(cntTable[i][j]==1) Move(i, j);
            }
        }

        // 공을 전부 이동시킨 후에 위치가 겹치는 공 삭제
        RemoveBall();
    }

    // 구슬이 몇 개 남았는지
    int answer=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(cntTable[i][j]==1) answer++;
        }
    }
    return answer;
}

int main() {
    cin >> n >> m >> t;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> arr[i][j];
        }
    }
    //m개의 구슬 시작 위치
    for(int i=0; i<m; ++i){
        int x, y;
        cin >> x >> y;
        cntTable[x-1][y-1]=1;
    }

    cout << Progress() << '\n';

    return 0;
}