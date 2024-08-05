#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> s;
    vector<int> vec(n);
    vec.push_back(0); // 처음 수직선 상에 x = 0 위치에만 점이 하나 

    // n번에 걸쳐 해당 숫자의 위치에 점을 추가한 이후 가장 가까운 두 점 사이의 거리를 한 줄에 하나씩 출력
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        for(auto e:vec){
            int dist = abs(e-num);
            s.insert(dist);
        }
        vec.push_back(num);
        cout << *s.begin() << '\n';
    }

    return 0;
}