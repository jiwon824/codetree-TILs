#include <iostream>
#include <list>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    list<char> l;
    for(int i=0; i<n; ++i){
        char e;
        cin >> e;
        l.push_back(e);
    }

    // 가리키는 위치는 처음에 모든 빵의 맨 마지막에 위치
    auto it = l.end();

    while(m--){
        char command;
        cin >> command;
        if(command=='L'){
            if(it!=l.begin()) it--;
        }
        else if(command=='R'){
            if(it!=l.end()) it++;
        }
        else if(command=='D'){
            l.erase(it);
        }
        else if(command=='P'){
            // 가리키는 위치에 
            char e;
            cin >> e;
            l.insert(it, e);
        }
    }
    //레시피 이행하고 난 뒤의 식빵들의 상태를 공백없이 순서대로 출력
    for(it = l.begin(); it != l.end(); it++) { 
        cout << *it;
    } 
    return 0;
}