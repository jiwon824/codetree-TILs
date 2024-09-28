#include <iostream>
#include <vector>
#include <cstring> // memset
using namespace std;

const int MAX_N = 10001;

int n, max_dist, maxPoint;
vector<pair<int, int> > edges[MAX_N];
bool visited[MAX_N] = {false, };

void DFS(int x, int dist){
    if(max_dist<dist){
        max_dist=dist;
        maxPoint=x;
    }
    
    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i].first, d=edges[x][i].second;
        if(visited[y]) continue;
        visited[y]=true;
        DFS(y, dist+d);
    }
}

int main() {
    // input
    cin >> n;
    for(int i=1; i<n; ++i){
        int a, b, d;
        cin >> a >> b >> d;
        edges[a].push_back({b, d});
        edges[b].push_back({a, d});
    }

    // solution
    // 1에서 가장 먼 노드 구하기(far_node)
    visited[1]=true;
    DFS(1, 0);
    
    // far_node에서 가장 먼 노드를 구하면 트리의 지름이 나온다.
    memset(visited, false, sizeof(visited));
    max_dist = 0;
    visited[maxPoint]=true;
    DFS(maxPoint, 0);
    
    // output
    cout << max_dist << '\n';
    return 0;
}