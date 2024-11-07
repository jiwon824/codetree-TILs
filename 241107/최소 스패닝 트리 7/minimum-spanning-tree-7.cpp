#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 40'000;
int n, m, mst_sum, max_route, far_node;
vector<pair<int,int> > edges[MAX_N+1]; // edges[a]={b, w}
int dist[MAX_N+1];
bool visited[MAX_N+1]={false, };

void initDist(){
    for(int i=0; i<=n; ++i){
        dist[i]=1e9;
    }
}

// 1번 노드에서 시작해서 가장 먼 노드를 찾기
// 가장 먼 노드에서 가장 먼 노드 구하기(트리의 지름)
void dfs(int curr_node, int dist){
    if(visited[curr_node]) return;
    visited[curr_node]=true;

    if(dist>max_route){
        max_route=dist;
        far_node=curr_node;
    }

    // 현재 노드에 연결된 노드 탐색
    for(auto e : edges[curr_node]){
        int v=e.first, w=e.second;
        dfs(v, dist+w);
    }
}

void prim(){
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<>> pq;//{weight, node}
    
    // 1번 노드에서 시작
    dist[1]=0;
    pq.push({0, 1});

    while(!pq.empty()){
        int min_weight = pq.top().first, min_vertex = pq.top().second;
        pq.pop();

        if(visited[min_vertex]) continue;
        visited[min_vertex]=true;
        mst_sum+=min_weight;

        // min_vertex에 이어진 간선 탐색
        for(auto e: edges[min_vertex]){
            int v=e.first, w=e.second;
            if(!visited[v] && dist[v]>w){
                dist[v]=w;
                pq.push({w, v});
            }
        }
    }

}

int main() {
    // [input] 정점의 개수 n, 간선의 개수 m
    cin >> n >> m;
    initDist();
    // [input] m개의 줄에 걸쳐, 각 간선의 양 끝 점과 가중치
    for(int i=0; i<m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    // [solution]
    fill(visited, visited+(n+1), false);
    prim();

    // [solution] 트리의 지름 구하기
    fill(visited, visited+(n+1), false);
    dfs(1, 0);
    fill(visited, visited+(n+1), false);
    dfs(far_node, 0);

    // [output]
    cout << mst_sum << '\n';
    cout << max_route << '\n';
    return 0;
}