#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    // 중복되는 점은 주어지지 않습니다.
    set<int> points;
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        points.insert(num);
    }

    unordered_map<int,int> mapper;
    int cnt=1;
    for(auto it=points.begin(); it!=points.end(); ++it){
        mapper[*it]=cnt;
        cnt++;
    }

    // q개의 질의에 대해 각 구간 내에 놓여있는 점의 개수
    while(q--){
        int a, b;
        cin >> a >> b;
        
        if(a>b){
            cout << 0 <<'\n';
            continue;
        }

        int start = *points.lower_bound(a);
        int end = *prev(points.upper_bound(b));

        cout << mapper[end]-mapper[start]+1 << '\n';
    }

    return 0;
}