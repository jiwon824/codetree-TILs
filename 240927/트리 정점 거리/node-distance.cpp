#include <iostream>
#include <vector>
#include <cstring> //memset

using namespace std;

const int MAX_N = 1001;

int n, m, answer;
vector<pair<int, int>> edges[MAX_N]; //edges[i][j] = {i의 자식노드, 길이}
bool visited[MAX_N]={false, };

void DFS(int x, int e, int dist){
    // 종료조건
    if(x==e){
        answer=dist;
        return;
    }

    // 재귀 호출
    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i].first, d=edges[x][i].second;
        if(visited[y]) continue;
        visited[y]=true;
        DFS(y, e, dist+d);
    }
}

int main() {
    // input
    cin >> n >> m;
    for(int i=1; i<n; ++i){
        int a, b, d;
        cin >> a >> b >> d;
        edges[a].push_back({b, d});
        edges[b].push_back({a, d});
    }

    // 거리를 구하고자 하는 정점쌍의 개수 m
    while(m--){
        int a, b;
        cin >> a >> b;
        memset(visited, false, sizeof(visited));

        visited[a]=true;
        DFS(a, b, 0);
        cout << answer << '\n';
    }

    return 0;
}