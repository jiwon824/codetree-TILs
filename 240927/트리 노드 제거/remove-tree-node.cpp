#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 51;

int n, root, e_node, answer; // 노드의 개수, 루트 노드, 지울 노드, 리프노드의 개수
vector<int> edges[MAX_N];
bool visited[MAX_N]={false, };

// x가 삭제되었을 때 리프 노드 개수 cnt
void DFS(int x){
    bool isLeaf = true;

    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i];
        if(visited[y]) continue;

        visited[y]=true;
        DFS(y);
        isLeaf=false;
    }

    if(isLeaf) answer++;
}

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        int parent;
        cin >> parent;
        if(parent==-1) {
            root=i;
            continue;
        }

        edges[parent].push_back(i);
    }

    cin >> e_node;
    visited[e_node]=true;

    if(root!=e_node) DFS(root);
    cout << answer << '\n';
    return 0;
}