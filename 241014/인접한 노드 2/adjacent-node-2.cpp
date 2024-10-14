#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 10001;

int n;
vector<int> edges[MAX_N];
bool visited[MAX_N]={false, };
int num[MAX_N]; // num[i]: i번 노드에 적힌 값

int dp[MAX_N][2]; // dp[i][j]: j=0 선택x 경우, j=1 선택o 경우
vector<int> picked;

void DFS(int x){
    dp[x][1]=num[x];

    for(int i=0; i<(int)edges[x].size(); ++i){
        int y =edges[x][i];
        if(visited[y])continue;

        visited[y]=true;
        DFS(y);

        // x번 노드가 포함된 경우 y번 노드는 포함될 수 없습니다.
        // x번 노드가 포함되지 않은 경우 y번 노드는 포함될 수도,
        // 포함되지 않을 수도 있습니다.
        dp[x][1] += dp[y][0];
        dp[x][0] += max(dp[y][0], dp[y][1]);
    }

    // x를 선택하는 게 나은 선택이라면 x 저장
    if(dp[x][1]>dp[x][0]) {
        picked.push_back(x);
    }
}

int main() {
    //input
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> num[i];
    }
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
    sort(picked.begin(), picked.end());

    // output
    cout << max(dp[1][0], dp[1][1]) << '\n';
    for(auto e: picked){
        cout << e << " ";
    }
    return 0;
}