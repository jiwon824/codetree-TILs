#include <iostream>
using namespace std;

const int MAX_N = 100'000;

int n, m;
int uf[MAX_N+1];

int myFind(int x){
    if(uf[x]==x) return x;
    return uf[x]=myFind(uf[x]);
}

void myUnion(int x, int y){
    x=myFind(x), y=myFind(y);
    uf[x]=y;
}

int main() {
    cin >> n >> m;
    // uf배열 초기화
    for(int i=1; i<=n; ++i){
        uf[i]=i;
    }
    // m개의 간선 연결
    while(m--){
        int a, b;
        cin >> a >> b;
        myUnion(a, b);
    }

    // 연결되지 않은 간선 연결
    int answer=0;
    for(int i=2; i<=n; ++i){
        if(myFind(1)!=myFind(i)){
            answer++;
            myUnion(1, i);
        }
    }
    cout << answer << '\n';
    return 0;
}