#include <iostream>
#include <vector>

using namespace std;

const int MAX_N=10001;

int n;
vector<int> edges[MAX_N];   
int parent[MAX_N];
int depth[MAX_N];

// depth를 계산
void DFS(int x) {
    for(int i = 0; i < (int)edges[x].size(); ++i){
        int y=edges[x][i];
        depth[y]=depth[x]+1;
        DFS(y);
    }
}

int main() {
    // input
    cin >> n;
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        // 앞의 노드가 뒤의 노드의 부모 노드
        parent[b]=a;
    }
    int a, b; // 공통 조상을 구할 두 노드
    cin >> a >> b;

    // 루트노드 찾기
    int root=0;
    for(int i=1; i<=n; ++i){
        if(parent[i]==0){
            root=i;
            break;
        }
    }
    
    // 각 노드의 깊이 계산
    depth[root]=1;
    DFS(root);

    // depth가 적은 노드의 깊이에 맞춤
    while(depth[a]!=depth[b]){
        if(depth[a]>depth[b]) a=parent[a];
        else b=parent[b];
    }
    
    while(a!=b){
        a=parent[a];
        b=parent[b];
    }

    cout << a << '\n';
    return 0;
}