#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX_N = 50001;

int n, d, far_node;
int max_edge, min_date=1e9; // for find answer(max_edge, min_date)
vector<pair<int,int> > edges[MAX_N];  // {vertex, weight}
bool visited[MAX_N] ={false, };

void DFS(int x, long long sum_of_dist, int num_of_edges){
    // 걸리는 날은 총 거리를 하루에 갈 수 있는 거리로 나눠서 올림 해야 함
    int require_days = ceil(sum_of_dist/(double)d);

    // 날짜가 더 많이 걸려도 간선은 많은 게 좋음
    if(num_of_edges>max_edge){
        far_node = x; // 가장 먼 노드의 번호
        max_edge = max(max_edge, num_of_edges); // 간선의 개수
        min_date = require_days; // 걸리는 날짜
    }
    else if(num_of_edges==max_edge && min_date>require_days){
        // 간선의 수가 같으면 날짜가 적은 쪽을 선택
        far_node = x;
        min_date=require_days;
    }

    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i].first, len=edges[x][i].second;

        if(visited[y]) continue;
        visited[y]=true;
        DFS(y, sum_of_dist+len, num_of_edges+1);
    }

}

int main() {
    // input
    cin >> n >> d;
    for(int i=1; i<n; ++i){
        int a, b, len;
        cin >> a >> b >> len;

        edges[a].push_back({b, len});
        edges[b].push_back({a, len});
    }

    // solution
    // 1. 가장 많은 간선을 지나기 위해서는 가장 먼 두 노드를 선택해야 함(트리의 지름)
    visited[1]=true;
    DFS(1, 0, 0); // 1번 노드(아무 노드나 가능)에서 시작해 가장 먼 노드 찾기
    
    // 2. visited 재사용을 위한 초기화
    memset(visited, false, sizeof(visited));
    max_edge=0, min_date =1e9;
    
    // 3. 가장 먼 노드에서 간선을 가장 많이 선택하면서, 날짜가 적게 걸리는 경로 선택
    visited[far_node]=true;
    DFS(far_node, 0, 0); // node, dist, num_of_edges

    cout << min_date << '\n';
    return 0;
}