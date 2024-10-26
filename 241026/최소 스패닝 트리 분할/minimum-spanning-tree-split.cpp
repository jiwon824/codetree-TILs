#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

const int MAX_N = 10'000;

int n, m;
int uf[MAX_N+1];
vector<tuple<int,int,int> > edges;

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
    for(int i=1; i<=n; ++i){
        uf[i]=i;
    }
    for(int i=1; i<=m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, a, b});
    }

    sort(edges.begin(), edges.end());

    int weightSum = 0, maxWeight=0;
    for(auto e : edges){
        int w, a, b;
        tie(w, a, b) = e;
        if(myFind(a)==myFind(b)) continue;
        myUnion(a, b);
        weightSum+=w;
        maxWeight=max(maxWeight, w);
    }

    cout << weightSum-maxWeight << '\n';
    return 0;
}