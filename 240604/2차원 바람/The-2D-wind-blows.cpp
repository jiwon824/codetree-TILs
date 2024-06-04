#include <iostream>

using namespace std;

int n, m, q;
int building[101][101];
int wind[101][4]; // 1-base {{r1, c1, r2, c2}, ...}

void GetInput(){
    cin >> n >> m >> q;
    // input n*m arr
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> building[i][j];
        }
    }
    // input wind
    for(int i=0; i<q; i++){
        cin >> wind[i][0] >> wind[i][1] >> wind[i][2] >> wind[i][3];
    }
}

void PrintArr(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << building[i][j] << " ";
        }
        cout << '\n';
    }
}

//직사각형 영역의 경계에 있는 숫자들을 시계 방향으로 한 칸씩 shift
void RotateShift(int r1, int c1, int r2, int c2){
    // r1줄 오른쪽으로 한 칸씩 옮기기 ->
    int r1c2= building[r1][c2];
    for(int i=c2; i>c1; i--){
        building[r1][i]= building[r1][i-1];
    }
    
    // c2줄 아래로 한 칸씩 옮기기
    int r2c2 = building[r2][c2];
    for(int i=r2; i>r1+1; i--){
        building[i][c2]=building[i-1][c2];
    }
    building[r1+1][c2] = r1c2;

    int r2c1=building[r2][c1];
    for(int i=c1; i<c2-1; i++){
        building[r2][i]= building[r2][i+1];
    }
    building[r2][c2-1]= r2c2;

    for(int i=r1; i<r2-1; i++){
        building[i][c1]=building[i+1][c1];
    }
    building[r2-1][c1] =r2c1;
}

// 직사각형 영역 내에 있는 각각의 숫자들의 값이 [현재 칸에 적혀있는 숫자 + 인접한 곳에 적혀있는 숫자들의 평균 값]으로 바뀌게 됩니다.
// 이 과정은 순차적으로 일어나는 것이 아니라 동시에 일어납니다. 평균 계산시에는 항상 버림하여 정수값이 나오도록 합니다.
void ChangeToAvg(int r1, int c1, int r2, int c2){
    // 좌(0, -1) 상(-1, 0) 하(1, 0) 우(0, 1)
    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {-1, 0, 0, 1};

    // 자신+상하좌우 살피면서 avgArr 채우기
    int avgArr[r2-r1+1][c2-c1+1]={0, };

    for(int i=r1; i<=r2; i++){
        for(int j=c1; j<=c2; j++){
            int sum=building[i][j], cnt=1;
            
            for(int dir=0; dir<4; dir++){
                int x= i+dx[dir], y=j+dy[dir];
                // 범위를 넘어가면 continue;
                if(x<0 || x>=n || y<0 || y>=m) continue;
                sum+=building[x][y];
                cnt++;
            }

            float avg = sum/cnt;
            avgArr[i-r1][j-c1]= static_cast<int>(avg);
        }
    }


    // avgArr의 원소를 building 배열에 복사
    for(int i=r1; i<=r2; i++){
        for(int j=c1; j<=c2; j++){
            building[i][j] = avgArr[i-r1][j-c1];
        }
    }
}

void WindStart(){
    for(int i=0; i<q; i++){
        // 1based라서 1 빼줘야 함
        int r1 = --wind[i][0], c1 = --wind[i][1], r2=--wind[i][2], c2=--wind[i][3];
        RotateShift(r1, c1, r2, c2);
        ChangeToAvg(r1, c1, r2, c2);
    }
}

int main() {
    GetInput();

    WindStart();

    PrintArr();
    return 0;
}