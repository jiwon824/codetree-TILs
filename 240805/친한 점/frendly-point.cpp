#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<pair<int,int> > s;
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        s.insert({x, y});
    }

    // 친한 점 찾기 x < x' 혹은 (x=x', y ≤ y')을 만족
    for(int i=0; i<m; ++i){
        int x, y;
        cin >> x >> y;
        auto it = s.lower_bound({x,y});
        if(it==s.end()) cout << "-1 -1\n";
        else cout << (*it).first << " " << (*it).second << '\n';
    }
    return 0;
}