#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 100'000;
const int MAX_H = ceil(log2(MAX_N));

int n, k, q;
vector<int> edges[MAX_N];
bool visited[MAX_N]={false, };
bool isColored[MAX_N]={false, };

int depth[MAX_N];
int numOfColoredNode[MAX_N];// 루트부터 i번째 노드까지 색칠된 노드의 수
int parent[MAX_H][MAX_N];

void dfs(int x){
    numOfColoredNode[x]= isColored[x] ? numOfColoredNode[x]+1 : numOfColoredNode[x];

    for(int y:edges[x]){
        if(visited[y]) continue;
        visited[y]=true;
        parent[0][y]=x;
        depth[y]=depth[x]+1;
        numOfColoredNode[y]+=numOfColoredNode[x];
        dfs(y);
    }
}

int get_lca(int a, int b){
    if(depth[b]>depth[a]) return get_lca(b, a);

    // 1. 깊이 맞추기
    for(int h=MAX_H-1; h>=0; --h){
        if(depth[a]-depth[b] >= (1<<h)) a=parent[h][a];
    }
    if(a==b) return a;

    // 2. lca 찾기
    for(int h=MAX_H-1; h>=0; --h){
        if(parent[h][a]!=parent[h][b]){
            a=parent[h][a];
            b=parent[h][b];
        }
    }
    return parent[0][a];
}

int main() {
    //input
    cin >> n;
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    cin >> k;
    for(int i=0; i<k; ++i){
        int num;
        cin >> num;
        isColored[num]=true;
    }

    //parent 배열 채우기 루트는 1
    depth[1]=1;
    visited[1]=true;
    dfs(1);
    for(int h=1; h<MAX_H; ++h){
        for(int i=1; i<=n; ++i){
            parent[h][i]=parent[h-1][parent[h-1][i]];
        }
    }

    // q개의 연산
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        int lca = get_lca(a, b);
        int answer =numOfColoredNode[a]+numOfColoredNode[b]-2*numOfColoredNode[lca];
        if(isColored[lca]) answer++;
        cout << answer << '\n';
    }

    return 0;
}