#include <iostream>
using namespace std;

const int MAX_N=101;

int n, m, v1, v2, e;
int graph[MAX_N][MAX_N];

void Init(){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            graph[i][j]=1e9;
        }
        // 자기자신으로 가는 비용은 0
        graph[i][i]=0;
    }
}

int main() {
    // input
    cin >> n >> m;
    Init();
    cin >> v1 >> v2 >> e;
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        // 양방향 그래프
        graph[a][b]=c;
        graph[b][a]=c;
    }

    // 최단거리 갱신
    for(int k=1; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                graph[i][j]=min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }

    int answer = 1e9;
    for(int k=1; k<=n; ++k){
        // (v1->k)+(v2->k)+(k->e)의 최소 비용을 구하면 됨
        answer = min(answer, graph[v1][k]+graph[v2][k]+graph[k][e]);
        
    }
    // 불가능 하다면 -1 출력
    if(answer==1e9) answer=-1;

    cout << answer << '\n';
    return 0;
}