#include <iostream>
using namespace std;

const int MAX_N = 11;

int n, k;
int coins[MAX_N];

int main() {
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> coins[i];
    }
    
    // 주어진 동전들이 전부 배수관계에 놓여있기 때문에 큰 동전이 사용이 가능하다면,
    // 작은 동전을 사용하는 것보다 항상 좋은 선택이 된다.
    int answer=0;
    for(int i=n-1; i>=0; --i){
        if(coins[i]>k) continue;
        int numOfCoin = k/coins[i];
        k -= numOfCoin*coins[i];
        answer+=numOfCoin;
    }
    cout << answer << '\n';
    return 0;
}