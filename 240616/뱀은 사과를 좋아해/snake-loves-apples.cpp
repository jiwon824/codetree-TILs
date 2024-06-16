#include <iostream>
#include <vector>

#define HEAD 1
#define BODY 2
#define APPLE 3

using namespace std;

int n, m, k;
int arr[101][101];
vector<pair<int, int> > moveList;
vector<pair<int,int> > bodyPos;

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

int DirConvertToInt(char dir){
    if(dir=='L') return 0;
    else if(dir=='U') return 1;
    else if(dir=='R') return 2;
    else return 3;
}

bool Move(int& hX, int& hY, int nx, int ny){
    // 이동1: 사과를 먹은 경우
    if(arr[nx][ny]==APPLE){
        // 머리가 있던 자리에 몸통이 생김
        bodyPos.push_back({hX, hY});
        arr[hX][hY]=BODY;

        // 머리 이동
        hX = nx;
        hY = ny;
        arr[hX][hY]=HEAD;
        return true;
    }

    // 이동2: 머리만 있는 경우
    if(bodyPos.empty()){
        arr[hX][hY]=0;
        // 머리 이동
        hX=nx;
        hY=ny;
        arr[hX][hY]=HEAD;
        return true;
    }


    // 이동3: 일반 이동(몸통+머리)
    // 몸통 이동
    arr[bodyPos[0].first][bodyPos[0].second]=0;

    for(int i=0; i<bodyPos.size()-1; i++){
        bodyPos[i].first=bodyPos[i+1].first;
        bodyPos[i].second=bodyPos[i+1].second;
    }
    bodyPos[bodyPos.size()-1].first = hX;
    bodyPos[bodyPos.size()-1].second = hY;
    arr[hX][hY] = BODY;

    // [종료조건] 몸통이 꼬이는 경우(=nx, ny가 bodyPos에 있으면 안 됨)
    for(int i=0; i<bodyPos.size(); ++i){
        if(bodyPos[i].first==nx && bodyPos[i].second==ny) return false;
    }

    hX=nx;
    hY=ny;
    arr[hX][hY]=HEAD;
    return true;
}

int Play(){
    // 좌(0,-1) 상(-1,0) 우(0,1) 하(1,0)
    int dx[4]={0, -1, 0, 1};
    int dy[4]={-1, 0, 1, 0};

    int headX=0, headY=0, time=0;
    arr[headX][headY]= HEAD; //(0,0)에는 사과가 주어지지 않음
    for(auto i : moveList){
        // moveList에서 d, p를 꺼내온다.
        int dir = i.first, movement = i.second;
        // j칸 만큼 dir 방향으로 움직임
        for(int j=0; j<movement; ++j){
            int nx= headX+dx[dir];
            int ny= headY+dy[dir];
            // [종료조건] 격자를 벗어난 경우
            if(!InRange(nx, ny)) return ++time;
            // [종료조건] 몸통이 꼬인 경우
            if(!Move(headX, headY, nx, ny)) return ++time;

            time++;
        }
    }
    return time; // [종료조건] 전부 움직인 경우
}

int main() {
    // input
    cin >> n >> m >> k;
    for(int i=0; i<m; ++i){
        int x, y;
        cin >> x >> y;
        arr[x-1][y-1]= APPLE;
    }
    for(int i=0; i<k; ++i){
        char d;
        int p;
        cin >> d >> p;
        moveList.push_back({DirConvertToInt(d), p});
    }

    // solution & output
    cout << Play()<<'\n';
    //for(int i=0; i<n; i++){
    //    for(int j=0; j<n; j++){
    //        cout << arr[i][j] << " ";
    //    }
    //   cout << '\n';
    //}
    return 0;
}