#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_set>
#include <algorithm>

using namespace std;

// x좌표, 1/-1, 선분번호
// +1: 시작점, -1: 끝점
vector<tuple<int,int,int> > v;

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        v.push_back({a, 1, i});
        v.push_back({b, -1, i});
    }
    
    sort(v.begin(), v.end());

    // 현재 남아있는 선분을 저장
    unordered_set<int> segs;
    int answer=0;
    for(int i=0; i<2*n; ++i){
        int x, flag, idx;
        tie(x, flag, idx) = v[i];

        if(flag==1){
            // 시작점
            if((int)segs.size()==0) answer++;
            segs.insert(idx);
        }
        else segs.erase(idx);

    }
    
    cout << answer << '\n';

    return 0;
}