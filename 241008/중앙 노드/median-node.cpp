#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100001;


int n, r, c;// num of node, root, central
vector<int> edges[MAX_N];
int parent[MAX_N];// parent[i]: i번 노드의 부모 노드 번호
bool visited[MAX_N]={false, };

int dp_depth[MAX_N]; // i번 노드의 깊이(level1부터 시작)
int dp_treeSize[MAX_N];// i번 노드를 루트로 하는 서브트리의 크기

// x번 노드의 정보를 출력
void PrintLog(int x){
    cout << "["<< x<< "번 노드 정보]\n";
    cout << "부모 노드: " << parent[x] << '\n';
    cout << "연결된 노드의 수" << (int)edges[x].size() << '\n';
}
void DFS(int x, int depth){
    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i];
        if(visited[y]) continue;
        visited[y]=true;
        parent[y]=x;
        c=y; // 자식이 2개 이상인 노드가 없는 경우 리프노드가 중앙노드가 됨
        DFS(y, depth+1);
    }

    dp_depth[x]=depth;
    dp_treeSize[x]=1;
    
    //PrintLog(x);

    // return 되면서 갱신되기 때문에 결국 처음으로 자식노드가 2개 이상인 노드로 갱신됨
    // x에 연결된 노드가 부모를 제외하고(-1) 2이상이면 c
    if(parent[x]!=0 && (int)edges[x].size()-1>=2) c=x;
    // 루트 노드이면서 자식이 2개 이상인 경우
    else if(parent[x]==0 && (int)edges[x].size()>=2) c=x;

    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i];
        if(parent[y]==x){
            dp_treeSize[x]+=dp_treeSize[y];
        }
    }

}

int main() {
    // input
    cin >> n >> r;
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    // solution
    visited[r]=true;
    DFS(r, 1);

    int max_val=0, min_val=1e9;
    for(int i=0; i<(int)edges[c].size(); ++i){
        int y=edges[c][i];
        // c의 부모가 y라면
        if(parent[c]==y){
            min_val=min(min_val, dp_depth[y]);
            max_val=max(max_val, dp_depth[y]);
            continue;
        }

        min_val=min(min_val, dp_treeSize[y]);
        max_val=max(max_val, dp_treeSize[y]);
    }
    
    // cout
    cout << max_val-min_val << '\n';
    return 0;
}