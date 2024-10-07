#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100001;

int n, r, q;
vector<int> edges[MAX_N];
int parent[MAX_N];
int dp[MAX_N]; // dp[i]: (i번 노드를 루트로 하는 서브트리)에 속한 노드 수
bool visited[MAX_N]={false, };

void DFS(int x){
    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i];
        if(visited[y]) continue;

        visited[y]=true;
        parent[y]=x;
        DFS(y);
    }

    dp[x]=1;
    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i];
        if(parent[y]!=x) continue;
        dp[x]+=dp[y];
    }
}

int main() {
    // input
    cin >> n >> r >> q;
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        // 간선 연결
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    visited[r]= true;
    DFS(r);

    // q개의 연산
    while(q--){
        //u를 루트 노드로 하는 서브트리에 속한 정점의 수
        int u;
        cin >> u;
        cout << dp[u] << '\n';
    }

    return 0;
}