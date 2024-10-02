#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int k;
vector<int> inorder_result;

// BFS방식을 이용하여 트리를 복구하는 함수
void BFS(int root_idx){
    // queue에는 idx를 넣고, cout << inorder_result[q.front()]; 이런 식으로
    queue<int> q;
    q.push(root_idx);
    int level=1;

    while(!q.empty()){
        int q_size = q.size();
        for(int i=0; i<q_size; ++i){
            int idx=q.front();
            q.pop();
            cout << inorder_result[idx] << " ";
            
            if(level<k){
                int gap= pow(2, k-level-1);
                int left= idx-gap, right=idx+gap;

                if(left>=0) q.push(left);
                if(right<(int)inorder_result.size()) q.push(right);
            }
        }

        level++;
        cout << '\n';
    }
}

int main() {
    // input
    cin >> k;

    int size=pow(2, k)-1;
    for(int i=0; i<size; ++i){
        int num;
        cin >> num;
        inorder_result.push_back(num);
    }

    int r=(size-1)/2;
    BFS(r);

    return 0;
}

/* [해설코드]

#include <iostream>

#define MAX_N 1024

using namespace std;

// 변수 선언
int k, n;
int a[MAX_N + 1];
int tree_num[MAX_N + 1];
int cnt = 1;

// 중위 순회를 진행하여 각 트리의 위치에 맞는 번호를 채워 넣습니다.
void InOrder(int x) {
    // n보다 큰 노드는 없습니다. 빠져나갑니다.
    if(x > n)
        return;

    InOrder(x * 2);
    tree_num[x] = a[cnt++];
    InOrder(x * 2 + 1);
}

int main() {
    // 입력:
    cin >> k;

    // 2^i은 (1 << i)로 쉽계 계산이 가능합니다.
    n = (1 << k) - 1;

    // a라는 배열에 중위 순회 순서를 입력받습니다.
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    // 중위 순회를 진행하여 각 트리의 위치에 맞는 번호를 채워 넣습니다.
    InOrder(1);

    // 트리의 구조에 맞게 출력을 진행합니다.
    for(int i = 1; i <= k; i++) {
        for(int j = (1 << (i - 1)); j <= (1 << i) - 1; j++) {
            cout << tree_num[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/