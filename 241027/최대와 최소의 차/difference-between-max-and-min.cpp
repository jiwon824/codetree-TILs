#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 100'000;

int n, m;
int uf[MAX_N+1];
vector<tuple<int,int,int> > edges; // {type, a, b}

int myFind(int x){
    if(uf[x]==x) return x;
    return uf[x]=myFind(uf[x]);
}
void myUnion(int x, int y){
    x=myFind(x), y=myFind(y);
    if(x==y) return;
    uf[x]=y;
}

int CalcultateCost(){
    // uf 배열 초기화
    for(int i=1; i<=n; ++i){
        uf[i]=i;
    }

    int numOfDanger=0;
    for(auto e : edges){
        int t, a, b;
        tie(t, a, b) = e;
        if(myFind(a)==myFind(b)) continue;
        myUnion(a, b);
        if(t==0) numOfDanger++;
    }

    return pow(numOfDanger, 2);
}

int main() {
    cin >> n >> m;
    // 간선 연결
    for(int i=1; i<=m; ++i){
        int a, b, t;
        cin >> a >> b >> t;
        edges.push_back({t, a, b});
    }
    
    int minCost=1e9, maxCost=0;
    //minCost 계산
    sort(edges.rbegin(), edges.rend());
    minCost = CalcultateCost();
    //maxCost 계산
    sort(edges.begin(), edges.end());
    maxCost = CalcultateCost();

    cout << maxCost-minCost << '\n';
    return 0;
}