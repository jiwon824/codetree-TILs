#include <iostream>
using namespace std;

long long m; // 1 ≤ m ≤ pow(10, 18)
long long a, b; // 1 ≤ a ≤ b ≤ m


int Search(int target){
    //cout << "Search: " << target << '\n';
    int turn=0;
    long long l=1, r=m;
    while(l<=r){
        long long mid = (l+r)/2;
        if(mid<target) l=mid+1;
        else r=mid-1;
        turn++;
        if(mid==target) break;
        //cout << mid << '\n';
    }
    //cout << "turn: "<< turn << '\n';
    return turn;
}

int main() {
    cin >> m >> a >> b;
    // 컴퓨터가 처음 a이상 b이하인 수 만을 선택
    int minAns = 2e9, maxAns=0;
    for(int i=a; i<=b; ++i){
        // 컴퓨터가 고른 수가 i라고 할 때 최소 턴과 최대 턴수
        int numOfTurn=Search(i);
        minAns = min(minAns, numOfTurn);
        maxAns = max(maxAns, numOfTurn);
    }
    cout << minAns << " " << maxAns << '\n';
    return 0;
}