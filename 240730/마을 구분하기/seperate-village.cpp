#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 26
using namespace std;

int n, sum;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N]={false, };
vector<int> population;

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}
bool CanGo(int x, int y){
    // 범위를 벗어남
    if(!InRange(x, y)) return false;
    // 방문함 || 벽
    if(visited[x][y] || arr[x][y]==0) return false;
    return true;
}

void DFS(int x, int y){
    // 상하좌우
    int dx[4]={-1, 1, 0, 0};
    int dy[4]={0, 0, -1, 1};

    visited[x][y]=true;
    sum++;
    
    for(int dir=0; dir<4; ++dir){
        int nx=x+dx[dir], ny=y+dy[dir];
        if(CanGo(nx, ny)){
            DFS(nx, ny);
        }
    }
}

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> arr[i][j];
        }
    }

    // solution
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            // 방문함 || 벽
            if(visited[i][j] || arr[i][j]==0) continue;
            // sum 초기화
            sum=0;
            DFS(i, j);
            population.push_back(sum);
        }
    }
    sort(population.begin(), population.end());

    // output
    cout << population.size() << '\n';
    for(size_t i=0; i<population.size(); ++i){
        cout << population[i] << '\n';
    }
    return 0;
}