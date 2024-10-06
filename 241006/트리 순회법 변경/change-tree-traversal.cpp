#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> preorder;

vector<int> FindPostorder(int preStart, int preEnd){
    // 유효하지 않은 범위일 경우
    if(preStart>preEnd){
        return vector<int>();
    }
    // 단일 노드
    if (preStart == preEnd) {
        return vector<int>{preorder[preStart]};
    }

    // 오른쪽 서브트리의 루트 인덱스 찾기
    int right_root_idx=preStart+1;
    for(int i=preStart+1; i<=preEnd; ++i){
        if(preorder[i]>preorder[preStart]){
            right_root_idx=i;
            break;
        }
    }

    //cout <<"["<<preStart<< " " << preEnd <<"]\n";
    //cout <<"leftSubtree: {" << preStart+1 << " " << right_root_idx-1<< "}\n";
    //cout <<"rightSubtree: {" << right_root_idx << " " << preEnd<< "}\n";

    vector<int> leftSubtree=FindPostorder(preStart+1, right_root_idx-1);
    vector<int> rightSubtree=FindPostorder(right_root_idx, preEnd);

    // postorder
    vector<int> postorder;
    postorder.insert(postorder.end(), leftSubtree.begin(), leftSubtree.end());
    postorder.insert(postorder.end(), rightSubtree.begin(), rightSubtree.end());
    postorder.push_back(preorder[preStart]);

    return postorder;
}

int main() {
    // input
    cin >>n;
    preorder.resize(n);
    for(int i=0; i<n; ++i){
        cin >> preorder[i];
    }

    // solution
    vector<int> postorder = FindPostorder(0, n-1);

    // output
    for(int i=0; i<n; ++i){
        cout << postorder[i] << '\n';
    }
    return 0;
}