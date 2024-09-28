#include <iostream>
#include <vector>
#include <cstring> // memset
using namespace std;

const int MAX_N = 10001;

int n;
vector<pair<int, int> > edges[MAX_N];
int dist[MAX_N][MAX_N];
bool visited[MAX_N] = {false, };

void DFS(int s, int x){
    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i].first, d=edges[x][i].second;
        if(visited[y]) continue;
        visited[y]=true;
        dist[s][y]=dist[s][x]+d;

        DFS(s, y);
    }
}

int main() {
    // input
    cin >> n;
    for(int i=1; i<n; ++i){
        int a, b, d;
        cin >> a >> b >> d;
        edges[a].push_back({b, d});
        edges[b].push_back({a, d});
    }

    // solution
    for(int i=1; i<=n; ++i){
        memset(visited, false, sizeof(visited));

        visited[i]=true;
        DFS(i, i);
    }
    
    // output
    int answer = 0;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            answer=max(answer, dist[i][j]);
        }
    }
    cout << answer << '\n';
    return 0;
}