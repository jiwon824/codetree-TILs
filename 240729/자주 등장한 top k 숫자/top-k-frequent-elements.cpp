#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int arr[100001];
unordered_map<int, int> um;

bool cmp(pair<int, int> &v1, pair<int, int> &v2){
    if(v1.second==v2.second)return v1.first > v2.first;
    return v1.second > v2.second;
}
int main() {
    // input
    cin >> n >> k;
    // unordered_map[숫자]=등장횟수
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        um[num]++;
    }

    // solution
    // 등장횟수 순으로 정렬하기 위해 vector에 넣어주기
    vector<pair<int,int> > v(n);
    for(auto it=um.begin(); it!=um.end(); ++it){
        int key=it->first, value=it->second;
        v.push_back({key, value});
    }
    sort(v.begin(), v.end(), cmp);

    // output: top k까지 출력
    for(int i=0; i<k; ++i){
        cout << v[i].first << " ";
    }
    return 0;
}