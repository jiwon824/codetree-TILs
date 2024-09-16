#include <iostream>
using namespace std;

const int MAX_N = 101;

int n, m;
int dist[MAX_N][MAX_N];

int main() {
    //input
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cin >> dist[i][j];
        }
    }

    // solution: 최단거리로 갱신
    for(int k=1; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                // i->j와 i->k->j 중 짧은 것으로 갱신
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    // output
    while(m--){
        int v1, v2;
        cin >> v1 >> v2;
        cout << dist[v1][v2] << '\n';
    }
    return 0;
}