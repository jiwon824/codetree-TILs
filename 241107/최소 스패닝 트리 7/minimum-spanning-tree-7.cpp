#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 40'000;

int n, m, mst_sum, max_route, far_node;
vector<pair<int,int> > edges[MAX_N+1]; // edges[a]={b, w}
vector<pair<int,int> > mst_edges[MAX_N+1];
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
    
    // mst_edges를 사용하도록 수정
    for(auto e : mst_edges[curr_node]){
        int v=e.first, w=e.second;
        dfs(v, dist+w);
    }
}

void prim(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; //{weight, node}
    vector<int> parent(n+1, -1);  // 각 노드의 부모 노드를 저장
    
    // 1번 노드에서 시작
    dist[1]=0;
    pq.push({0, 1});
    
    while(!pq.empty()){
        int min_weight = pq.top().first, min_vertex = pq.top().second;
        pq.pop();
        
        if(visited[min_vertex]) continue;
        visited[min_vertex]=true;
        mst_sum+=min_weight;
        
        // parent가 있다면 (시작노드가 아니라면) mst_edges에 추가
        int parent_of_min_vertex = parent[min_vertex];
        if(parent_of_min_vertex != -1) {
            mst_edges[parent_of_min_vertex].push_back({min_vertex, min_weight});
            mst_edges[min_vertex].push_back({parent_of_min_vertex, min_weight});
        }
        
        // min_vertex에 이어진 간선 탐색
        for(auto e: edges[min_vertex]){
            int v=e.first, w=e.second;
            if(!visited[v] && dist[v]>w){
                dist[v]=w;
                parent[v] = min_vertex;  // v의 부모를 min_vertex로 설정
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
    max_route=0;
    dfs(1, 0);
    fill(visited, visited+(n+1), false);
    max_route=0;
    dfs(far_node, 0);

    // [output]
    cout << mst_sum << '\n';
    cout << max_route << '\n';
    return 0;
}