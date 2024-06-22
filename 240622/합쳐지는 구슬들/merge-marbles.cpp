#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, t;
int arr[51][51];
vector<vector<int> > marble;

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

bool cmp(vector<int> &v1, vector<int> &v2){
    return v1[0]<v2[0];
}

int DirConvertToInt(char dir){
    if(dir=='L')return 0;
    if(dir=='U')return 1;
    if(dir=='R')return 2;
    if(dir=='D')return 3;
    return -1;
}

void MoveMarble(){
    // L(0,-1) U(-1,0) R(0,1) D(1,0)
    int dx[4]={0, -1, 0, 1};
    int dy[4]={-1, 0, 1, 0};

    for(int i=0; i<marble.size(); ++i){
        int dir=marble[i][3];
        int nx=marble[i][1]+dx[dir];
        int ny=marble[i][2]+dy[dir];
        // 범위를 벗어나면 방향만 바꾸기
        if(!InRange(nx, ny)){
            dir=(dir+2)%4;
            marble[i][3]=dir;
            continue;
        }
        // 이동
        arr[marble[i][1]][marble[i][2]]--;
        marble[i][1]=nx;
        marble[i][2]=ny;
        arr[nx][ny]++;
    }
}

//이 구슬들이 합쳐지게 되면 하나의 구슬이 만들어지게 되고,
//[무게] 해당 위치에 모인 모든 구슬의 합
//[방향] 합쳐진 구슬들 중 가장 큰 번호가 매겨져있는 구슬의 방향
//[번호] 충돌이 일어난 구슬들 중 가장 큰 번호
void MergeMarble(int x, int y){
    int weight=0, maxNum=0, maxDir=0;

    //(x,y)에 있는 구슬 전부 삭제
    for(int i=0; i<marble.size(); ++i){
        if(marble[i][1]==x && marble[i][2]==y){
            if (marble[i][0] > maxNum) {
                maxNum = marble[i][0];
                maxDir = marble[i][3];
            }
            weight+=marble[i][4];
            marble[i][0]=3000; // 1<=m<=n*n 범위 밖의 값 설정
        }
    }

    // 합쳐진 구슬 추가
    marble.push_back({maxNum, x, y, maxDir, weight});
    m=m-arr[x][y]+1;
    arr[x][y]=1;

    sort(marble.begin(), marble.end(), cmp);

    while(marble.size()>m){
        marble.pop_back();
    }

}

void Progress(){
    while(t--){
        // 1.구슬 이동
        MoveMarble();

        // 2. 한 칸에 여러 개의 구슬이 있는지 체크
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                // 3. 구슬이 2개 이상인 칸은 구슬 합치기
                if(arr[i][j]>=2) MergeMarble(i, j);
            }
        }
    }
}

int main() {
    // input
    cin >> n >> m >> t;
    for(int i=0; i<m; ++i){
        int r, c, w;
        char d;
        cin >> r >> c >> d >> w;
        marble.push_back({i, r-1, c-1, DirConvertToInt(d), w});
        arr[r-1][c-1]=1;
    }
    
    // solution
    Progress();

    // output
    int maxWeight=0;
    for(int i=0; i<marble.size(); ++i){
        maxWeight=max(maxWeight, marble[i][4]);
    }
    cout << marble.size() << " " << maxWeight <<'\n';
    return 0;
}