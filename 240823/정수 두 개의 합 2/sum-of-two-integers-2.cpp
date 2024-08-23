#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100001;

int n, k;
int num[MAX_N];

int main() {
    // input
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }
    
    sort(num, num+n);

    int r=n-1, answer=0;
    for(int l=0; l<r; ++l){
        while(r>0 && num[l]+num[r]>k){
            r--;
        }
        
        answer+=(r-l);
    }
    cout << answer << '\n';
    return 0;
}