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
        s.insert({x,y});
    }

    for(int i=0; i<m; ++i){
        int k;
        cin >> k;
        auto it = s.lower_bound({k,-1});
        if(it!=s.end()) {
            cout << (*it).first << " " << (*it).second <<'\n';
            s.erase(*it);
        }
        else cout << "-1 -1\n";
    }

    return 0;
}