#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<pair<int,int> > v;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    double vpw_a = (double)a.second/a.first; //Value per weight 
    double vpw_b = (double)b.second/b.first;
    return vpw_a > vpw_b; // 무게당 가치가 높은 것이 먼저
}

int main() {
    cin >> n >> m;
    v.resize(n);
    for(int i=0; i<n; ++i){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    double answer=0;
    for(int i=0; i<n; ++i){
        if(m==0) break;
        double weight= v[i].first;
        double value = v[i].second;
        if(m>=weight){
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