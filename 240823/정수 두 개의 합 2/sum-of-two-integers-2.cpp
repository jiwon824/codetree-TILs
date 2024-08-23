#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100001;

int n, k;
vector<int> num;

int main() {
    // input
    cin >> n >> k;
    num.resize(n);
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }
    
    // 정렬
    sort(num.begin(), num.end());

    // 가능한 최대 r idx 구하기 num[r]<=k인 최초 idx
    int lastRIdx=n, r=n;
    for(int i=n-1; i>0; --i){
        if(num[i]<=k){
            lastRIdx=i;
            break;
        }
    }

    int answer=0;
    for(int l=0; num[l]<k; ++l){
        for(int r=lastRIdx; r>l; --r){
            if(num[l]+num[r]<=k){
                answer++;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}