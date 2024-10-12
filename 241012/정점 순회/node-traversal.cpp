#include <iostream>
#include <vector>

using namespace std;

const int MAX_N =100001;

int n, s, d, answer;
vector<int> edges[MAX_N];
bool visited[MAX_N]={false, };
int dist[MAX_N]; // dist[i]: 리프노드에서 i번째 노드까지의 거리

void DFS(int x){
    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i];
        if(visited[y]) continue;

        visited[y]=true;
        DFS(y);

        dist[x]=max(dist[x], dist[y]+1);
    }
}
int main() {
    cin >> n >> s >> d;
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        // 간선 연결
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    visited[s]=true;
    DFS(s);

    for(int i=1; i<=n; ++i){
        if(i==s) continue;
        if(dist[i]>=d){
            answer+=2; // 해당 노드를 왔다갔다 해야하니까
        }
    }
    
    cout << answer << '\n';
    return 0;
}