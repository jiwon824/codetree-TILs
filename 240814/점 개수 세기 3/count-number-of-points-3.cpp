#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    // 중복되는 점은 주어지지 않음->set이용
    set<int> points;
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        points.insert(num);
    }

    unordered_map<int, int> mapper;
    int cnt=1;
    for(auto it=points.begin(); it!=points.end(); ++it){
        mapper[*it]=cnt;
        cnt++;
    }

    // q개의 줄에 걸친 구간 정보
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << mapper[b]-mapper[a]+1 << '\n';
    }
    
    return 0;
}