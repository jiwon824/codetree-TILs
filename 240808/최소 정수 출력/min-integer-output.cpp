#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    priority_queue<int> pq;

    while(n--){
        int x;
        cin >> x;
        if(x==0){
            if(pq.empty()) cout << 0 <<'\n';
            else{
                cout << -pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(-x);
        }
    }
    return 0;
}