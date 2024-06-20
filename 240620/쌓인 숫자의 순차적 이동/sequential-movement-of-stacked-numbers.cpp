#include <iostream>
#include <tuple>

using namespace std;

int n, m;
int arr[21][21][21*21];// [x][y][num] (x, y)에 들어간 숫자 num
int moveNum[101]; // 움직일 m개의 숫자

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

// num이 있는 배열의 좌표를 반환
tuple<int,int, int> FindCoordinate(int num){
    tuple<int,int, int> Coord;
    // (i,j)칸에 있는 k번째 수 num 찾기
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<n*n; ++k){
                if(arr[i][j][k]==0) break;
                if(arr[i][j][k]==num){
                    Coord = tie(i, j, k);
                    return Coord;
                }
            }
        }
    }
    return {-1, -1, -1};
}

// return: 8방향 중 최대값의 좌표, 8방향 모두 비어있을 경우 {-1, -1}
pair<int, int> FindNextCoord(int x, int y){
    // 좌상(-1,-1) 상(-1,0) 우상(-1,1) 우(0,1) 우하(1,1) 하(1,0) 좌하(1,-1) 좌(0,-1)
    int dx[8]={-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8]={-1, 0, 1, 1, 1, 0, -1, -1};

    int maxX=-1, maxY=-1, maxNum=0;
    // 8방향을 탐색하면서 최대값이 있는 좌표를 찾기
    for(int dir=0; dir<8; ++dir){
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        // 범위를 벗어남 || 비어있음
        if(!InRange(nx, ny) || arr[nx][ny][0]==0) continue;

        for(int idx=0; idx<n*n; ++idx){
            if(arr[nx][ny][idx]==0) break;

            // 최대값이 있는 곳
            if(maxNum < arr[nx][ny][idx]){
                maxX=nx;
                maxY=ny;
                maxNum = arr[nx][ny][idx];
            }
        }
    }
    
    return {maxX, maxY};
}

// 
void Move(int x, int y, int idx, int nx, int ny){
    int tmp[n*n]={0, };
    // 1. (x,y)에 있던 값을 tmp에 옮기기
    for(int i=0; i<=idx; ++i){
        tmp[i]=arr[x][y][i];
        arr[x][y][i]=0;
    }
    // 2.(nx,ny)에 있던 값을 tmp에 저장
    for(int i=0; ;++i){
        if(arr[nx][ny][i]==0) break;
        tmp[idx+1+i]=arr[nx][ny][i];
    }
    
    // 3. (nx, ny)에 있는 배열 tmp로 변경(tmp를 nx,ny에 복사하기)
    for(int i=0; ; ++i){
        if(tmp[i]==0) break; // 더 옮길 숫자가 없다면
        arr[nx][ny][i]=tmp[i];
    }

    // 4. (x, y)좌표에 있는 값 앞으로 당기기
    for(int i=idx+1; ; ++i){
        if(arr[x][y][i]==0) break;
        arr[x][y][i-idx-1]=arr[x][y][i];
        arr[x][y][i]=0;
    }
}

void Progress(){
    // moveNum 배열 순회
    for(int i=0; i<m; ++i){
        // 1. 옮겨야 할 숫자가 어느 좌표 몇 번째 idx에 있는지 찾기
        int x, y, idx; // [x][y][0]<=(범위)<=[x][y][idx]의 수를 모두 옮겨야 함
        tie(x, y, idx) = FindCoordinate(moveNum[i]);

        // 2. 해당 수를 어느 좌표로 옮겨야 하는지
        int nx, ny;
        tie(nx, ny) = FindNextCoord(x, y);
        if(nx==-1 && ny==-1) continue; // 8방향이 모두 비어있는 경우 움직이지 않음
        // 3. 옮기기
        Move(x, y, idx, nx, ny);
    }
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> arr[i][j][0];
        }
    }
    for(int i=0; i<m; ++i){
        cin >> moveNum[i];
    }

    //Solution
    Progress();

    // output
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            // 아무 수도 없다는 뜻이므로 None
            if(arr[i][j][0] == 0){
                cout <<"None\n";
                continue;
            }
            for(int k=0; k<n*n; ++k){
                if(arr[i][j][k]==0) break;
                cout << arr[i][j][k] << " ";
            }
            cout <<'\n';
        }
    }
    return 0;
}