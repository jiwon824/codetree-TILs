#include <iostream>
#include <vector>
#include <cstring> //memset()

using namespace std;

const int MAX_N = 100001;

int n, max_dist;
vector<int> edges[MAX_N];
bool visited[MAX_N];
int dist[MAX_N]; // dist[i]: i번 노드에서 출발했을 때 가장 먼 노드까지의 거리

// s에서 x노드까지의 거리 d
void DFS(int s, int x, int d){
    
    if(d>max_dist){
        max_dist=d;
        dist[s]=max_dist;
    }

    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i];
        if(visited[y]) continue;
        visited[y]=true;
        DFS(s, y, d+1);
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
    for(int i=1; i<=n; ++i){
        max_dist=0;
        memset(visited, false, sizeof(visited));
        // i에서 i까지 거리가 0임->이후 i에 연결된 노드를 탐색
        visited[i]=true;
        DFS(i, i, 0);
    }

    // output
    int answer=1e9;
    for(int i=1; i<=n; ++i){
        answer=min(answer, dist[i]);
    }
    cout << answer << '\n';
    return 0;
}