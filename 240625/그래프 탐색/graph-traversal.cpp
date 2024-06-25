#include <iostream>

using namespace std;

int n, m, answer;
int graph[1001][1001];
int visited[1001];

void DFS(int v){
    for(int curr_v=1; curr_v<=n; ++curr_v){
        if(graph[v][curr_v] && visited[curr_v]==0){
            visited[curr_v]=1;
            answer++;
            DFS(curr_v);
        }
    }
}
int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    DFS(1);

    cout << answer-1 <<'\n';
    return 0;
}