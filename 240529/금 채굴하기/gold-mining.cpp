#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring> // memset()

using namespace std;

int n, m, answer;
int map[21][21];
bool exploreRange[21][21] = {false, };

// 좌(0, -1) 상(-1, 0) 우 (0, 1) 하(1, 0)
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}
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
void MakeRange(int i, int j, int k){
    // 어차피 k=0부터 2*(n-1)까지 커지기 때문에 범위가 겹쳐도 상관 없음
    // map[i][j] 범위가 변경될 때 exploreRange를 초기화 해주면 된다
    memset(exploreRange, false, sizeof(exploreRange));
    queue<pair<int, int>> q;
    q.push({i, j});
    exploreRange[i][j]=true;

    for(int size=0; size<k; size++){
        int qSize = q.size();
        for(int qIdx =0; qIdx<qSize; qIdx++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int dir=0; dir<4; dir++){
                int nx = x+dx[dir];
                int ny = y+dy[dir];
                if(!InRange(nx, ny) || exploreRange[nx][ny]) continue;
                exploreRange[nx][ny]=true;
                q.push({nx, ny});
            }
        }
    }
}


void PointToExplore(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // map[i][j]에서 k크기 다이아 만들기
            for(int k=0; k<=2*(n-1); k++){
                //cout << "(" << i << ", " << j <<") 구간에서 " <<k<<"크기의 다이아\n";
                MakeRange(i, j, k);
                //for(int x=0; x<n; x++){
                //    for(int y=0; y<n; y++){
                //        cout <<exploreRange[x][y] << " ";
                //    }
                //    cout << '\n';
                //}

                int cost = k*k + (k+1)*(k+1);
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