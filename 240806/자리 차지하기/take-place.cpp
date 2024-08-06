#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> info(n);
    for(int i=0; i<n; ++i){
        cin >> info[i];
    }

    // solution
    // [초기화] m개의 비어있는 의자
    set<int> s;
    for(int i=1; i<=m; ++i){
        s.insert(i);
    }

    // 1번 사람부터 순서대로 해당 규칙에 맞춰 앉기 시작하며, 최초로 앉지 못하는 사람이 생기면 종료
    for(size_t i=0; i<info.size(); ++i){
        int num = info[i];
        
        auto it = s.upper_bound(num);

        if(it==s.begin()) break;
        s.erase(prev(it));
    }
    
    // 최대로 앉힐 수 있는 사람의 수
    cout << m-s.size() << '\n';
    return 0;
}