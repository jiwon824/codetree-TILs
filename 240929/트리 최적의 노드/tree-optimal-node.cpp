#include <iostream>
#include <vector>
#include <cstring> //memset()

using namespace std;

const int MAX_N = 100001;

int n, max_dist, max_node;
vector<int> edges[MAX_N];
bool visited[MAX_N];

void DFS(int x, int d){
    if(d>max_dist){
        max_dist=d;
        max_node=x;
    }

    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i];
        if(visited[y]) continue;
        visited[y]=true;
        DFS(y, d+1);
    }
}

int main() {
    // input
    cin >> n;
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        // a, b 노드 연결(모든 간선의 길이는 1)
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    // solution
    // 가장 먼 노드(a)에서 가장 먼 노드(b)의 길이를 구하면
    // a, b의 중간에 있는 노드가 가장 먼 노드까지의 거리가 최소인 노드
    DFS(1, 0);

    max_dist=0;
    memset(visited, false, sizeof(visited));
    DFS(max_node, 0);

    // output
    // 정중앙에 있는 노드에서 가장 먼 노드까지의 길이
    cout << (max_dist+1)/2 << '\n';

    return 0;
}