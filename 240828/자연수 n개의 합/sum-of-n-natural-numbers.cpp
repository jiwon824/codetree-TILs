#include <iostream>
using namespace std;

const int MAX_S = 2e9;
long long s;

int main() {
    // 1부터 n까지의 자연수의 합이 s이하인 경우 중 가능한 n의 최댓값
    cin >> s;

    long long l=1, r=MAX_S, max_num=0;
    while(l <= r){
        long long mid = (l+r)/2;
        // 1부터 n까지 합 = n(a+l)/2
        if(mid*(1+mid)/2 > s){
            r=mid-1;
        }
        else {
            l= mid+1;
            max_num = max(max_num, mid);
        }
    }
    cout << max_num << '\n';
    return 0;
}