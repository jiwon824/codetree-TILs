#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100'000;
const int MAX_K = 100'000;

int n, m, k;
int uf[MAX_N];
int visitOrder[MAX_K];

int my_find(int x){
    if(uf[x]==x) return x;
    return uf[x]=my_find(uf[x]);
} 

void my_union(int x, int y){
    x=my_find(x), y=my_find(y);
    uf[x]=y;
}

bool CanGo(){
    for(int i=1; i<k; ++i){
        int a=visitOrder[i-1], b=visitOrder[i];
        if(my_find(a)!=my_find(b)) return false;
    }
    return true;
}

int main() {
    cin >> n >> m >> k;

    // uf 배열 초기화
    for(int i=1; i<=n; ++i){
        uf[i]=i;
    }

    // m개의 간선 연결
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        my_union(a, b);
    }
    for(int i=0; i<k; ++i){
        cin >> visitOrder[i];
    }

    if(CanGo()) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}