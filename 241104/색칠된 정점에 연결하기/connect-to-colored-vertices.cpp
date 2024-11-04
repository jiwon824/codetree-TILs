#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100'000;

int n, m, k;
vector<pair<int,int> > edges[MAX_N+1]; // edges[a]={b, w}
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<>> pq;//{weight, node}
int dist[MAX_N+1];
bool visited[MAX_N+1]={false, };

void initDist(){
    for(int i=0; i<=n; ++i){
        dist[i]=1e9;
    }
}

// Prim알고리즘의 시작점을 색칠된 정점으로 하면 되는 문제
int main() {
    // [input]정점의 개수 n과, 간선의 개수 m, 특정한 정점의 개수 k
    cin >> n >> m >> k;
    
    initDist();

    // [input]k개의 색칠된 정점의 번호
    for(int i=0; i<k; ++i){
        int node;
        cin >> node;
        // 색칠된 정점에서 시작하도록 설정
        pq.push({0, node});
        dist[node]=0;
    }
    // [input]m개의 줄에 걸쳐 각 간선의 양 끝 정점의 번호와 해당 간선의 가중치
    for(int i=0; i<m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    // 100'000*10'000=1'000'000'000
    int answer=0;
    while(!pq.empty()){
        int min_weight = pq.top().first, min_vertex=pq.top().second;
        pq.pop();

        if(visited[min_vertex]) continue;
        visited[min_vertex]=true;
        answer+=min_weight;

        // min_vertex에 연결된 점 탐색
        for(auto e: edges[min_vertex]){
            int v=e.first, w=e.second;
            if(!visited[v]&&dist[v]>w){
                dist[v]=w;
                pq.push({w, v});
            }
        }
    }
    cout << answer <<'\n';
    return 0;
}