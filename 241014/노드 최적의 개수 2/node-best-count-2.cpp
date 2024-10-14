#include <iostream>
#include <vector>

using namespace std;

const int MAX_N =100001;

int n, m;
vector<int> edges[MAX_N];
bool visited[MAX_N]={false, };
bool isPlaced[MAX_N]={false, };
int dp[MAX_N][2];

void DFS(int x){
    if(!isPlaced[x]) dp[x][0]=0, dp[x][1]=1;

    for(int y : edges[x]){
        if(visited[y]) continue;
        visited[y]=true;
        DFS(y);

        // y에 놓여있으면 x에는 놓든 말든 상관없음
        // 아니라면 둘 중 하나에는 놓아야 한다
        dp[x][0]+=dp[y][1];
        dp[x][1]+=min(dp[y][0], dp[y][1]);
    }
    
}

int main() {
    // input
    cin >> n >> m;
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for(int i=0; i<m; ++i){
        int node;
        cin >> node;
        isPlaced[node]=true;
    }

    // solution
    visited[1]=true;
    DFS(1);

    // output
    cout << min(dp[1][0], dp[1][1]) << '\n';
    return 0;
}