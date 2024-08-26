#include <iostream>
using namespace std;

const int MAX_N = 1000001;
int n, k;
int num[MAX_N];
int num_cnt[3];

int main() {
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }
    
    int r=0, answer=2e9;
    for(int l=0; l<n; ++l){
        while(r<n && num_cnt[1]<k){
            num_cnt[num[r]]++;
            r++;
        }
        if(num_cnt[1]>=k) answer=min(answer, r-l);
        num_cnt[num[l]]--;
    }
    answer = (answer==2e9) ? -1 : answer;
    cout << answer << '\n';
    return 0;
}