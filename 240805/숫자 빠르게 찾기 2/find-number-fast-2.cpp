#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // 주어지는 모든 숫자는 서로 다름
    set<int> s;
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        s.insert(num);
    }

    for(int i=0; i<m; ++i){
        int num;
        cin >> num;
        auto it = s.lower_bound(num);
        if(it==s.end()) cout << "-1\n";
        else cout << *it << '\n';
    }

    return 0;
}