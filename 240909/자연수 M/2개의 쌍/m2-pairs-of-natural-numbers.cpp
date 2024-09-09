#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int> > v;

bool cmp(pair<int, int> &a, pair<int,int> &b){
    return a.second<b.second;
}

int main() {
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; ++i){
        cin >> v[i].first >> v[i].second; // second가 first개 있음
    }
    
    sort(v.begin(), v.end(), cmp);

    int left=0, right=n-1, answer=0;
    while(left<=right){
        if(v[left].first==0) left++;
        if(v[right].first==0) right--;
        
        int min_num= min(v[left].first, v[right].first);
        
        /*
        예제처럼 같은 수가 마지막으로 남을 경우를 대비
        1 8
        2 5
        1 2
        */
        if(left==right) min_num/=2;
        
        answer=max(answer, v[left].second+v[right].second);
        v[left].first-=min_num;
        v[right].first-=min_num;
    }
    cout << answer << '\n';
    return 0;
}