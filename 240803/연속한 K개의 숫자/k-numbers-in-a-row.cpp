#include <iostream>
#include <vector>

using namespace std;

int main() {
    // input
    int n, k, b;
    cin >> n >> k >> b;
    vector<int> is_missing(n+1, 0);
    for(int i=0; i<b; ++i){
        int num;
        cin >> num;
        is_missing[num]=1;
    }

    // solution
    int curr =0;
    for(int i=1; i<=k; ++i){
        curr+=is_missing[i];
    }
    int answer=curr;
    for (int i=2; i<=n-k+1; ++i) {
        curr-=is_missing[i-1];
        curr+=is_missing[i+k-1];
        answer = min(answer, curr);
    }

    // output
    cout << answer << '\n';
    return 0;
}