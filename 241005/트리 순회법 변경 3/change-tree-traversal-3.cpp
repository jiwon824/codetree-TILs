#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> inorder;
vector<int> postorder;

//3
// 1 2 3 // 중위(왼 중 오) 
// 1 3 2 // 후위(왼 오 중)

vector<int> FindPreorder(int inorderStart, int inorderEnd, int postorderStart, int postorderEnd){
    // 종료 조건
    if(inorderStart>inorderEnd || postorderStart>postorderEnd){
        return vector<int>();
    }

    int root_val= postorder[postorderEnd];
    // root가 중위 순회에서 어디에 있는지
    int root_idx=0;
    for(int i=0; i<n; ++i){
        if(inorder[i]==root_val){
            root_idx=i;
            break;
        }
    }
    
    int left_size=root_idx-inorderStart;
    vector<int> leftSubtree=FindPreorder(inorderStart, root_idx-1, postorderStart, postorderStart+left_size-1);
    vector<int> rightSubtree=FindPreorder(root_idx+1, inorderEnd, postorderStart+left_size, postorderEnd-1);

    vector<int> preorder; // 중 왼 오
    preorder.push_back(root_val);
    preorder.insert(preorder.end(), leftSubtree.begin(), leftSubtree.end());
    preorder.insert(preorder.end(), rightSubtree.begin(), rightSubtree.end());

    return preorder;
}

int main() {
    cin >> n;
    inorder.resize(n), postorder.resize(n);
    for(int i=0; i<n; ++i){
        cin >> inorder[i];
    }
    for(int i=0; i<n; ++i){
        cin >> postorder[i];
    }

    vector<int> preorder=FindPreorder(0, n-1, 0, n-1);

    for(int i=0; i<n; ++i){
        cout << preorder[i] << " ";
    }
    return 0;
}