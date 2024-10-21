#include <iostream>
using namespace std;

const int MAX_N = 100'000;

int n, m;
int uf[MAX_N+1];

int my_find(int x){
    if(uf[x]==x) return x;
    int root_node = my_find(uf[x]);
    uf[x]=root_node;
    return root_node;
}

void my_union(int x, int y){
    x = my_find(x), y = my_find(y);
    uf[x]=y;
}

int main() {
    cin >> n >> m;

    // uf 배열의 초기값은 자기 자신. uf는 그룹 번호를 의미
    for(int i=1; i<=n; ++i){
        uf[i]=i;
    }

    // m번의 연산
    while(m--){
        int command, a, b;
        cin >> command >> a >> b;
        if(command==0){
            // 0 a b : a가 포함된 집합과 b가 포함된 집합을 합칩니다.
            // 만약 이미 같은 집합에 속한다면, 아무것도 하지 않습니다.
            my_union(a, b);
        }
        else if(command==1){
            // 1 a b : a와 b가 같은 집합 안에 있다면 1을, 그렇지 않다면 0을 출력
            if(my_find(a)==my_find(b)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
    return 0;
}