#include <iostream>

using namespace std;

int n, m;
int bombs[201][201];
int explodeCol[11];

// Down Shift
void Drop(){
    for(int col=0; col<n; col++){
        int endOfIdx=-1;
        // 아래에서부터 0인 칸 찾기
        for(int row=n-1; row>0; row--){
            if(bombs[row][col]==0){
                endOfIdx=row;
                break;
            }
        }
        if(endOfIdx==-1) continue;

        // 위로 올라가면서 0이 아닌 칸이랑 자리 바꾸기
        for(int row=endOfIdx-1; row>=0; row--){
            if(bombs[row][col]!=0){
                bombs[endOfIdx][col]=bombs[row][col];
                bombs[row][col]=0;
                endOfIdx--;
            }
        }
    }
}

void Explode(int column){
    // 좌(0,-1) 상(-1,0) 우(0,1) 하(1,0)
    int dx[4]={0, -1, 0, 1};
    int dy[4]={-1, 0, 1, 0};

    for(int row=0; row<n; row++){
        if(bombs[row][column]==0)continue;
        for(int dir=0; dir<4; dir++){
            // range 범위: 1이면 자기칸만 터지고 2면 주변 1칸 터져야 하니까
            for(int range=1; range<bombs[row][column]; range++){
                int nx=row+dx[dir]*range;
                int ny=column+dy[dir]*range;
                if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                bombs[nx][ny]=0;
            }
        }
        bombs[row][column]=0;
        break;
    }
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> bombs[i][j];
        }
    }
    for(int i=0; i<m; i++){
        cin >> explodeCol[i];
    }

    // Solution
    for(int i=0; i<m; i++){
        Explode(explodeCol[i]-1);
        Drop();    
    }

    // output
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << bombs[i][j] << " ";
        }
        cout <<'\n';
    }
    return 0;
}