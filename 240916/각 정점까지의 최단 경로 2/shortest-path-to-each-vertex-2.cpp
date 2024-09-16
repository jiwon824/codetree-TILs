#include <iostream>
using namespace std;

const int MAX_N = 101;

int n, m;
int dist[MAX_N][MAX_N];

void InitDist(){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            dist[i][j]=1e9;
        }
        dist[i][i]=0;
    }
}

int main() {
    // input
    cin >> n >> m;

    InitDist();
    for(int i=0; i<m; ++i){
        int v1, v2, d;
        cin >> v1 >> v2 >> d;
        //그래프는 방향 그래프 v1->v2
        dist[v1][v2]=min(dist[v1][v2], d);
    }

    // solution
    // 두 경로 i->j와 i->k->j를 비교 
    for(int k = 1; k <= n; k++){
        // 거쳐갈 정점 k에 대해 모든 쌍 (i, j)를 살펴봅니다.
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }


    // output
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            // 불가능하다면 -1을 출력
            if (dist[i][j]==1e9) dist[i][j]=-1;
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}