#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 20001;

int n, m, k; // 정점의 수, 간선의 수, 시작 정점

vector<pair<int, int> > graph[MAX_N];
priority_queue<pair<int, int>, vector<pair<int,int> >, greater<>> pq; // {dist, vertex}
int dist[MAX_N];

void InitDist(){
    //k번 정점에서 다른 모든 정점으로 가는 최단 경로를 구하는 프로그램
    for(int i=0; i<n; ++i){
        dist[i]=1e9;
    }
    // 1-based -> 0-based
    dist[k-1]=0;
}

int main() {
    // input
    cin >> n >> m >> k;
    for(int i=0; i<m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        // 정점 n 개와 간선 m 개로 구성된 무방향 그래프
        graph[a-1].push_back({b-1, w});
        graph[b-1].push_back({a-1, w});
    }

    // solution
    InitDist();

    // 시작 정점을 큐에 넣어줌
    pq.push({0, k-1});
    while(!pq.empty()){
        // 가장 거리가 가까운 정점의 정보
        int min_dist=pq.top().first, min_vertex=pq.top().second;
        pq.pop();

        // 이미 갱신된 상태라면 패스
        // (같은 정점의 원소가 여러 번 들어가는 문제가 있을 수 있어서 처리)
        if(min_dist != dist[min_vertex]) continue;

        // graph[min_vertex]에 연결된 정점들 거리 갱신
        for(int j = 0; j<graph[min_vertex].size(); j++) {
            int vertex = graph[min_vertex][j].first, weight = graph[min_vertex][j].second;
            dist[vertex] = min(dist[vertex], dist[min_vertex]+weight);
            pq.push({dist[min_vertex]+weight, vertex});
        }
    }

    //output
    for(int i=0; i<n; ++i){
        // 도달하는 것이 불가능하다면 -1을 출력
        if (dist[i]==1e9) dist[i]=-1;
        cout << dist[i] << '\n';
    }
    return 0;
}