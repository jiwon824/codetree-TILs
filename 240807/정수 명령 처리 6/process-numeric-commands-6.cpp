#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> pq;
    while(n--){
        string command;
        cin >> command;
        if(command=="push"){
            int a;
            cin >> a;
            pq.push(a);
        }
        else if(command=="pop"){
            cout << pq.top() <<'\n';
            pq.pop();
        }
        else if(command=="size"){
            cout << pq.size() << '\n';
        }
        else if(command=="empty"){
            cout << pq.empty() << '\n';
        }
        else if(command=="top"){
            cout << pq.top() <<'\n';
        }
    }
    
    return 0;
}