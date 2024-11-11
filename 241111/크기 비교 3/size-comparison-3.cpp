#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 32'000;

int n, m;

vector<int> edges[MAX_N+1];
int indegree[MAX_N+1];
priority_queue<int> pq;


int main() {
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        indegree[b]++;
    }

    for(int i=1; i<=n; ++i){
        // 작은 순으로 정렬해야 하므로 -를 붙여서 push
        if(indegree[i]==0) pq.push(-i);
    }
    
    while(!pq.empty()){
        int node = -pq.top();
        pq.pop();

        cout << node << " ";
        
        for(auto e : edges[node]){
            indegree[e]--;
            if(indegree[e]==0) pq.push(-e);
        }
    }

    return 0;
}