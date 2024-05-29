#include <iostream>
#include <algorithm>
#include <cstring> // memset()

using namespace std;

int n, m, answer;
int map[21][21];
bool exploreRange[21][21] = {false, };

// 좌(0, -1) 상(-1, 0) 우 (0, 1) 하(1, 0)
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

// (exploreRange[i][j]==true && map[i][j]==1) gold++
int MiningGold(){
    int gold =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(exploreRange[i][j] && map[i][j]==1) gold++;
        }
    }
    return gold;
}

// k크기의 다이아 만들기
void MakeRange(int i, int j, int size, int k){
    //if (size==0) exploreRange[i][j]=true;
    // 종료 조건
    if(size==k){
        return;
    }

    // 재귀 호출
    for(int dir=0; dir<4; dir++){
        exploreRange[i][j]=true;

        int nx= i+dx[dir];
        int ny= j+dy[dir];
        // 범위를 넘어가면 continue
        if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
        MakeRange(nx, ny, size+1, k);
    }
}


void PointToExplore(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // 어차피 k=0부터 n-1까지 커지기 때문에 범위가 겹쳐도 상관 없음
            // map[i][j] 범위가 변경될 때 exploreRange를 초기화 해주면 된다
            memset(exploreRange, false, sizeof(exploreRange));

            // map[i][j]에서 k크기 다이아 만들기
            for(int k=1; k<=n; k++){
                MakeRange(i, j, 0, k);
                //cout << "(" << i << ", " << j <<") 구간에서 " <<k<<"크기의 다이아\n";
                //for(int x=0; x<n; x++){
                //    for(int y=0; y<n; y++){
                //        cout <<exploreRange[x][y] << " ";
                //    }
                //    cout << '\n';
                //}

                // 비용 계산 k=1이 문제에서의 k=0이기 때문에 k에 k-1을 대입해야 함
                int cost = k*k + (k-1)*(k-1);
                int gold = MiningGold();
                // 손해보지 않는다면 최대 금 갯수 갱신
                if(gold*m-cost>=0) answer = max(answer, gold);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    PointToExplore();
    cout << answer;

    return 0;
}