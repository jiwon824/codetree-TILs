#include <iostream>
using namespace std;

const int MAX_N = 100'000;

int n, m;
int uf[MAX_N];

int myFind(int x){
    if(uf[x]==x) return x;
    return uf[x]=myFind(uf[x]);
}

// return: union 연산 성공 여부
bool myUnion(int x, int y){
    x=myFind(x), y=myFind(y);
    if(x==y) return false;

    uf[x]=y;
    return true;
}

int main() {
    cin >> n >> m;
    // uf 배열 초기화
    for(int i=1; i<=n; ++i){
        uf[i]=i;
    }
    
    // m개의 간선 추가
    bool isCycle = false;
    for(int i=1; i<=m; ++i){
        int a, b;
        cin >> a >> b;

        // a, b 연결
        bool result = myUnion(a, b);

        // 사이클이 있는지 검사
        if(!result){
            isCycle=true;
            cout << i << '\n';
            break;
        }
    }
    // m개의 간선이 놓인 후에도 사이클이 없다면, happy를 출력
    if(!isCycle) cout << "happy\n";
    return 0;
}