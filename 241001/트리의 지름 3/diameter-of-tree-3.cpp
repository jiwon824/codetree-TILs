#include <iostream>
#include <vector>
#include <cstring> // memset
#include <algorithm> //sort
using namespace std;

const int MAX_N = 100001;

int n, far_node, max_dist;
vector<pair<int,int> > edges[MAX_N];
bool visited[MAX_N]={false, };


void DFS(int x, int dist, vector<int> &saveDist){
    // 가장 먼 노드 찾기
    if(dist>max_dist){
        max_dist=dist;
        far_node=x;
    }

    // dist를 벡터에 저장
    saveDist.push_back(dist);

    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i].first, d=edges[x][i].second;
        if(visited[y]) continue;
        visited[y]=true;
        DFS(y, dist+d, saveDist);
    }
}

int main() {
    // input
    cin >> n;
    for(int i=1; i<n; ++i){
        int a, b, d;
        cin >> a >> b >> d;

        // 간선 연결
        edges[a].push_back({b, d});
        edges[b].push_back({a, d});
    }

    // 가장 먼 노드 찾기
    vector<int> tmp;
    visited[1]=true;
    DFS(1, 0, tmp);

    // 가장 먼 노드로부터의 거리 계산
    memset(visited, false, sizeof(visited));
    max_dist=0;
    vector<int> dist1;
    visited[far_node]=true;
    DFS(far_node, 0, dist1);
    
    memset(visited, false, sizeof(visited));
    max_dist=0;
    vector<int> dist2;
    visited[far_node]=true;
    DFS(far_node, 0, dist2);
    
    sort(dist1.begin(), dist1.end());
    sort(dist2.begin(), dist2.end());

    // size-1은 제일 먼 노드와의 거리
    int size = (int)dist1.size();
    cout << max(dist1[size-2], dist2[size-2]) <<'\n';
    return 0;
}