#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 10001;

int n;
int weight[MAX_N];
vector<int> edges[MAX_N];
bool visited[MAX_N]={false, };

int parent[MAX_N];
int dp[MAX_N][2]; // dp[i][0]: i를 선택하지 않았을 때 최대값, dp[i][1]: i를 선택했을 때 최대값


void DFS(int x){
    for(int i=0; i<(int)edges[x].size(); ++i){
        int y = edges[x][i];
        if(visited[y]) continue;
        visited[y]=true;
        parent[y]=x;
        DFS(y);
    }

    dp[x][0]=0, dp[x][1]=weight[x];

    for(int i=0; i<(int)edges[x].size(); ++i){
        int y = edges[x][i];
        if(parent[y]==x){
            // x를 선택하지 않는 경우=자식을 선택하는 경우
            dp[x][0]+=dp[y][1];
            // x를 선택하는 경우=자식을 선택하지 않은 경우
            dp[x][1]+=dp[y][0];
        }
    }
}
int main() {
    // input
    // 정점의 수 n이 주어집니다.
    cin >> n;
    // 1번 정점부터 n번 정점까지 각 정점에 적힌 수가 번호 순서대로 공백으로 구분되어 주어집니다.
    for(int i=1; i<=n; ++i){
        cin >> weight[i];
    }
    // n-1 개의 줄에 걸쳐, 트리의 각 간선이 연결하는 두 정점의 번호가 공백으로 구분되어 주어집니다.
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
    cout << max(dp[1][0], dp[1][1]) << '\n';
    return 0;
}