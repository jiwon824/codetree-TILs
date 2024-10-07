#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100001;

int n;
vector<int> edges[MAX_N];
int weight[MAX_N]; // weight[i]:  i번 노드를 루트로 하는 서브 트리에 있는 노드에 적힌 수들의 합. i번 노드에 적힌 값으로 초기화
int parent[MAX_N]; // parent[i]: i번 노드의 부모
bool visited[MAX_N] = {false, };

void DFS(int x){
    for(int i=0; i<edges[x].size(); ++i){
        int y=edges[x][i];
        if(visited[y]) continue;
        visited[y] = true;
        DFS(y);
    }

    for(int i=0; i<edges[x].size(); ++i){
        int y=edges[x][i];
        if(parent[y]==x && weight[y]>0) weight[x]+=weight[y];
    }

}
int main() {
    // input
    cin >> n;
    for(int i=2; i<=n; ++i){
        int t, a, p;
        cin >> t >> a >> p;
        if(t==0) a = -a;

        // 트리 탐색을 위한 간선 연결
        edges[i].push_back(p);
        edges[p].push_back(i);

        weight[i]=a;
        parent[i]=p;
    }
    
    visited[1]=true;
    DFS(1);

    cout << weight[1] << '\n';

    return 0;
}