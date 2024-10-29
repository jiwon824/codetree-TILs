#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

const int MAX_N = 100'000;

int n, m;
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
    for(int i=0; i<m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, a, b});
    }

    // uf 배열 초기화
    for(int i=1; i<=n; ++i){
        uf[i]=i;
    }
    
    sort(edges.begin(), edges.end());

    int answer =0;
    for(auto e : edges){
        int a, b, w;
        tie(w, a, b)=e;
        if(myFind(a)!=myFind(b)) myUnion(a, b);
        else answer+=w;
    }
    
    cout << answer << '\n';
    return 0;
}