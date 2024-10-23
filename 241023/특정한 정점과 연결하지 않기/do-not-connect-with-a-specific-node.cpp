#include <iostream>
#include <vector>
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

    // 추가로 최대 k개의 간선을 놓아 정점 A가 최대한 많은 정점과 연결되게
    // 하지만 간선을 놓을 때 정점 B와는 연결되지 않도록
    for(int i=1; i<=n; ++i){
        if(myFind(i)==myFind(nodeB)) continue;
        myUnion(nodeA, i);
    }
    cout << size[myFind(nodeA)] << '\n';
    return 0;
}