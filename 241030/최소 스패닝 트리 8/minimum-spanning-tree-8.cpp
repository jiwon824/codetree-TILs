#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 500;

int n, m;
vector<pair<int,int> > edges[MAX_N]; // edges[i]: i번 노드에 연결된 {노드, 가중치}
priority_queue<pair<int, int>, vector<pair<int,int> >, greater<>> pq; // {weight, vertex}
int dist[MAX_N+1]; // dist[x]: 현재까지 만들어진 MST와 노드 x를 연결하기 위해 필요한 최소 비용
bool visited[MAX_N+1]={false, };

void InitDist(){
    for(int i=1; i<=n; ++i){
        dist[i]=1e9;
    }
    // 시작점(아무 정점이나 선택 가능) 0으로 초기화
    dist[1]=0;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }

    // dist 배열을 초기화(INF), 출발지(1)의 값 0
    InitDist();
    
    // 거리 dist 내의 값들 중 최솟값 선택(우선순위 큐를 사용)
        // 다익스트라와 마찬가지로 프림 알고리즘에서도
        // 최솟값을 골라주는 과정을 여러 번 반복하기 때문
    int answer=0;
    // 시작점을 queue에 넣어줌 {weight, vertex}
    pq.push({0, 1});
    while(!pq.empty()){
        // 가장 거리가 가까운 정점의 정보
        int min_dist=pq.top().first, min_vertex=pq.top().second;
        pq.pop();
        
        // 이미 방문한 노드라면 무시
        if (visited[min_vertex]) continue;

        // 최소값 방문 표시
        visited[min_vertex]=true;
        answer += min_dist;

        // graph[min_vertex]에 연결된 정점들 거리 갱신
        for(auto e: edges[min_vertex]){
            int vertex = e.first, weight = e.second;

            if(!visited[vertex] && dist[vertex]>weight){
                dist[vertex] = weight;
                pq.push({weight, vertex});
            }
        }
    }

    cout << answer << '\n';
    return 0;
}