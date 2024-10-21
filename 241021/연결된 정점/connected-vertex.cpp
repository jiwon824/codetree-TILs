#include <iostream>
using namespace std;

const int MAX_N = 100'000;

int n, m;
int uf[MAX_N];
int size[MAX_N];

int my_find(int x){
    if(uf[x]==x) return x;
    return uf[x]=my_find(uf[x]);
}

void my_union(int x, int y){
    x=my_find(x), y=my_find(y);
    if(x!=y){
        if(size[x]<size[y]) swap(x, y); // 항상 더 큰 트리에 작은 트리를 붙이기
        uf[y] = x;
        size[x] += size[y];
    }
}

int main() {
    cin >> n >> m;
    // uf 배열 초기화
    for(int i=1; i<=n; ++i){
        uf[i]=i;
        size[i]=1;
    }    
    
    while(m--){
        char command;
        cin >> command;
        
        if(command=='x'){
            int a, b;
            cin >> a >> b;
            my_union(a, b);
        }
        else if(command=='y'){
            int a;
            cin >> a;
            cout << size[my_find(a)] << '\n';
        }
    }

    return 0;
}