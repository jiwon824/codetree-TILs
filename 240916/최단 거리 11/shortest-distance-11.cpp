#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N =1001;

int n, m;
int s_v, e_v;
vector<pair<int,int>> graph[MAX_N];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
int dist[MAX_N];

// 로그 찍기용 함수
void PrintGraph(){
    for(int i=1; i<=n; ++i){
        for(int j=0; j<graph[i].size(); ++j){
            cout << "{" << graph[i][j].first << ", " << graph[i][j].second << "}, ";
        }
        cout << '\n';
    }
}

void Init(){
    for(int i=1; i<=n; ++i){
        dist[i]=1e9;
    }
    //시작 지점
    dist[e_v]=0;
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int a, b, d;
        cin >> a >> b >> d;
        // 양방향 그래프
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }
    cin >> s_v >> e_v;

    // solution
    Init();
    for(int i =1; i<=n; ++i){
        sort(graph[i].begin(), graph[i].end());
    }

    //  도착 지점에서 시작
    pq.push({0, e_v}); // {dist, vertex}
    while(!pq.empty()){
        int curr_d=pq.top().first, curr_v=pq.top().second;
        pq.pop();

        if(curr_d!=dist[curr_v]) continue;
        
        // 인접노드 최단거리 갱신
        for(int j=0; j<(int)graph[curr_v].size(); ++j){
            int next_v=graph[curr_v][j].first, curr_to_next=graph[curr_v][j].second;
            int new_dist=dist[curr_v]+curr_to_next;// curr_v가 현재 가장 최단거리노드

            if(dist[next_v]>new_dist){
                dist[next_v]=new_dist;
                pq.push({new_dist, next_v});
            }
        }
    }

    // 경로 저장
    vector<int> route;
    route.push_back(s_v);
    for(int x=s_v; x!=e_v; ){
        for(int i=0; i<(int)graph[x].size(); i++) {
            int v= graph[x][i].first, d=graph[x][i].second;
            if(dist[v]+d == dist[x]) {
                x=v;
                break;
            }
        }
        route.push_back(x);
    }

    // output
    cout << dist[s_v] << '\n';
    for(int i =0; i<(int)route.size(); ++i){
        cout << route[i] << " ";
    }
    return 0;
}