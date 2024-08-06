#include <iostream>
#include <set>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> s;
    int answer = INT_MAX;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        // 현재 숫자에서 차이가 m 이상인 최소 숫자를 찾기
        auto it = s.lower_bound(num-m+1);
        if (it != s.begin()) answer = min(answer, num-*prev(it));

        it = s.upper_bound(num+m-1);
        if(it != s.end()) answer = min(answer, *it-num);

        // 현재 숫자를 set에 추가
        s.insert(num);
    }

    // 만약 answer가 갱신되지 않았다면 -1 출력
    if (answer == INT_MAX) cout << -1 << '\n';
    else cout << answer << '\n';

    return 0;
}