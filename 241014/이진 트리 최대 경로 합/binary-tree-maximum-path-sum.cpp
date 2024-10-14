#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 30001;

// 주어지는 것
int n;
int weight[MAX_N]; // weight[i]: i의 weight
vector<int> edges[MAX_N];

bool visited[MAX_N]={false, };
int dp[MAX_N];
int max_length[MAX_N];

void DFS(int x){
    vector<int> children;

    for(int i=0; i<(int)edges[x].size(); ++i){
        int y = edges[x][i];
        if(visited[y]) continue;
        
        visited[y]=true;
        children.push_back(y);
        DFS(y);
    }

    int num_of_children = (int)children.size();
    int left_child = (num_of_children>=1) ? children[0] : 0;
    int right_child = (num_of_children==2) ? children[1] : 0;

    dp[x]= weight[x] + max({0, dp[left_child], dp[right_child]});

    max_length[x] = weight[x]+max(0, dp[left_child])+max(0, dp[right_child]);
}

int main() {
    // input
    // 이진 트리의 정점 수 N이 주어집니다.
    cin >> n;
    // 총 N-1개의 줄에 걸쳐 간선으로 연결된 두 개의 노드가 공백을 두고 차례대로 주어집니다.
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        // 간선 연결
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    // 총 N개의 줄에 걸쳐 각 노드들이 가지는 값이 주어집니다.
    for(int i=1; i<=n; ++i){
        cin >> weight[i];
    }

    // solution
    // 트리의 루트는 1번
    visited[1]=true;
    DFS(1);

    // output
    int answer = -30000000;
    for(int i=1; i<=n; ++i){
        answer=max(answer, max_length[i]);
    }
    cout << answer << '\n';
    return 0;
}