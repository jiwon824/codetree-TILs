#include <iostream>
using namespace std;

const int MAX_N = 100001;

int n, s;
int num[MAX_N];

int main() {
    // input
    cin >> n >> s;
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }
    
    int r=0, answer=2e9;
    int sum_val=0;
    for(int l=0; l<n; ++l){
        while(r+1<n && sum_val<s){
            sum_val+=num[r];
            r++;
        }
        if(sum_val>=s) answer = min(answer, r-l);
        sum_val-=num[l];
    }

    answer = (answer==2e9)? -1:answer;
    cout << answer << '\n';
    return 0;
}