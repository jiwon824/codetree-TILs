#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int MAX_N = 1001;

int n, m;
int start_v, end_v;
vector<vector<pair<int,int>>> graph(MAX_N);
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
int dist[MAX_N];
int path[MAX_N]; // 경로

void Init(){
    for(int i=1; i<=n; ++i){
        dist[i]=1e9;
        path[i]=-1;
    }
    // 시작 위치는 0으로 초기화
    dist[start_v]=0;
}
int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int a, b, d;
        cin >> a >> b >> d;
        // 주어지는 간선은 양방향 간선
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }
    cin >> start_v >> end_v;

    // solution
    Init();
    
    // 시작위치 넣어주기
    pq.push({0, start_v}); // {dist, vertex}
    while(!pq.empty()){
        int min_dist=pq.top().first, min_vertex=pq.top().second;
        pq.pop();

        if(min_dist!=dist[min_vertex]) continue;

        for(int j=0; j<(int)graph[min_vertex].size(); ++j){
            int v=graph[min_vertex][j].first, d=graph[min_vertex][j].second;
            int new_dist=dist[min_vertex]+d;
            if(dist[v]>new_dist){
                dist[v]=new_dist;
                pq.push({new_dist, v});
                // minvertex->v로 가는 최단 경로 저장
                path[v]=min_vertex;
            }
        }
    }

    // 경로 저장(도착점부터 경로를 역추적)
    stack<int> route;
    int curr = end_v;
    // curr==-1이라는 건 시작점에 도착했음을 의미
    while (curr != -1) {
        route.push(curr);
        curr = path[curr];
    }

    // output
    cout << dist[end_v] << '\n';
    while (!route.empty()) {
        cout << route.top() << " ";
        route.pop();
    }
    return 0;
}