#include <iostream>
using namespace std;

const int MAX_N =100'000;

int n;
int uf[MAX_N+1];
int size[MAX_N+1];    

int myFind(int x){
    if(uf[x]==x) return x;
    return uf[x]=myFind(uf[x]);
}

void myUnion(int x, int y){
    x=myFind(x), y=myFind(y);
    size[y]+=size[x];
    uf[x]=y;
}

int main() {
    cin >> n;
    
    for(int i=1; i<=n+1; ++i){
        uf[i]=i;
        size[i]=1;
    }

    for(int i=1; i<=n; ++i){
        int a, b;
        cin >> a >> b;
        myUnion(a, b);
        cout << size[myFind(a)] << '\n';
    }
    return 0;
}