#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

const int MAX_N =10'000;

int n, m;
char kindOfNode[MAX_N+1];
int uf[MAX_N+1];
vector<tuple<int,int,int> > edges; //{w, a, b}

int myFind(int x){
    if(uf[x]==x) return x;
    return uf[x]=myFind(uf[x]);
}
void myUnion(int x, int y){
    x=myFind(x), y=myFind(y);
    if(x==y) return;
    uf[x]=y;
}

int main() {
    cin >> n >> m;
    // uf 배열 초기화
    for(int i=1; i<=n; ++i){
        uf[i]=i;
    }
    // i번째 노드의 종류(a, b)
    for(int i=1; i<=n; ++i){
        cin >> kindOfNode[i];
    }
    // 양 끝 노드, 가중치
    for(int i=0; i<m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, a, b});
    }
    
    sort(edges.begin(), edges.end());

    int mstWeight=0;
    for(auto e: edges){
        int w, a, b;
        tie(w, a, b)=e;
        // a, b가 연결되어 있지 않고 && a, b가 다른 종류인 경우
        if(myFind(a)!=myFind(b) && kindOfNode[a]!=kindOfNode[b]){
            myUnion(a, b);
            mstWeight+=w;
        }
    }

    // 하나의 트리가 완성되지 않은 경우
    bool canMST = true;
    for(int i=2; i<=n; ++i){
        // 1과 i의 루트가 다른 경우 트리가 여러개 존재
        if(myFind(1)!=myFind(i)){
            canMST=false;
            break;
        }
    }
    if(canMST) cout << mstWeight << '\n';
    else cout << -1 << '\n';
    return 0;
}