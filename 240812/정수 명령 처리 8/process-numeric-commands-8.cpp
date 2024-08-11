#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    list<int> s;
    while(n--){
        string command;
        cin >> command;
        if(command=="push_front"){
            int e;
            cin >> e;
            s.push_front(e);
        }
        if(command=="push_back"){
            int e;
            cin >> e;
            s.push_back(e);
        }
        if(command=="pop_front"){
            cout << s.front() << '\n';
            s.pop_front();
        }
        if(command=="pop_back"){
            cout << s.back() << '\n';
            s.pop_back();
        }
        if(command=="size"){
            cout << s.size() <<'\n';
        }
        if(command=="empty"){
            cout << (s.empty()? 1:0) << '\n'; 
        }
        if(command=="front"){
            cout << s.front() << '\n';
        }
        if(command=="back"){
            cout << s.back() << '\n';
        }
    }

    return 0;
}