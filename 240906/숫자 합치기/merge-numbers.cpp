#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
priority_queue<int> pq;

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        pq.push(-num);
    }

    int answer=0;
    while(n>1){
        int lhs = -pq.top();
        pq.pop();
        int rhs = -pq.top();
        pq.pop();

        int sum = lhs+rhs;
        answer+= sum;
        pq.push(-sum);
        n--;
    }
    cout << answer << '\n';
    return 0;
}