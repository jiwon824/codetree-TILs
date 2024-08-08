#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    priority_queue<int> pq;
    // n개의 숫자
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        pq.push(num);
    }

    // 2개 이상의 숫자가 남아 있는 한 계속 반복
    while(pq.size()>=2){
        // 가장 큰 숫자 2개를 뽑아 제거하고 두 숫자의 차이에 해당하는 숫자를 다시 집어넣는 것
        int num1=pq.top();
        pq.pop();
        int num2=pq.top();
        pq.pop();
        if(num1!=num2) pq.push(num1-num2);
    }
    
    if(pq.empty()) cout << -1 <<'\n';
    else cout << pq.top() << '\n';
    return 0;
}