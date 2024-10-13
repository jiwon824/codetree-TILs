#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 30001;

// 주어지는 것
int n;
int weight[MAX_N]; // weight[i]: i의 weight
vector<int> edges[MAX_N];

// 문제를 풀기 위해 필요한 것
int parent[MAX_N]; // parent[i]: i의 부모노드
bool visited[MAX_N]={false, };
// 30,000 * 1,000 = 30,000,000 이므로 int로 가능. INT_MAX=2,147,483,647
// 노드 i를 지나는 가장 긴 경로합은 노드 i의 왼쪽 자식 L, 오른쪽 자식 R일 때
// "L을 루트로 하는 서브트리에서 L를 지나는 가장 긴 경로의 경로합
// + R을 루트로 하는 서브트리에서 R을 지나는 가장 긴 경로합"
int max_length[MAX_N];

void DFS(int x){
    for(int i=0; i<(int)edges[x].size(); ++i){
        int y =edges[x][i];
        if(visited[y])continue;
        visited[y]=true;
        parent[y]=x;
        DFS(y);
    }

    // x를 지나는 가장 긴 경로의 합
    // x를 지나기 때문에 일단 x의 가중치로 초기화
    max_length[x]=weight[x];
    for(int i=0; i<(int)edges[x].size(); ++i){
        int y =edges[x][i];
        if(parent[y]==x && max_length[y]>0){
            max_length[x]+=max_length[y];
        }
    }

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