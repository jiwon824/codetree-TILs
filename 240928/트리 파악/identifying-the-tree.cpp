#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100001;

int n;
vector<int> edges[MAX_N];
vector<int> leaf_node;
vector<int> depth;
bool visited[MAX_N] = {false, };

// DFS로 모든 노드의 depth를 저장
void DFS (int x, int d){
    // x번 노드의 깊이 d
    depth[x]=d;

    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i];
        if(visited[y]) continue;
        visited[y]=true;
        DFS(y, d+1);
    }

}

int main() {
    //input
    cin >> n;
    depth.resize(n);
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        // 간선 연결(a->b)
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    // 2번 노드부터(1은 루트 노드니까) size()==1은 부모노드랑만 이어져 있다는 뜻
    // 즉 자식이 없는 노드=리프 노드라는 의미가 된다.
    for(int i=2; i<=n; ++i){
        if((int)edges[i].size()==1) leaf_node.push_back(i);
    }

    // 모든 노드의 깊이 계산 및 저장
    DFS(1, 0); // DFS(node_num, depth)

    int sum=0;
    for(int i=0; i<(int)leaf_node.size(); ++i){
        sum+=depth[leaf_node[i]];
    }

    if(sum%2==0) cout << 0 <<'\n';
    else cout << 1 << '\n';
    return 0;
}