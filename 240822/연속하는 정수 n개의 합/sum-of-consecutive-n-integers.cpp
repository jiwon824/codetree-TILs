#include <iostream>
using namespace std;

const int MAX_N = 100001;

int n, m;
int num[MAX_N];

int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }

    int answer=0;
    int r=0, sum_val=0;
    for(int l=0; l<n; ++l){
        while(r<n && sum_val+num[r]<=m){
            sum_val+=num[r];
            r++;
        }
        
        if(sum_val==m) answer++;
        sum_val-=num[l];
    }
    cout << answer << '\n';
    return 0;
}