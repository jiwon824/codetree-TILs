#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map <string, int> m;

    for(int i=0; i<n; ++i){
        string str;
        cin >> str;
        m[str]++;
    }

    cout<<fixed;
    cout.precision(4);
    for(auto it=m.begin(); it!=m.end(); ++it){
        cout << it->first << " " << (it->second)/(float)n*100 <<'\n';
    }
    
    return 0;
}