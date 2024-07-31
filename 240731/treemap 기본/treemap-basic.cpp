#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin>> n;

    map<int, int> m;
    for(int i=0; i<n; ++i){
        string command;
        cin >> command;
        if(command=="add"){
            int k, v;
            cin >> k >> v;
            m[k]=v;
        }
        if(command=="remove"){
            int k;
            cin >> k;
            m.erase(k);
        }
        if(command=="find"){
            int k;
            cin >> k;
            if(m.find(k)==m.end()) cout << "None\n";
            else cout << m[k] << '\n';
        }
        if(command=="print_list"){
            if(m.empty()) cout << "None\n";
            else{
                for(auto it=m.begin(); it!=m.end(); ++it){
                    cout << it->second << " ";
                }
                cout << '\n';
            }
        }
    }
    
    return 0;
}