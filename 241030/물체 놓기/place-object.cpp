#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 300;

int n;
int dist[MAX_N+1];
int connectCost[MAX_N+1][MAX_N+1]; // i번 정점에서 j번 정점을 연결하는 데 드는 비용
bool visited[MAX_N]={false, };

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> dist[i];
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> connectCost[i][j];
        }
    }
    
    int answer=0;
    for(int i=0; i<n; ++i){
        // v개의 정점 중 방문하지 않았으면서 dist값이 가장 작은 정점
        int min_idx = -1;
        for(int j=0; j<n; ++j){
            if(visited[j]) continue;
            if(min_idx==-1 || dist[min_idx]>dist[j]) min_idx=j;
        }

        // 방문 체크
        visited[min_idx]=true;
        answer+=dist[min_idx];

        for(int j=0; j<n; ++j){
            if (visited[j]) continue;
            dist[j]=min(dist[j], connectCost[min_idx][j]);
        }
    }

    cout << answer << '\n';
    return 0;
}