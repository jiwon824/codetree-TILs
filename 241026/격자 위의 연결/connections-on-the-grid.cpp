#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

const int MAX_N = 300;
const int MAX_M = 300;

int n, m;
int uf[MAX_N *MAX_M +1];
vector<tuple<int,int,int> > edges; // {w, a, b}

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
    for(int i=1; i<=n*m; ++i){
        uf[i]=i;
    }
    // 가로 간선 입력
    for(int i=0; i<n; ++i){
        for(int j=0; j<m-1; ++j){
            int a=i*m+j, b=i*m+(j+1), w;
            cin >> w;
            edges.push_back({w, a, b});
        }
    }
    // 세로 간선 입력
    for(int i=0; i<n-1; ++i){
        for(int j=0; j<m; ++j){
            int a=i*m+j, b=(i+1)*m+j, w;
            cin >> w;
            edges.push_back({w, a, b});
        }
    }

    // 가중치가 적은 것을 먼저 이어야 하므로 sort
    sort(edges.begin(), edges.end());

    int mstSum=0;
    for(auto e : edges){
        int w, a, b;
        tie(w, a, b) = e;
        if(myFind(a)==myFind(b)) continue;
        myUnion(a, b);
        mstSum+=w;
    }
    cout << mstSum << '\n';
    return 0;
}