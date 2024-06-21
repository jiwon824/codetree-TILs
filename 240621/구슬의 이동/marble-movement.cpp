#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, t, k;

int arr[51][51];
vector<vector<int> > marble;

void PrintMarble(){
    for(int i=0; i<m; i++){
        for(int j=0; j<5; j++){
            cout << marble[i][j] << " ";
        }
        cout << '\n';
    }
}

void PrintArr(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

int DirConvertToInt(char dir){
    if (dir=='L') return 0;
    if (dir=='U') return 1;
    if (dir=='R') return 2;
    if (dir=='D') return 3;
    return -1;
}

// 우선순위: 속도가 빠른 구슬이 높음(같을 경우 구슬의 번호가 더 큰 구슬이 높음)
// 구슬의 번호는 입력된 순서
// 우선순위가 낮은 순서로 없앰
bool cmp(vector<int> &v1, vector<int> &v2){
    if(v1[4]==v2[4]) return v1[0]<v2[0];
    return v1[4]<v2[4];
}

void MoveMarble(){
    //L(0,-1) U(-1,0) R(0,1) D(1,0)
    int dx[4]={0, -1, 0, 1};
    int dy[4]={-1, 0, 1, 0};

    for(int i=0; i<m; ++i){
        int dir=marble[i][3];
        int move=marble[i][4];
        while (move--){
            int nx = marble[i][1]+dx[dir];
            int ny = marble[i][2]+dy[dir];
            if(!InRange(nx, ny)){
                dir= (dir+2)%4;
                nx = marble[i][1]+dx[dir];
                ny = marble[i][2]+dy[dir];
            }
            arr[marble[i][1]][marble[i][2]]--;
            marble[i][1]=nx;
            marble[i][2]=ny;
            marble[i][3]=dir;
            arr[nx][ny]++;
        }
    }
}

void RemoveMarble(int x, int y){
    // k이하가 될 때까지 우선순위에 따라 
    while (arr[x][y]>k){
        for(int i=0; i<marble.size(); i++){
            if(marble[i][1]==x && marble[i][2]==y){
                marble[i][1]=-1;
                marble[i][2]=-1;
                marble[i][4]=100; // 1<=v<=10
                arr[x][y]--;
                m--;
                break;
            }
        }
    }

    sort(marble.begin(), marble.end(), cmp);
    while(marble.size()>m){
        marble.pop_back();
    }
}

void Progress(){
    // t초 동안 반복
    while(t--){
        //1. 구슬 이동
        MoveMarble();

        //2. 구슬이 k개 이상이 칸 찾기
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                // 3. k이상이 칸에 있는 구슬 우선순위에 따라 삭제
                if(arr[i][j]>k) RemoveMarble(i, j);
            }
        }
    }
}

int main() {
    // input
    cin >> n >> m >> t >> k;
    for(int i=0; i<m; ++i){
        int r, c, v;
        char dir;
        cin >> r >> c >> dir >> v;
        marble.push_back({i, r-1, c-1, DirConvertToInt(dir), v});
        arr[r-1][c-1]=1;
    }

    sort(marble.begin(), marble.end(), cmp);
    Progress();

    // output
    cout << m << '\n';
    return 0;
}