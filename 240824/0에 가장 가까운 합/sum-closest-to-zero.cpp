#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100001;

int n;
int num[MAX_N];

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }

    sort(num, num+n);

    // answer=min(answer, abs(a+b))
    int r=n-1, answer=2e9;
    for(int l=0; l<n; ++l){
        while(r-1>=l && abs(num[l]+num[r])>answer){
            r--;
        }

        if(r <= l) break;
        answer = min(answer, abs(num[l]+num[r]));
    }
    cout << answer << '\n';
    return 0;
}