#include <iostream>
using namespace std;

int n, m;
int arr[21][21];

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

void Swap(int& a, int& b){
    int tmp=a;
    a=b;
    b=tmp;
}

// 주위 8방향 중 가장 큰 값과 교환
void SelectMax(int x, int y){
    // 좌상(-1,-1) 상(-1,0) 우상(-1,1) 우(0,1) 우하(1,1) 하(1,0) 좌하(1,-1) 좌(0,-1)
    int dx[8]={-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8]={-1, 0, 1, 1, 1, 0, -1, -1};

    int maxX=-1, maxY=-1;
    for(int dir=0; dir<8; ++dir){
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        if(!InRange(nx, ny)) continue;

        if(maxX==-1){
            maxX=nx;
            maxY=ny;
        }

        if(arr[maxX][maxY]<arr[nx][ny]){
            maxX=nx;
            maxY=ny;
        }
    }

    Swap(arr[x][y], arr[maxX][maxY]);
}

void Progress(){
    for(int turn=0; turn<m; ++turn){
        int num=1;
        //1이 적힌 칸부터 n*n이 적힌 칸까지 순차적 swap 
        while(num<=n*n){
    
            bool isDone=false;
            for(int i=0; i<n; ++i){
                for(int j=0; j<n; ++j){
                    if(arr[i][j]==num){
                        SelectMax(i, j);
                        isDone=true;
                        break;
                    }
                }
                if(isDone) break;
            }
            num++;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> arr[i][j];
        }
    }

    Progress();

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}