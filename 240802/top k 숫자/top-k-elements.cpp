#include <iostream>
#include <set>

using namespace std;

set<int> s;

int main() {
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        s.insert(num);
    }

    set<int>::reverse_iterator it;
    int cnt=0;
    for(it=s.rbegin(); it!=s.rend(); ++it){
        cout << *it << " ";
        cnt++;
        if(cnt>=k) break;
    }

    return 0;
}