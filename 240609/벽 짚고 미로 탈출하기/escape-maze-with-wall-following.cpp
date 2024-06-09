#include <iostream>

using namespace std;
int n;
char map[101][101];
int visited[101][101];


bool IsPossible(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j]=='.'&&visited[i][j]==0) return true;
        }
    }
    return false; // 전부 1이면 못 나감
}

int Play(int x, int y){
    // 우(0, 1) 상(-1,0) 좌(0,-1) 하(1,0)
    int dx[4]={0, -1, 0, 1};
    int dy[4]={1, 0, -1, 0};

    // 방향을 트는 데에는 시간이 걸리지 않고 한 번 이동하는 데에는 1초의 시간이 걸린다
    int dir=0, time =0, rotationCnt=0;

    bool isEscape=true;
    while (true){
        if(!IsPossible()){
            isEscape = false;
            break;
        }
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        
        // 바라보고 있는 방향으로 이동하는 것이 가능하지 않은 경우
        if(map[nx][ny]=='#'){
        // 앞에 벽이 있으면 반시계 90도
            if(rotationCnt>=4){
                isEscape = false;
                break;
            }
            dir=(dir+1)%4;
            rotationCnt++;
            continue;
        }
        else{
            rotationCnt=0; // 한 자리에서 도는 경우가 아니니 초기화

            // 바로 앞이 격자 밖이라면 탈출
            if(nx<0 || nx>=n || ny<0 || ny>=n){
                time++;
                break;
            }
            
            //이동했을 때 오른쪽에 벽이 있는 경우
            if(map[nx+dx[(dir+3)%4]][ny+dy[(dir+3)%4]]=='#'){
                visited[x][y]=1;
                x=nx;
                y=ny;
                time++;
            }
            else{
                // 오른쪽에 벽이 없으면 한 칸 이동 후 시계방향 90도 한 칸 이동
                visited[x][y]=1;
                x=nx;
                y=ny;

                dir=(dir+3)%4;
                visited[x][y]=1;
                x+=dx[dir];
                y+=dy[dir];
                time+=2;
            }
        }
    }
    if(isEscape) return time;
    return -1;
}

int main() {
    int x, y;
    cin >> n >> x >> y;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    cout << Play(x-1, y-1) <<'\n';
    
    return 0;
}