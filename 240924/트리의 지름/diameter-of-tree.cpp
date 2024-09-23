#include <iostream>
#include <cstring> // memset
#include <vector>

using namespace std;

const int MAX_N = 100001;

int n;
vector<pair<int,int> > edges[MAX_N];
bool visited[MAX_N]={false, };
int maxPoint=-1, maxLen=-1;

// DFS 방식을 이용하여
// 주어진 점에서 가장 먼 지점을 찾는 함수
void FindFurthestPoint(int point, int length){
    if(visited[point]) return;
    
    // 방문 체크
    visited[point]=true;

    // 가장 멀리 있는 점 갱신
    if(maxLen<length){
        maxLen=length;
        maxPoint=point;
    }

    // point와 연결된 노드들
    for(int i=0; i<(int)edges[point].size(); ++i){
        int vertex = edges[point][i].first;
        int weight = edges[point][i].second;

        FindFurthestPoint(vertex, length+weight);
    }

}

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        int a, b, d;
        cin >> a >> b >> d;
        // 간선 연결
        edges[a].push_back({b, d});
        edges[b].push_back({a, d});
    }

    // a---v---b가 있다고 했을 때 v에서 가장 먼 지점을 구하고
    // 거기서 가장 먼 지점을 구하면 지름이 된다.
    FindFurthestPoint(1, 0);
    memset(visited, false, sizeof(visited));

    FindFurthestPoint(maxPoint, 0);

    cout << maxLen << '\n';
    return 0;
}