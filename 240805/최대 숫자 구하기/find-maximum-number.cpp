#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // 1부터 m까지의 숫자가 적혀있는 공이 하나씩 놓여있다.
    set<int> s;
    for(int i=1; i<=m; ++i){
        s.insert(i);
    }

    // 주어지는 숫자가 적혀 있는 공을 제거 후 남아있는 최대 공번호
    for(int i=0; i<n; ++i){
        int delNum;
        cin >> delNum;
        s.erase(delNum);

        cout << *s.rbegin() << '\n';
    }
    return 0;
}