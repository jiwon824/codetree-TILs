#include <iostream>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    // testcase만큼 반복
    while(t--){
        int k; // 연산의 개수
        cin >> k;

        // 삽입되는 값에 중복되는 숫자는 주어지지 않습니다.
        set<int> s;
        for(int i=0; i<k; ++i){
            char command;
            int num;
            cin >> command >> num;
            if(command=='I') s.insert(num);
            else{
                // command=='D'
                if(s.empty()) continue;

                if(num==1) s.erase(*s.rbegin());
                else s.erase(*s.begin());
            }
        }

        // 모든 연산을 처리한 후 큐에 남아 있는 값 중 최댓값과 최솟값을 공백을 두고 출력
        // 큐가 비어있다면 EMPTY를 출력
        if(s.empty()) cout << "EMPTY\n";
        else cout << *s.rbegin() << " " << *s.begin() << '\n';
    }
    return 0;
}