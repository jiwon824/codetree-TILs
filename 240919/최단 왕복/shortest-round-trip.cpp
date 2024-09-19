#include <iostream>
using namespace std;

const int MAX_N = 101;

int n, m;
int dist[MAX_N][MAX_N];

void Init(){
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
    Init();
    for(int i=0; i<m; ++i){
        int v1, v2, d;
        cin >> v1 >> v2 >> d;
        // 그래프는 방향 그래프
        dist[v1][v2]=d;
    }
    
    // 최단 거리 갱신
    for(int k=1; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    int answer=1e9;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            // 서로 다른 정점 사이의 최단거리를 구해야 하므로
            if(i==j) continue;

            int d1 = (dist[i][j]==1e9) ? 0 : dist[i][j];
            int d2 = (dist[j][i]==1e9) ? 0 : dist[j][i];

            // 왕복을 이용하는 거리의 합 중 최소를 구해야 함
            if(d1==0 || d2==0) continue;

            answer = min(answer, d1+d2);
        }
    }
    cout << answer << '\n';
    return 0;
}