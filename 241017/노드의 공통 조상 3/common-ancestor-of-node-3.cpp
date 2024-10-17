#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 100'001;
const int MAX_H = 17; // ceil(log2(MAX_N))하면 편함

int n, q;
vector<int> edges[MAX_N];
bool visited[MAX_N]={false, };

int depth[MAX_N];
int parent[MAX_H][MAX_N];

void dfs(int x){
    for(int y : edges[x]){
        if(visited[y]) continue;

        visited[y]=true;
        depth[y]=depth[x]+1;
        parent[0][y]=x;
        dfs(y);
    }
}

int lca(int a, int b){
    if(depth[b]>depth[a]) return lca(b, a);

    // 1. 깊이 맞추기
    for(int h=MAX_H-1; h>=0; --h){
        if(depth[a]-depth[b] >= (1<<h)) a= parent[h][a];
    }

    if(a==b) return a;

    // 2. 공통 조상 찾기
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

    // dfs로 parent 초기 설정 후, 점화식으로 배열 채우기
    depth[1]=1;
    visited[1]=true;
    dfs(1);
    for(int h=1; h<MAX_H; ++h){
        for(int i=1; i<=n; ++i){
            parent[h][i]=parent[h-1][parent[h-1][i]];
        }
    }

    cin >> q;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        int answer = lca(a, b);
        answer = lca(answer, c);
        cout << answer << '\n';
    }
    return 0;
}