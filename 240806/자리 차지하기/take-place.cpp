#include <iostream>
#include <set>
#include <vector>

using namespace std;

// return: Add 성공 여부
bool Add(set<int> &s, int num){
    // num이하의 수가 없다면 s에 num삽입
    if(*s.lower_bound(num)!=num) {
        s.insert(num);
        return true;
    }
    if(*s.lower_bound(num)==num) {
        while(*s.lower_bound(num)==num){
            num-=1;
        }

        if(num>0) {
            s.insert(num);
            return true;
        }
        else return false;
    }

    return false;
} 

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> info(n);
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        info[i]=num;
    }

    // solution
    // 1번 사람부터 순서대로 해당 규칙에 맞춰 앉기 시작하며, 최초로 앉지 못하는 사람이 생기면 종료
    set<int> s;
    for(size_t i=0; i<info.size(); ++i){
        int num = info[i];
        bool isSuccess = Add(s, num);
        if(!isSuccess) break;
    }
    
    cout << s.size() << '\n';

    return 0;
}