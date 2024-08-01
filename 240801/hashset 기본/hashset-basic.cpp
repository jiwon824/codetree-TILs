#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> us;
    for(int i=0; i<n; ++i){
        string command;
        int x;
        cin >> command >> x;
        if(command=="add"){
            us.insert(x);
        }
        if(command=="remove"){
            us.erase(x);
        }
        if(command=="find"){
            if(us.find(x)!=us.end()) cout << "true\n";
            else cout << "false\n";
        }
    }
    
    return 0;
}