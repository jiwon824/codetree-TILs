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

void dfs(int x){
    for(pair<int,int> child : edges[x]){
        int y = child.first;
        if(visited[y]) continue;

        visited[y]=true;
        depth[y]=depth[x]+1;
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

int sumWeightsBetweenNodes(int target, int x){
    int answer=0;
    while(target!=x){
        int px=parent[0][x];
        // x랑 px가 연결된 간선을 찾아서 가중치를 answer에 더해줌
        for(pair<int,int> e : edges[x]){
            if(e.first==px){
                answer+=e.second;
                break;
            }
        }
        // x 한 칸 올리기
        x=px;
    }
    return answer;
}

int main() {
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

        int answer=sumWeightsBetweenNodes(lca, a)+sumWeightsBetweenNodes(lca, b);
        cout << answer << '\n';
    }
    return 0;
}