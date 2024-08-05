#include <iostream>
#include <set>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> s;
    s.insert(0);

    int minDist=INT_MAX;
    // n번에 걸쳐 해당 숫자의 위치에 점을 추가한 이후 가장 가까운 두 점 사이의 거리를 한 줄에 하나씩 출력
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        s.insert(num);

        // num의 위치와 num이전의 위치, num 다음 위치를 구한다.
        auto it = s.find(num);
        auto prev_it = (it==s.begin()) ? s.end() : prev(it);
        auto next_it = (it==s.end()) ? s.end() : next(it);
        
        if(prev_it!=s.end()) minDist = min(minDist, num-*prev_it);
        if(next_it!=s.end()) minDist = min(minDist, *next_it-num);


        cout << minDist << '\n';
    }

    return 0;
}