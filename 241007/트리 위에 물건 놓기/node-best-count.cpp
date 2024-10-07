#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100001;

int n;
vector<int> edges[MAX_N];
int parent[MAX_N];
bool visited[MAX_N] ={false, };
int dp[MAX_N][2]; // dp[i][j]: j=0 i번 노드에 물건을 올리지 않은 경우, j=1 물건을 올린 경우 물건의 총 개수

void DFS(int x){
    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i];
        if(visited[y]) continue;

        visited[y]=true;
        parent[y]=x; // y의 부모는 x
        DFS(y);
    }

    // 기본값: x번 노드에 물건을 올리면 1 올리지 않으면 0개
    dp[x][0]=0;
    dp[x][1]=1;

    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i];
        if(parent[y]!=x) continue;

        // 적어도 하나 색칠 -> x가 색칠되면 y는 색칠 되든 말든 상관 없다.
        //              -> x가 색칠되지 않으면 y는 무조건 색칠되어 있어야 한다.
        dp[x][1]+=min(dp[y][0], dp[y][1]);
        dp[x][0]+=dp[y][1];
    }
}


int main() {
    // input
    cin >> n;
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        // 간선 연결
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    visited[1]=true;
    DFS(1);

    cout << min(dp[1][0], dp[1][1]) << '\n';
    return 0;
}