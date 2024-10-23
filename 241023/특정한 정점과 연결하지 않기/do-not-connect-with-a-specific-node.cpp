#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N =100'000;

int n, m;
int uf[MAX_N+1];
int size[MAX_N+1];
int nodeA, nodeB, k;

int myFind(int x){
    if(uf[x]==x) return x;
    return uf[x]=myFind(uf[x]);
}

void myUnion(int x, int y){
    x=myFind(x), y=myFind(y);
    if(x==y) return;
    uf[x]=y;
    size[y]+=size[x];
}

int main() {
    cin >> n >> m;
    
    // 배열 초기화
    for(int i=1; i<=n; ++i){
        uf[i]=i;
        size[i]=1;
    }

    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        myUnion(a, b);
    }
    cin >> nodeA >> nodeB >> k;

    // B와 겹쳐지지 않는 노드들의 size를 components에 push
    // 하지만 간선을 놓을 때 정점 B와는 연결되지 않도록
    vector<int> components;
    int visited[MAX_N]={false, };
    for(int i=1; i<=n; ++i){
        int root_i = myFind(i);

        // b랑 연결된 노드는 a 노드랑 연결하면 안 됨.
        if(root_i==myFind(nodeB)) continue;
        // 이미 방문한 노드거나 a노드에 연결된 노드라면 추가하지 않음
        if(visited[root_i] || root_i==myFind(nodeA)) continue;

        visited[root_i]=true;
        components.push_back(size[root_i]);
    }

    // size[root]가 큰 순서대로 정렬
    sort(components.begin(), components.end(), greater<>());

    int answer=size[myFind(nodeA)];
    for(int i=0; i<k; ++i){
        answer+=components[i];
    }
    // 놓을 수 있는 간선 중 크기가 큰 것을 
    // 최대 k개의 간선을 놓아 정점 A가 최대한 많은 정점과 연결되게
    cout << answer << '\n';
    return 0;
}