#include <iostream>
#include <queue>

using namespace std;

// 절댓값이 가장 작은 값을 출력해야함
// 절댓값이 가장 작은 값이 여러개일 때는, 그 중 가장 작은 수를 출력
bool cmp(int a, int b){
    if(abs(a)==abs(b)) return a>b;
    return abs(a)>abs(b);
}

int main() {
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, decltype(&cmp)> pq(cmp);
    while(n--){
        int x;
        cin >> x;
        if(x!=0) pq.push(x);
        else{
            if(pq.empty()) cout << 0 <<'\n';
            else {
                cout << pq.top() <<'\n';
                pq.pop();
            }
        }

    }
    return 0;
}