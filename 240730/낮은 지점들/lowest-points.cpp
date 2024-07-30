#include <iostream>
#include <unordered_map> 
using namespace std;

int main() {
    int n;
    cin >> n;

    // 가장 작은 y값을 저장
    unordered_map<int, int> um;
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        if(um.find(x)==um.end() || um[x]>y) um[x]=y;
    }

    // 남아있는 y값 합 출력
    long long answer=0;
    for(auto it=um.begin(); it!=um.end(); ++it){
        answer+=it->second;
    }
    cout << answer <<'\n';
    return 0;
}