#include <iostream>

using namespace std;

// 상(-1, 0) 좌(0, -1) 하(1, 0)  우(0, 1)
int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};

int ToIntDir(char dir){
    switch(dir){
        case 'U':
            return 0;
            break;
        case 'L':
            return 1;
            break;
        case 'D':
            return 2;
            break;
        case 'R':
            return 3;
        default:
            break;
    }
    return -100;
}

int main() {
    // 첫 번째 줄에는 격자의 크기를 나타내는 n과 시간 t가 공백을 사이에 두고 주어집니다.
    int n, t;
    cin >> n >> t;
    // 두 번째 줄에는 구슬 정보 (x, y, d)가 공백을 사이에 두고 주어집니다.
    // 현재 구슬이 x행 y열에 놓여 있으며, d방향을 바라보고 있음을 뜻합니다.
    // d는 위 아래 오른쪽 왼쪽을 의미하는 ‘U', ‘D’, ‘R’, 'L’ 4개의 문자 중 하나가 주어집니다. 
    int x, y;
    char d;
    cin >> x >> y >> d;

    int moveDir = ToIntDir(d);
    for (int i=0;i<t;i++){
        int nx = x +dx[moveDir];
        int ny = y +dy[moveDir];
        // (nx, ny)가 n*n 범위를 벗어나면 방향전환
        // 0->2, 2->0, 1->3, 3->1로 바뀌어야 함
        if(nx<1 || ny<1 || nx>n || ny>n){
            moveDir =(moveDir+2)%4;
        }else{
            x=nx;
            y=ny;
        }
    }
    
    cout << x << " " << y<<"\n";
    return 0;
}