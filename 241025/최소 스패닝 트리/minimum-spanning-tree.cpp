#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

const int MAX_N = 10'000;

int n, m;
int uf[MAX_N+1];
vector<tuple<int,int,int> > edges; //{w, a, b}: 가중치 순으로 정렬을 위함


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
    for(int i=0; i<m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, a, b});
    }
    // 가중치를 오름차순으로 정렬(낮음->높음)
    sort(edges.begin(), edges.end());

    int mstWeight=0;
    for(auto e : edges){
        int w, a, b;
        tie(w, a, b)=e;
        if(myFind(a)==myFind(b)) continue;
        mstWeight+=w;
        myUnion(a, b);
    }

    cout << mstWeight << '\n';
    return 0;
}