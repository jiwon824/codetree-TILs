#include <iostream>

using namespace std;

int n, m, r, c;
int arr[101][101];
int dirNum[10001];
// arr 좌표 안에 들어갈 수 관리
int dice[3]={1, 2, 3}; // 위 정면 오른쪽

int CharDirToInt(char d){
    if (d=='L') return 0;
    else if (d=='U') return 1;
    else if (d=='R') return 2;
    else return 3;
}

void RollTheDice(int d){
    if(d==0){
        int tmp = dice[0];
        dice[0]=dice[2];
        dice[2]=7-tmp;
    }
    else if(d==1){
        int tmp = dice[0];
        dice[0]=dice[1];
        dice[1]=7-tmp;
    }
    else if(d==2){
        int tmp = dice[2];
        dice[2]=dice[0];
        dice[0]=7-tmp;
    }
    else {
        int tmp = dice[1];
        dice[1]=dice[0];
        dice[0]=7-tmp;
    }
}

void Play(){
    // arr좌표를 움직이기 위한 dx dy
    // 좌(0,-1) 상(-1,0) 우(0,1) 하(1,0)
    int dx[4]={0, -1, 0, 1};
    int dy[4]={-1, 0, 1, 0};
    
    arr[r][c] = 7-dice[0];
    for(int i=0; i<m; ++i){
        int nx=r+dx[dirNum[i]];
        int ny=c+dy[dirNum[i]];
        if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
        
        RollTheDice(dirNum[i]);
        r=nx;
        c=ny;
        arr[r][c] = 7-dice[0];
    }
    
}

int main() {
    cin >> n >> m >> r >> c;
    r-=1;
    c-=1;
    for(int i=0; i<m; ++i){
        char d;
        cin >> d;
        dirNum[i]=CharDirToInt(d);
    }

    Play();

    int answer =0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            answer+=arr[i][j];
        }
    }
    cout << answer << '\n';
    return 0;
}