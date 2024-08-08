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
        if(x!=0){
            pq.push(x);
        }
        else{
            if(pq.empty()){
                cout << 0 <<'\n';
            }
            else{
                cout << pq.top() <<'\n';
                pq.pop();
            }
        }
    }
    return 0;
}