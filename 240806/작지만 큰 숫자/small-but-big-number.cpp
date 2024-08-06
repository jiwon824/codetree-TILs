#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    set<int> s;
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        s.insert(num);
    }

    // m개의 질의에 대해 각 질의마다 해당 숫자보다 같거나 작은 숫자들 중 최댓값을 한 줄에 하나씩 출력
    // 존재: 해당 숫자를 제거 후 다음 질의, 존재x: -1을 출력하고 다음 질의 진행
    for(int i=0; i<m; ++i){
        int num;
        cin >> num;
        if(s.lower_bound(num)==s.begin()) cout << "-1\n";
        else{
            auto it = s.lower_bound(num);
            int delNum = *prev(it);
            if(*it==num) delNum = *it;
            
            cout << delNum << '\n';
            s.erase(delNum);
        }
    }
    return 0;
}