#include <iostream>
using namespace std;

const int MAX_N = 27;

int n;
char arr[MAX_N][3];

// node, left, right
void Preorder(int idx){
    char node=arr[idx][0], left=arr[idx][1], right=arr[idx][2];

    // node
    cout << node;
    // left
    for(int i=0; i<n; ++i){
        if(left=='.') break;
        if(arr[i][0]==left) Preorder(i);
    }
    // right
    for(int i=0; i<n; ++i){
        if(right=='.') break;
        if(arr[i][0]==right) Preorder(i);
    }
}
// left, node, right
void Inorder(int idx){
    char node=arr[idx][0], left=arr[idx][1], right=arr[idx][2];

    // left
    for(int i=0; i<n; ++i){
        if(left=='.') break;
        if(arr[i][0]==left) Inorder(i);
    }
    // node
    cout << node;
    // right
    for(int i=0; i<n; ++i){
        if(right=='.') break;
        if(arr[i][0]==right) Inorder(i);
    }
}

// left, right, node
void Postorder(int idx){
    char node=arr[idx][0], left=arr[idx][1], right=arr[idx][2];

    // left
    for(int i=0; i<n; ++i){
        if(left=='.') break;
        if(arr[i][0]==left) Postorder(i);
    }
    // right
    for(int i=0; i<n; ++i){
        if(right=='.') break;
        if(arr[i][0]==right) Postorder(i);
    }
    // node
    cout << node;
}

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    Preorder(0);
    cout << '\n';
    Inorder(0);
    cout << '\n';
    Postorder(0);
    cout << '\n';
    return 0;
}