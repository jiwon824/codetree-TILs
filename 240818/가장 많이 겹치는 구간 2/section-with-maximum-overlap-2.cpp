#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int> > points;

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        int x1, x2;
        cin >> x1 >> x2;
        points.push_back({x1, 1});
        points.push_back({x2, -1});
    }
    sort(points.begin(), points.end());

    int sum_val=0, answer=0;
    for(int i=0; i < 2*n; ++i) {
        int x=points[i].first, v=points[i].second; // x는 좌표, v는 가중치

        sum_val += v;
        answer=max(answer, sum_val);
    }
    cout << answer << '\n';
    return 0;
}