#include <iostream>
#include <vector>
using namespace std;

const int MAX_N=10001;

int m, root;
vector<int> parents[MAX_N];
vector<int> edges[MAX_N];
bool nodeExist[MAX_N]={false, };
bool visited[MAX_N]={false, };

// 들어오는 간선이 하나도 없는 루트 노드가 정확히 한 개 존재
bool isSingleRoot(){
    int cnt=0;
    for(int i=1; i<MAX_N; ++i){
        // node가 존재하는데, 부모가 없는 경우 cnt 증가
        if(nodeExist[i] && parents[i].empty()) {
            root=i;
            cnt++;
        }

        // 1보다 커지면 root가 여러 개이므로 더 검사할 필요가 없음
        if(cnt>1) break;
    }

    // cnt==1이면 root가 1개라는 의미 true, 아니면 false
    return cnt==1;  
}

void DFS(int x){
    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i];
        if(visited[y]) continue;
        visited[y]=true;
        DFS(y);
    }
}


bool isTree(){
    // [조건1] 루트 노드가 1개인지 검사
    if(!isSingleRoot()) return false;
    
    //[조건2] 검사
    for(int i=1; i<MAX_N; ++i){
        // [조건2] 들어오는 간선이 2개라는 의미(부모가 2개)이므로 0 리턴
        if((int)parents[i].size()>1) return false;
    }

    // [조건3] 루트 노드에서 간선을 사용해서, 자신을 제외한 모든 노드에 도달할 수 있으며, 이러한 경로는 유일합니다.
    visited[root]=true; //루트노드 방문 체크
    DFS(root);
    for(int i=1; i<MAX_N; ++i){
        // 존재하는 노드인데, 방문하지 못했다면 도달하지 못한 노드가 있다는 의미
        if(nodeExist[i] && !visited[i]) return false;
    }

    return true;
}

int main() {
    // input
    cin >> m;
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        // a b 는 노드 a에서 노드 b로 가는 간선이 존재한다는 의미
        edges[a].push_back(b);
        
        // 노드 존재 여부 체크
        nodeExist[a]=true;
        nodeExist[b]=true;
        
        // a에서 노드 b로 가는 간선 == b의 부모가 a임을 의미
        parents[b].push_back(a);
    }

    // 트리 여부 판별
    if(isTree()) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}