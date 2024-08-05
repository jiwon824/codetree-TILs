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
        bool isExist = false;
        for(auto it=s.begin(); it!=s.end(); ++it){
            if(*it>=num){
                isExist=true;
                cout << *it << '\n';
                break;
            }
        }
        if(!isExist) cout << "-1\n";
    }

    return 0;
}