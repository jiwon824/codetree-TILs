#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> pq;
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        pq.push(-num);
        
        if(pq.size()<3) cout << -1 <<'\n';
        else{
            int a = -pq.top();
            pq.pop();
            int b = -pq.top();
            pq.pop();
            int c = -pq.top();
            pq.pop();

            cout << a*b*c <<'\n';

            pq.push(-a);
            pq.push(-b);
            pq.push(-c);
        }
    }
    return 0;
}