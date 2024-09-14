#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100001;

int n, m;

// int graph[MAX_N][MAX_N]; // graph 배열의 크기: int graph[MAX_N][MAX_N];는 매우 큰 2차원 배열을 선언하려고 합니다. MAX_N이 100001이므로, 이는 약 40GB의 메모리를 요구하게 됩니다. 이는 대부분의 시스템에서 스택 오버플로우를 일으킬 것입니다.
// vector<pair<int,int> > graph[MAX_N]; // 가능

vector<vector<pair<int, int>>> graph(MAX_N); // graph[i][j]={vertex, dist} i->vertex까지 dist
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;// {mindist, vertex}
int dist[MAX_N];

void InitDist(){ 
    // n-1에서 다른 모든 정점으로의 거리를 구해야 함 -> n-2까지 초기화
    for(int i=0; i<n-1; ++i){
        dist[i]=1e9;
    }
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int s, e, d;
        cin >> s >> e >> d;
        // 모든 정점으로부터 특정 도착점까지의 최단거리를 구하기 위해 거꾸로 저장
        // e->s까지의 거리
        graph[e-1].push_back({s-1, d});
    }

    // solution
    InitDist();
    // 출발지점과 거리를 queue에 push
    pq.push({0, n-1});

    while(!pq.empty()){
        int min_dist = pq.top().first, min_vertex=pq.top().second;
        pq.pop();

        // 이미 갱신된 상태라면 패스
        // (같은 정점의 원소가 여러 번 들어가는 문제가 있을 수 있어서 처리)
        if(min_dist != dist[min_vertex]) continue;

        for(int j=0; j<graph[min_vertex].size(); ++j){
            // graph[i][j]={vertex, dist} i->vertex까지 dist
            int v=graph[min_vertex][j].first, d=graph[min_vertex][j].second;
            int new_dist = dist[min_vertex]+d;
            dist[v]=min(dist[v], new_dist);
            // {mindist, vertex}
            pq.push({new_dist, v});
        }
    }

    // output
    int answer=0;
    for(int i=0; i<n; ++i){
        if(dist[i]==1e9) dist[i]=-1;
        answer=max(answer, dist[i]);
    }
    cout << answer << '\n';
    return 0;
}