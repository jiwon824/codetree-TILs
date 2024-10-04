#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> preorder;
vector<int> inorder;

vector<int> FindPostorder(int preorderStart, int preorderEnd, int inorderStart, int inorderEnd){
    // 범위를 벗어나는 경우
    if (preorderStart > preorderEnd || inorderStart > inorderEnd) {
        return vector<int>();
    }

    // 1. 전위 순회의 첫 번째 노드는 루트
    // 2. 중위 순회에서 루트노드를 기준으로 왼쪽 노드들은 왼쪽 서브트리
    //                            오른쪽 노드들은 오른쪽 서브트리
    // 왼쪽 트리를 후위 순회한 결과, 오른쪽 트리를 후위 순회한 결과, 루트 노드를 재귀적으로 실행
    
    // 1. 전위 순회의 첫 번째 노드는 루트
    int root_val=preorder[preorderStart];
    int root_idx =0;
    for(int i=inorderStart; i<=inorderEnd; ++i){
        if(inorder[i]==root_val) {
            root_idx=i;
            break;
        }
    }

    // 재귀적으로 sub트리 구하기
    int left_size=root_idx-inorderStart;
    vector<int> leftSubtree=FindPostorder(preorderStart+1, preorderStart+left_size, inorderStart, root_idx-1 );
    vector<int> rightSubtree=FindPostorder(preorderStart+left_size+1, preorderEnd, root_idx+1, inorderEnd);

    // subtree 합치기
    vector<int> postorder;
    postorder.insert(postorder.end(), leftSubtree.begin(), leftSubtree.end());
    postorder.insert(postorder.end(), rightSubtree.begin(), rightSubtree.end());
    postorder.push_back(root_val);

    return postorder;
}

int main() {
    // input
    cin >> n;
    preorder.resize(n), inorder.resize(n);
    for(int i=0; i<n; ++i){
        cin >> preorder[i];
    }
    for(int i=0; i<n; ++i){
        cin >> inorder[i];
    }

    // solution
    vector<int> postorder = FindPostorder(0, n-1, 0, n-1);
    // output
    for(int i=0; i<n; ++i){
        cout << postorder[i] << " ";
    }
    return 0;
}