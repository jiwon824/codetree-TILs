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