#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_N = 100'000;

int n, m;
vector<int> edges[MAX_N+1];
bool visited[MAX_N+1]={false, };
stack<int> reversed_order;

void dfs(int x){
    for(auto e: edges[x]){
        if(visited[e]) continue;
        visited[e]=true;
        dfs(e);
    }

    reversed_order.push(x);
}
// 키가 큰 사람부터 내림차순으로
// (a, b) 형태로 주어지며, 이는 a번 친구가 b번 친구보다 키가 크다는 것을 의미
// 친구들이 서있는 순서를 앞에서부터 차례대로 구해주는 프로그램
int main() {
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }

    for(int i=1; i<=n; ++i){
        if(visited[i]) continue;
        visited[i]=true;
        dfs(i);
    }

    while(!reversed_order.empty()){
        cout << reversed_order.top() << " ";
        reversed_order.pop();
    }
    return 0;
}