#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100001;

int n;
vector<int> edges[MAX_N];
bool visited[MAX_N]={false, };
int dp[MAX_N][2]; // dp[i][j], j=0 물건을 놓지 않는 경우, j=1 물건을 놓는 경우

void DFS(int x){
    // 기본적으로 놓지 않으면 0개, 놓으면 1개
    dp[x][0]=0, dp[x][1]=1;

    for(int y : edges[x]){
        if(visited[y]) continue;
        visited[y]=true;
        DFS(y);
        
        // x에 안 놓으려면 y에는 놓아야 함
        dp[x][0]+=dp[y][1];
        dp[x][1]+=min(dp[y][0], dp[y][1]);
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

    // solution
    visited[1]=true;
    DFS(1);

    // output
    cout << min(dp[1][0], dp[1][1]) << '\n';
    return 0;
}