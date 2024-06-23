#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n, answer=INT_MAX;
int numOfJump[11];
vector<int> jump;

void Simulate(int idx, int movement){
    // 종료 조건
    if(idx==n-1 || movement==0){
        if(idx==n-1) answer = min(answer, static_cast<int>(jump.size()));
        return;
    }

    // 재귀 호출
    for(int i=1; i<=movement; i++){
        jump.push_back(idx+i);
        Simulate(idx+i, numOfJump[idx+i]);
        jump.pop_back();
    }
}

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> numOfJump[i];
    }

    Simulate(0, numOfJump[0]);

    // output
    if(answer==INT_MAX) cout << "-1\n";
    else cout << answer << '\n';
    return 0;
}