#include <iostream>
#include <vector>
#include <unordered_set>
#include <tuple>
#include <algorithm>

using namespace std;

int n;
vector<tuple<int,int,int> > points;

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        int x1, x2;
        cin >> x1 >> x2;
        points.push_back({x1, 1, i});
        points.push_back({x2, -1, i});
    }
    sort(points.begin(), points.end());

    // 현재 남아있는 선분을 저장
    unordered_set<int> segs;

    int answer=0;
    int startSeg = get<0>(points[0]);
    for(int i=0; i<2*n; ++i){
        int x, flag, idx;
        tie(x, flag, idx) = points[i];

        if(flag==1){
            segs.insert(idx);
        }
        else {
            segs.erase(idx);
            if((int)segs.size()==0) {
                int len = x-startSeg;
                answer+=len;
                startSeg = get<0>(points[i+1]);
            }
        }

    }
    
    cout << answer << '\n';
    return 0;
}