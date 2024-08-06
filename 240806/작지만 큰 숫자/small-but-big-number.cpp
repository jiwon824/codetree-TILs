#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> s;
    
    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        s.insert(num);
    }

    for(int i = 0; i < m; ++i) {
        int num;
        cin >> num;

        auto it = s.upper_bound(num);
        if(it == s.begin()) cout << "-1\n";
        else {
            --it;
            cout << *it << '\n';
            s.erase(it);
        }
    }

    return 0;
}