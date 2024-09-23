#include <iostream>
#include <vector>

using namespace std;

const int MAX_N=100001;

int n;

vector<int> edges[MAX_N];
bool visited[MAX_N]={false, };
int parent[MAX_N];

// DFS 방식으로 트리를 순회
void Traversal(int x){
    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i];
        if(!visited[y]){
            visited[y]=true;
            // y의 부모는 x
            parent[y]=x;
            
            Traversal(y);
        }
    }
}

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        // 간선 저장
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    //solution
    visited[1]=true;
    Traversal(1);

    // output
    for(int i=2; i<=n; ++i){
        cout << parent[i] << '\n';
    }
    return 0;
}