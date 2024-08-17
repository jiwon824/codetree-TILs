#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int,int> > v;

    int x=0;
    for(int i=0; i<n; ++i){
        int len;
        char dir;
        cin >> len >> dir;
        if(dir=='L'){
            v.push_back({x - len, 1});  // 시작점
            v.push_back({x, -1});       // 끝점
            x-=len;
        }
        else{
            v.push_back({x, 1});
            v.push_back({x+len, -1});
            x+=len;
        }
    }

    sort(v.begin(), v.end());

    // 선분이 k개 이상 겹치는 곳의 길이 합
    long long answer = 0;
    int count = 0;
    int prev = v[0].first;
    
    for(auto e : v) {
        if(count >= k) {
            answer += e.first - prev;
        }
        count += e.second;
        prev = e.first;
    }
    
    cout << answer << endl;
    return 0;
}