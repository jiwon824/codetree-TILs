#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 100'001;
const int MAX_H = ceil(log2(MAX_N));

int n, q;
vector<pair<int,int> > edges[MAX_N];
bool visited[MAX_N];

int depth[MAX_N];
int parent[MAX_H][MAX_N];
long long dist[MAX_N]; // 루트에서 i번 노드까지의 가중치의 합

void dfs(int x){
    for(pair<int,int> child : edges[x]){
        int y = child.first;
        if(visited[y]) continue;

        visited[y]=true;
        depth[y]=depth[x]+1;
        dist[y] += dist[x]+child.second;
        parent[0][y]=x;
        dfs(y);
    }
}

int getLca(int a, int b){
    if(depth[b]>depth[a]) return getLca(b, a);

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
    // input
    cin >> n;
    for(int i=1; i<n; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
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
        int lca = getLca(a, b);
        cout << dist[a]+dist[b]-2*dist[lca] << '\n';
    }
    return 0;
}