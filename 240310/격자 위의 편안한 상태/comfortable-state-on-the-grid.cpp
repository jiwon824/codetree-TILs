#include <iostream>

using namespace std;

// 상 (-1, 0) 우(0, 1) 하(1, 0) 좌(0, -1)
int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
int** map;
//‘편안한 상태’란 방금 막 칠해진 칸을 기점으로 위 아래 양옆으로 인접한 4개의 칸 중 격자를 벗어나지 않는 칸에 색칠되어 있는 칸이 정확히 3개인 경우
bool IsComfortable(int x, int y, int n){
    int cnt=0;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
        if(map[nx][ny]==1) cnt++;
    }
    if (cnt==3) return true;
    else return false;
}
int main() {
    int n, m;
    cin >> n >> m;

    // n*n 격자 만들기
    map = new int*[n];
    for (int i=0;i<n;i++){
        map[i]= new int[n];
    }

    //m개의 줄에 걸쳐 색칠할 칸의 위치 입력
    for (int i=0; i<m; i++){
        int r, c;
        cin >> r >> c;
        // 해당 문제는 [0][0]을 [1][1]로 취급
        map[r-1][c-1]=1;
        // 해당 칸을 칠한 직후 막 칠한 칸이 편안한 상태에 있는지 확인
        cout << IsComfortable(r-1, c-1, n) << "\n";
    }
    return 0;
}