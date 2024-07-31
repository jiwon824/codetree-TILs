#include <iostream>
#include<map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> num;
    for(int i=0; i<n; ++i){
        int e;
        cin >> e;
        num.insert({e, i+1});
    }

    for(auto it=num.begin(); it!=num.end(); ++it){
        cout << it->first << " " << it->second <<'\n';
    }
    return 0;
}