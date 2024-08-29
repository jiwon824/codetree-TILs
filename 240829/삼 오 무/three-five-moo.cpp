#include <iostream>
using namespace std;

int n;

long long NumOfNumber(long long n){
    // n -3의 배수의 개수 -5의 배수의 개수 +15의 배수 개수
    return n-(n/3)-(n/5)+(n/15);
}

int main() {
    cin >> n;

    long long left=0, right=2000000000, answer=2000000000;
    while(left<=right){
        long long mid = (left+right)/2;
        if(NumOfNumber(mid)>=n){
            right = mid-1;
            answer = min(answer, mid);
        }
        else{
            left = mid+1;
        }
    }
    cout << answer << '\n';
    return 0;
}