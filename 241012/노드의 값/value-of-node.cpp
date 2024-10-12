#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 10001;

// 주어지는 정보
int n;
int weight[MAX_N]; // weight[i]: i번 노드에 적혀있는 번호
vector<int> edges[MAX_N];

// 풀이를 위해 선언한 정보
int parent[MAX_N]; // i번 노드의 부모노드
int prefix_weight[MAX_N]; // prefix_weight[i]: i노드를 루트로 하는 서브트리의 가중치 누적합
int num_of_node[MAX_N]; // num_of_node[i]: i번 노드를 루트로 하는 서브트리의 노드 개수
bool visited[MAX_N]={false, };

void DFS(int x){
    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i];
        if(visited[y]) continue;
        visited[y]=true;
        parent[y]=x;
        DFS(y);
    }

    prefix_weight[x]=weight[x];
    num_of_node[x]=1;

    for(int i=0; i<(int)edges[x].size(); ++i){
        int y = edges[x][i];
        // y의 부모가 x라면 dp[x]에 dp[x]+dp[y] 저장
        if(parent[y]==x){
            prefix_weight[x]+=prefix_weight[y];
            num_of_node[x]+=num_of_node[y];
        }
    }
}

int main() {
    // input
    // 정점의 수 n
    cin >> n;
    // 1번부터 n번까지 n 개의 정점에 적혀 있는 정수가 번호 순서대로 공백으로 구분되어 주어집니다.
    for(int i=1; i<=n; ++i){
        cin >> weight[i];
    }
    // 각 줄에 간선 하나씩, 각 간선이 연결하는 두 정점의 번호가 공백으로 구분되어 주어집니다.
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
    int answer=0;
    for(int i=1; i<=n; ++i){
        answer+= abs(num_of_node[i]-prefix_weight[i]);
    }
    cout << answer << '\n';
    return 0;
}