#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int> > reservations;

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        int s, e;
        cin >> s >> e;
        // 한 사람이 나가는 날과 다른 사람이 들어오는 날이 일치하는 경우 두 사람은 같은 방에 머무를 수 없다
        reservations.push_back({s-1, 1}); // 일부러 겹치게 해주기
        reservations.push_back({e, -1});
    }
    
    sort(reservations.begin(), reservations.end());

    int sum_val=0, answer=0;
    for(int i=0; i<2*n; ++i){
        sum_val+=reservations[i].second;
        answer= max(answer, sum_val);
    }
    cout << answer << '\n';
    return 0;
}