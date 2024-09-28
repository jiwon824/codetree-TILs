#include <iostream>
#include <vector>
#include <cstring> // memset

using namespace std;

const int MAX_N = 100001;

int n, dfs_dist;
vector<int> edges[MAX_N];
vector<int> leaf_node;
bool visited[MAX_N] = {false, };


void DFS (int x, int e, int dist){
    // 종료 조건
    if(x==e){
        dfs_dist = dist;
        return;
    }

    // 재귀 호출(
    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i];
        if(visited[y]) continue;

        visited[y]=true;
        DFS(y, e, dist+1);
    }

}

int main() {
    //input
    cin >> n;
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        // 간선 연결(a->b)
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    // 2번 노드부터(1은 루트 노드니까) size()==1은 부모노드랑만 이어져 있다는 뜻
    // 즉 자식이 없는 노드=리프 노드라는 의미가 된다.
    for(int i=2; i<=n; ++i){
        if((int)edges[i].size()==1) leaf_node.push_back(i);
    }

    // 루트에서 시작해서 각 리프노드까지의 거리
    int sum=0; // 모든 (루드-리프) 거리의 합
    for(int i=0; i<(int)leaf_node.size(); ++i){
        int target=leaf_node[i];
        dfs_dist=0;
        memset(visited, false, sizeof(visited));
        
        DFS(1, target, 0);

        sum+=dfs_dist;
    }

    if(sum%2==0) cout << 0 <<'\n';
    else cout << 1 << '\n';
    return 0;
}