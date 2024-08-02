#include <iostream>
#include <set>

using namespace std;

set<int> s;

int main() {
    int n;
    cin >> n;
    while(n--){
        string command;
        cin >> command;
        if(command=="add"){
            int num;
            cin >> num;
            s.insert(num);
        }
        if(command=="remove"){
            int num;
            cin >> num;
            s.erase(num);
        }
        if(command=="find"){
            int num;
            cin >> num;
            if(s.find(num)!=s.end()) cout << "true\n";
            else cout << "false\n";
        }
        if(command=="lower_bound"){
            int num;
            cin >> num;
            if(s.lower_bound(num)!=s.end()) cout << *s.lower_bound(num) << '\n';
            else cout << "None\n";
        }
        if(command=="upper_bound"){
            int num;
            cin >> num;
            if(s.upper_bound(num)!=s.end()) cout << *s.upper_bound(num) << '\n';
            else cout << "None\n";
        }
        if(command=="largest"){
            if(s.empty()) cout << "None\n";
            else cout << *s.rbegin() << '\n';
        }
        if(command=="smallest"){
            if(s.empty()) cout << "None\n";
            else cout << *s.begin() <<'\n';
        }

    }
    return 0;
}