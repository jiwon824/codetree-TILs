#include <iostream>
using namespace std;

const int MAX_N = 100'000;

int n, m;
int uf[MAX_N];

int my_find(int x){
    if(uf[x]==x) return x;
    return uf[x]=my_find(uf[x]);
}

void my_union(int x, int y){
    x=my_find(x), y=my_find(y);
    uf[x]=y;
}

int main() {
    cin >> n >> m;
    // uf 배열 초기화
    for(int i=1; i<=n; ++i){
        uf[i]=i;
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

            int num_of_node=1; // 연결된 노드가 적어도 자기자신 1개
            for(int i=1; i<=n; ++i){
                if(a==i) continue;
                if(my_find(a)==my_find(i)) num_of_node++;
            }
            cout << num_of_node << '\n';
        }
    }

    return 0;
}