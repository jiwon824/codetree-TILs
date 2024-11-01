#include <iostream>

using namespace std;

const int MAX_N = 4;
const int DIR_NUM = 8;

int n, startX, startY, answer;
int numArr[MAX_N+1][MAX_N+1];
int dirArr[MAX_N+1][MAX_N+1];


bool inRange(int x, int y){
    return x>0 && x<=n && y>0 && y<=n;
}
bool canGo(int x, int y, int currNum){
    return inRange(x, y) && numArr[x][y] > currNum;
}

void move(int x, int y, int cnt){
    // 상(-1, 0)부터 시계방향으로 1-based이므로 [0]=0으로 설정
    int dx[DIR_NUM+1] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
    int dy[DIR_NUM+1] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

    int currDir = dirArr[x][y];
    int currNum = numArr[x][y];

    answer=max(answer, cnt);

    for(int i=1; i<n; ++i){
        int nx = x+dx[currDir]*i, ny = y+dy[currDir]*i;
        // 갈 수 없다면 넘어감
        if(!canGo(nx, ny, currNum)) continue;
        move(nx, ny, cnt+1);
    }
    
}

int main() {
    // [input]
    cin >> n;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cin >> numArr[i][j];
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cin >> dirArr[i][j];
        }
    }
    cin >> startX >> startY;

    // [solution]
    move(startX, startY, 0);

    cout << answer << '\n';
    return 0;
}