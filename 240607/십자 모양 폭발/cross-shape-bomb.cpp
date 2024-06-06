#include <iostream>

using namespace std;
int n;
int arr[201][201]; //1이상 100이하의 숫자로 구성

void PrintArr(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}

void GravitationalActions(){
    for(int col=0; col<n; col++){
        int endOfIdx=-1;
        for(int row=n-1; row>0; row--){
            if(arr[row][col]==0){
                endOfIdx=row;

                int x=row;
                while(arr[x][col]==0){
                    x--;
                    if(x<0) break;
                }
                if(x<0) continue;

                arr[endOfIdx][col]=arr[x][col];
                arr[x][col]=0;
                endOfIdx-=1;
            }
        }
    }
}

void Explode(int r, int c){
    // 좌(0,-1)상(-1,0)우(0,1)하(1,0)
    int dx[4]={0, -1, 0, 1};
    int dy[4]={-1, 0, 1, 0};
    
    int explosionRange = arr[r][c]-1;
    for(int dir=0; dir<4; dir++){
        if(explosionRange==0) break;

        int x=r, y=c;
        for(int move=0; move<explosionRange; move++){
            x+=dx[dir];
            y+=dy[dir];
            if(x<0 || x>=n || y<0 || y>=n) break; //같은 방향으로 가니까 한 번 범위를 벗어나면 쭉 벗어남
            arr[x][y]=0; // 범위를 벗어나지 않으면 폭발시키기
        }

    }
    arr[r][c]=0;
    
    GravitationalActions();
}

int main() {
    //input
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    int r, c;
    cin >> r >> c;

    Explode(r-1, c-1);
    
    PrintArr();
    return 0;
}