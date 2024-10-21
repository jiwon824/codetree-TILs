#include <iostream>
using namespace std;

const int MAX_N = 100'000;

int n;
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
    cin >> n;
    // uf 배열 초기화
    for(int i=1; i<=n; ++i){
        uf[i]=i;
    }

    for(int i=1; i<=n-2; ++i){
        int a, b;
        cin >> a >> b;
        my_union(a, b);
    }
    
    bool isFind = false;
    for(int i=1; i<=n; ++i){
        int nodeNum=0;
        for(int j=i+1; j<=n; ++j){
            if(my_find(i)!=my_find(j)){
                isFind=true;
                nodeNum=j;
                break;
            }
        }

        if(isFind){
            cout << i << " " << nodeNum << '\n';
            break;
        }
    }

    return 0;
}