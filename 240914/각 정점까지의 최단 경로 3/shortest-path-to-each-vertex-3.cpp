#include <iostream>

using namespace std;

const int MAX_N = 101;

int n, m;

int graph[MAX_N][MAX_N];
int dist[MAX_N];
bool visited[MAX_N]={false, };

void InitDist(){
    //1번 정점에서 다른 모든 정점으로 가는 최단 경로를 구하는 프로그램
    // dist[0]=0으로 둔다
    for(int i=1; i<n; ++i){
        dist[i]=1e9;
    }
}

int FindMinVertex(){
    int min_vertex=-1;
    for(int i=0; i<n; ++i){
        // 방문한 점은 다시 방문하지 않도록 처리
        if (visited[i]) continue;

        // 최소값으로 갱신
        if(min_vertex==-1 || dist[min_vertex]>dist[i]){
            min_vertex=i;
        }
    }
    return min_vertex;
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int s, e, v;
        cin >> s >> e >> v;
        // 단방향 그래프라서 [e][s]는 그대로 둠
        graph[s-1][e-1] = v;
    }

    // solution
    InitDist();

    for(int i=0; i<n; ++i){
        // 최소값 찾기 & 방문 체크
        int min_vertex=FindMinVertex();
        visited[min_vertex]=true;

        // min_vertex와 이어진 정점 dist 갱신
        for(int j=0; j<n; ++j){
            // min_vertex에서 시작해서 j정점으로 이어진 간선 존재x
            if(graph[min_vertex][j]==0) continue;
            
            // 1. dist의 원래 거리
            // 2. 시작 점에서 min_vertex까지의 거리+min_vertex에서 j까지의 거리
            // 1과 2 중 작은 값으로 갱신
            dist[j]=min(dist[j], dist[min_vertex]+graph[min_vertex][j]);
        }
    }

    // output
    for(int i=1; i<n; ++i){
        if (dist[i]==1e9) dist[i]=-1;

        cout << dist[i] << '\n';
    }
    return 0;
}