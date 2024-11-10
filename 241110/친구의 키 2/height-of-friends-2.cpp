#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100'000;

int n, m;
vector<int> edges[MAX_N+1];
int indegree[MAX_N+1]; // indegree[i]: i번 노드에 들어오는 간선의 개수
queue<int> q;

// in-degree 방법을 사용하여 위상정렬을 시도해본 뒤,
// queue에 들어간 노드의 수가 그래프에서 주어진 노드의 수와 일치하는지를 확인
int main() {
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        indegree[b]++;
    }

    // queue에 시작 노드 추가
    for(int i=1; i<=n; ++i){
        if(indegree[i]==0) q.push(i);
    }
    
    int numOfNode=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        numOfNode++;
        for(auto e: edges[node]){
            indegree[e]--;
            if(indegree[e]==0) q.push(e);
        }
    }

    if(numOfNode==n) cout << "Consistent\n";
    else cout << "Inconsistent\n";

    return 0;
}