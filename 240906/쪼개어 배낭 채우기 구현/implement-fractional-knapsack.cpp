#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<pair<int,int> > v;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    float vpw_a = (float)a.second/a.first; //Value per weight 
    float vpw_b = (float)b.second/b.first;
    return vpw_a > vpw_b; // 무게당 가치가 높은 것이 먼저
}

int main() {
    cin >> n >> m;
    v.resize(n);
    for(int i=0; i<n; ++i){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    float answer=0;
    for(int i=0; i<n; ++i){
        float weight=v[i].first;
        float value = v[i].second;
        if(m-weight>=0){
            m-=weight;
            answer+=value;
        }
        else{
            answer += value/weight*m;
            m=0;
        }
    }

    cout << fixed; // 소수점 고정
    cout.precision(3); // 소수점 3자리 출력
    cout << answer << '\n';
    return 0;
}