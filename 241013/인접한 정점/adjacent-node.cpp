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
    bool child_selected = false;

    for(int i=0; i<(int)edges[x].size(); ++i){
        int y = edges[x][i];
        if(parent[y]==x){
            // x를 선택하는 경우=자식을 선택하지 않은 경우
            dp[x][1]+=dp[y][0];

            // 자식을 선택할 것인지 말 것인지 고려
            // 자식을 선택한 게 자식을 선택하지 않은 것보다 크다면 부모선택x-자식 선택o
            if(dp[y][1] > dp[y][0]) {
                dp[x][0] += dp[y][1];
                child_selected = true;
            }
            else dp[x][0]+= dp[y][0];
        }
    }

    // 자식을 하나도 선택하지 않았다면(=모든 자식을 dp[x][0]+= dp[y][0]한 경우),
    // 가장 이득이 큰 자식 하나를 강제로 선택

    // dp[x][0]에 모든 자식을 선택하지 않는 경우(dp[y][0])를 더했기 때문에
    // 이득이 큰 자식을 선택하려면, 선택하는 자식에 대해 아래 연산을 수행해야 한다.
    // dp[x][0]=dp[x][0]-dp[y][0]+dp[y][1]

    // -dp[y][0]+dp[y][1]=max_diff가 되고, dp[x][0]과 합쳐주는 연산을 취하므로
    // dp[x][0]+=max_diff
    if(!child_selected){
        int max_diff = 0;
        for(int i=0; i<(int)edges[x].size(); ++i) {
            int y = edges[x][i];
            if(parent[y] == x) {
                max_diff = max(max_diff, dp[y][1] - dp[y][0]);
            }
        }
        dp[x][0]+= max_diff;
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