#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> pq;

    // n개의 숫자
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        pq.push(num);
    }

    // 가장 큰 숫자를 골라 1씩 빼는 작업을 m번 반복
    for(int i=0; i<m; ++i){
        int maxNum = pq.top();
        pq.pop();
        pq.push(maxNum-1);
    }

    // 남아있는 숫자들 중 최댓값을 출력
    cout << pq.top() << '\n';
    return 0;
}