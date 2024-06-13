#include <iostream>
#include <algorithm> // copy()

using namespace std;

int base[51][51];
int tmp[51][51];
int n, answer;

void PrintArr(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << tmp[i][j] << " ";
        }
        cout << '\n';
    }
}

void FindNumOfPairs(){
    // 좌(0,-1) 상(-1,0) 우(0,1) 하(1,0)
    int dx[4]={0, -1, 0, 1};
    int dy[4]={-1, 0, 1, 0};

    int cnt=0;
    for(int row=0; row<n; ++row){
        for(int col=0; col<n; ++col){
            for(int dir=0; dir<4; ++dir){
                int nx=row+dx[dir];
                int ny=col+dy[dir];
                if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                if(tmp[row][col]!=0 && tmp[row][col]==tmp[nx][ny])cnt++;
            }
        }
    }
    answer = max(answer, cnt/2); // 중복 때문에 cnt를 2로 나눠줘야 한다
}

void Drop(){
    for(int col=0; col<n; ++col){
        // 0찾기
        int endOfIdx=-1;
        for(int row=n-1; row>0; --row){
            if(tmp[row][col]==0){
                endOfIdx=row;
                break;
            }
        }
        if(endOfIdx==-1) continue;

        //0채우기(swap)
        for(int row=endOfIdx-1; row>=0; --row){
            if(tmp[row][col]!=0){
                tmp[endOfIdx][col]=tmp[row][col];
                tmp[row][col]=0;
                endOfIdx--;
            }
        }
    }
}

void Explode(int x, int y){
    // 좌(0,-1) 상(-1,0) 우(0,1) 하(1,0)
    int dx[4]={0, -1, 0, 1};
    int dy[4]={-1, 0, 1, 0};

    for(int dir=0; dir<4; ++dir){
        int currX=x, currY=y, range=base[x][y];

        for(int r=1; r<range; ++r){
            currX+=dx[dir];
            currY+=dy[dir];
            if(currX<0 || currX>=n || currY<0 || currY>=n) continue;
            tmp[currX][currY]=0;
        }
    }

    tmp[x][y]=0;
}

void SetPoint(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            // base 배열을 copy에 복사
            for (int k = 0; k < n; ++k) {
                copy(begin(base[k]), end(base[k]), begin(tmp[k]));
            }
        
            Explode(i, j);
            Drop();
            FindNumOfPairs();
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> base[i][j];
        }
    }

    SetPoint();
    cout << answer << '\n';
    return 0;
}