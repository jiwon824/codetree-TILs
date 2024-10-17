#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 50'001;
const int MAX_H = 16; // 2^16=65,536 이므로 50,000개의 노드를 커버할 수 있다

int n, q;
vector<int> edges[MAX_N];
bool visited[MAX_N]={false, };

int depth[MAX_N];
int parent[MAX_H][MAX_N];

// DFS를 통해 parent 초기 조건을 채움
void DFS(int x){
    for(int y : edges[x]){
        if(visited[y]) continue;

        visited[y]=true;
        parent[0][y]=x; // y에서 1(2^0)번 올라간 노드는 x(=x가 부모라는 의미)
        depth[y]=depth[x]+1;
        DFS(y);
    }
}

int LCA(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);

    // 1. 두 노드의 깊이를 같게 만들기
    for(int h=MAX_H; h>=0; --h){
        if(depth[a]-depth[b] >= (1<<h)) a=parent[h][a];
    }
    
    if(a == b) return a;

    // 2. 두 노드의 공통 조상 찾기(두 노드가 일치하기 직전까지 올라감)
    for(int h=MAX_H; h>=0; --h){
        if(parent[h][a] != parent[h][b]){
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
    
    // parent 초기조건 채우기(루트는 1번)
    depth[1]=1;
    visited[1]=true;
    DFS(1);

    // 점화식을 이용하여 parent 값 구하기
    for(int h = 1; h < MAX_H; h++) {
        for(int i = 1; i <= n; i++) {
            parent[h][i] = parent[h-1][parent[h-1][i]];
        }
    }

    // q번 연산
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b)  << '\n';
    }

    return 0;
}