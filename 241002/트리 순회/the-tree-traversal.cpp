#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 27;

int n;
char arr[MAX_N][3]; // {node, left, right}
vector<char> tree;

// Creating a tree using arr
void MakeTree(){
    // 추가된 값은 '\0'값으로 초기화된다.
    tree.resize(pow(2, n+1));
    tree[1]=arr[0][0], tree[2]=arr[0][1], tree[3]=arr[0][2];

    for(int i=1; i<n; ++i){
        char node=arr[i][0], left=arr[i][1], right=arr[i][2];
        for(int j=0; j<(int)tree.size(); ++j){
            // 노드를 찾으면 left, right를 정해진 인덱스에 넣고 
            if(tree[j]==node){
                tree[j*2]=left;
                tree[j*2+1]=right;
                break;
            }
        }
    }
}

// node left right
void Preorder(int idx){
    if(tree[idx]=='\0' || tree[idx]=='.') return;

    cout << tree[idx];
    Preorder(idx*2);
    Preorder(idx*2+1);
}

// left node right
void Inorder(int idx){
    if(tree[idx]=='\0' || tree[idx]=='.') return;

    Inorder(idx*2);
    cout << tree[idx];
    Inorder(idx*2+1);
}

// left right node
void Postorder(int idx){
    if(tree[idx]=='\0' || tree[idx]=='.') return;
    
    Postorder(idx*2);
    Postorder(idx*2+1);
    cout << tree[idx];
}

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    MakeTree();

    // output
    Preorder(1);
    cout << '\n';
    Inorder(1);
    cout << '\n';
    Postorder(1);
    cout << '\n';
    return 0;
}