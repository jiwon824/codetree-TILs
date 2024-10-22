#include <iostream>
using namespace std;

const int MAX_N = 100'000;

int n, m;
int uf[MAX_N+1];

int myFind(int x){
    if(uf[x]==x) return x;
    return uf[x]=myFind(uf[x]);
}

bool myUnion(int x, int y){
    x=myFind(x), y=myFind(y);
    if(x==y) return false;
    uf[x]=y;
    return true;
}

int main() {
    cin >> n >> m;
    // uf배열 초기화
    for(int i=1; i<=n; ++i){
        uf[i]=i;
    }

    // m개의 간선 연결
    int answer=0;
    while(m--){
        int a, b;
        cin >> a >> b;
        // union이 실패라면 사이클이 생긴 것-> 끊어야 하는 간선
        if(!myUnion(a, b)) answer++;
    }

    // 그래프의 개수를 세서 연결해야 할 노드의 수를 구함
    for(int i=1; i<=n; ++i){
        // 루트 노드의 개수
        if(myFind(i)==i) answer++;
    }
    
    // 간선의수= 노드-1
    cout << answer-1 << '\n';
    return 0;
}