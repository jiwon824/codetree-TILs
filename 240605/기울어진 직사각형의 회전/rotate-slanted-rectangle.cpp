#include <iostream>

using namespace std;

int n, r, c, m1, m2, m3, m4, dir;
int arr[101][101];

void GetInput(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;
    r-=1;
    c-=1;
}

void PrintArr(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}
// (r, c) 회전이 시작되는 아래의 점
// width: m1, m3의 길이, height: m2, m4의 크기
// dir: 0 반시계 방향 회전, 1 시계 방향 회전
void Rotate(){
    if (dir==0){
        // 반시계 회전
        // shift line1
        int lastElementOfL1 = arr[r-m1][c+m1];
        for(int i=m1; i>0; i--){
            // 좌하(1, -1)에 있는 원소를 현재 칸에 넣어야 함
            arr[r-i][c+i]=arr[r-i+1][c+i-1];
        }

        //shift line2
        // [r-m1][c+m1]에서 좌상(-1,-1)으로 height 만큼 가야함
        int lastElementOfL2=arr[r-m1-m2][c+m1-m2];
        for(int i=m2; i>1; i--){
            //우하(1,1)에 있는 원소를 현재 칸에 넣어야 함
            arr[r-m1-i+1][c+m1-i+1]=arr[r-m1-i][c+m1-i];
        }
        arr[r-m1-1][c+m1-1]=lastElementOfL1;

        //shift line3
        // r,c에서 좌상으로 hight만큼 간 값
        int lastElementOfL3=arr[r-m4][c-m4];
        for(int i=0; i<m3-1; i++){
            // 우상(-1,1)에 있는 값을 마지막 값에서부터 당기기
            arr[r-m4-i][c-m4+i]=arr[r-m4-i-1][c-m4+i+1];
        }
        arr[r-m1-m2+1][c+m1-m2-1]=lastElementOfL2;

        //shift line4
        for(int i=1; i<m4; i++){
            arr[r][c]=arr[r-i][c-i];
        }
        arr[r-m4+1][c-m4+1]=lastElementOfL3;

    }
    else{
        // 시계 회전
        // shift line1
        int lastElementOfL1 = arr[r-m4][c-m4];
        for(int i=m4; i>0; i--){
            arr[r-i][c-i]=arr[r-i+1][c-i+1];
        }

        // shift line2
        int lastElementOfL2=arr[r-m4-m3][c-m4+m3];
        for(int i=m3; i>0; i--){
            arr[r-m4-i][c-m4+i]=arr[r-m4-i+1][c-m4+i-1];
        }
        arr[r-m4-1][c-m4+1]=lastElementOfL1;

        // shift line3
        int lastElementOfL3=arr[r-m1][c+m1];
        for(int i=0; i<m2; i++){
            arr[r-m1-i][c+m1-i]=arr[r-m1-i-1][c+m1-i-1];
        }
        arr[r-m4-m3+1][c-m4+m3+1]=lastElementOfL2;

        // shift line4
        for(int i=0; i<m1;i++){
            arr[r-i][c+i]=arr[r-i-1][c+i+1];
        }
        arr[r-m1+1][c+m1-1]=lastElementOfL3;
    }
}

int main() {
    GetInput();

    Rotate();

    PrintArr();
    return 0;
}