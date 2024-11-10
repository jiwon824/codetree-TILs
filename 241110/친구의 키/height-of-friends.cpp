#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100'000;

int n, m;
vector<int> edges[MAX_N+1];
int indegree[MAX_N+1];
queue<int> q;

int main() {
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        indegree[b]++; // a->b: b로 들어오는 간선이 1개 생김
    }

    // 들어오는 간선이 없는 노드에서 시작
    for(int i=1; i<=n; ++i){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        cout << node << " ";
        
        // node에 연결된 노드들 간선 처리
        for(auto e : edges[node]){
            indegree[e]--;
            if(indegree[e]==0) q.push(e);
        }
    }

    return 0;
}