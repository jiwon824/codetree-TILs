#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 100'001;
const int MAX_H = ceil(log2(MAX_N));

int n, q;
vector<int> edges[MAX_N];
bool visited[MAX_N]={false, };

int depth[MAX_N];
int parent[MAX_H][MAX_N];

// parent 초기조건
void dfs(int x){
    for(int y : edges[x]){
        if(visited[y]) continue;

        visited[y]=true;
        parent[0][y]=x;
        depth[y]=depth[x]+1;
        dfs(y);
    }
}

int find_lca(int a, int b){
    if(depth[b]>depth[a]) return find_lca(b, a);

    // 1. 두 노드의 깊이 맞추기
    for(int h=MAX_H-1; h>=0; --h){
        if(depth[a]-depth[b] >= (1<<h)) a=parent[h][a];
    }

    if(a==b) return a;

    for(int h=MAX_H-1; h>=0; --h){
        if(parent[h][a]!=parent[h][b]){
            a=parent[h][a];
            b=parent[h][b];
        }
    }

    return parent[0][a];
}

int main() {
    cin >> n;
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    // 루트는 1
    depth[1]=1;
    visited[1]=true;
    dfs(1);
    for(int h=1; h<MAX_H; ++h){
        for(int i=1; i<=n; ++i){
            parent[h][i]=parent[h-1][parent[h-1][i]];
        }
    }

    // q번의 연산
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        int lca = find_lca(a, b);
        cout << (depth[a]-depth[lca])+(depth[b]-depth[lca])+1 << '\n';
    }
    return 0;
}