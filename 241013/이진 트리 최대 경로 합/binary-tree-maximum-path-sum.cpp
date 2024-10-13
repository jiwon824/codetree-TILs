#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 30001;

// 주어지는 것
int n;
int weight[MAX_N]; // weight[i]: i의 weight
vector<int> edges[MAX_N];

// 노드 i를 지나는 가장 긴 경로합은 노드 i의 왼쪽 자식 L, 오른쪽 자식 R일 때
// "L을 루트로 하는 서브트리에서 L를 지나는 가장 긴 경로의 경로합
// + R을 루트로 하는 서브트리에서 R을 지나는 가장 긴 경로합"
int max_length[MAX_N];
int answer = -30000000;

void DFS(int x){
    // 자식이 없는 경우
    if(edges[x].empty()) {
        max_length[x]=weight[x];
        answer=max(answer, max_length[x]);
        return;
    }

    int num_of_child = (int)edges[x].size();
    int left_sum = 0, right_sum = 0;
    if(num_of_child >= 1){
        int left_child = edges[x][0];
        DFS(left_child);
        left_sum = max(0, max_length[left_child]);
    }
    if(num_of_child==2){
        int right_child = edges[x][1];
        DFS(right_child);
        right_sum = max(0, max_length[right_child]);
    }

    max_length[x]=max(max_length[x], weight[x]+max({0, left_sum, right_sum}));

    answer = max(answer, weight[x] + left_sum + right_sum);
}

int main() {
    // input
    // 이진 트리의 정점 수 N이 주어집니다.
    cin >> n;
    // 총 N-1개의 줄에 걸쳐 간선으로 연결된 두 개의 노드가 공백을 두고 차례대로 주어집니다.
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        // 간선 연결
        edges[a].push_back(b);
    }
    // 총 N개의 줄에 걸쳐 각 노드들이 가지는 값이 주어집니다.
    for(int i=1; i<=n; ++i){
        cin >> weight[i];
    }

    // solution
    // 트리의 루트는 1번
    DFS(1);

    // output
    cout << answer << '\n';
    return 0;
}