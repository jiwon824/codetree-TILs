#include <iostream>

using namespace std;

const int MAX_N = 100001;
const int MAX_M = 100001;

int n, m;
int a[MAX_N];
int b[MAX_M];

// B가 A의 부분수열인지 판단하는 프로그램
bool IsSubsequence(){
    int ap=0;
    int bp=0;
    for(bp=0; bp<m; ++bp){
        while(ap<n && a[ap]!=b[bp]) ap++;

        if(ap==n) return false;
        else ap++;
    }
    return true;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    for(int i=0; i<m; ++i){
        cin >> b[i];
    }
    
    if(IsSubsequence()) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}