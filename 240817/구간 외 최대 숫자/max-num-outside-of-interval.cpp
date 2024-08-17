#include <iostream>
#define MAX_N 100000
using namespace std;

int num[MAX_N];
int leftMax[MAX_N];
int rightMax[MAX_N];

int main() {
    int n, q;
    cin >> n >> q;
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }

    // fill left
    leftMax[0]=num[0];
    for(int i=1; i<n; ++i){
        leftMax[i]=max(leftMax[i-1], num[i]);
    }

    // fill right
    rightMax[n-1]=num[n-1];
    for(int i=n-2; i>=0; --i){
        rightMax[i]=max(rightMax[i+1], num[i]);
    }

    // q개의 질의
    while(q--){
        int a, b;
        cin >> a >> b;
        a--, b--; // 0-based
        cout << max(leftMax[a-1], rightMax[b+1]) <<'\n';
    }

    return 0;
}